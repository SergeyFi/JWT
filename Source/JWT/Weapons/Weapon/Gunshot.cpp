// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Weapon/Gunshot.h"

AGunshot::AGunshot()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal mesh");
	RootComponent = Mesh;

	AmmoGrabVolume = CreateDefaultSubobject<UCapsuleComponent>("AmmoGrabVolume");
	AmmoGrabVolume->SetCollisionProfileName("OverlapAll");
	AmmoGrabVolume->SetCapsuleHalfHeight(14.0f);
	AmmoGrabVolume->SetCapsuleRadius(7.0f);
	AmmoGrabVolume->SetupAttachment(GetRootComponent());
}

void AGunshot::Fire()
{
	if (Ammo)
	{
		if (Ammo->IsAvailable())
		{
			Super::Fire();

			Ammo->Remove(AmmoPerShot);
		}
	}
}

AAmmo* AGunshot::GetAmmo()
{
	return Ammo;
}

void AGunshot::BeginPlay()
{
	Super::BeginPlay();

	AmmoGrabVolume->OnComponentBeginOverlap.AddDynamic(this, &AGunshot::OnAmmoGrabVolumeOverlap);
}

void AGunshot::OnAmmoGrabVolumeOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                       UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if (Ammo) return;
	
	auto NewAmmo = Cast<AAmmo>(OtherActor);

	if (NewAmmo && NewAmmo->GetClass() == AmmoClass)
	{
		Ammo = NewAmmo;

		auto AmmoGrabcomponent = Ammo->FindComponentByClass<UGrabComponent>();

		if (AmmoGrabcomponent->IsHeld())
		{
			AmmoGrabcomponent->OnGrabbed.AddDynamic(this, &AGunshot::OnAmmoGrabbed);
			AmmoGrabcomponent->OnDropped.AddDynamic(this, &AGunshot::OnAmmoDropped);
		}
	}
}

void AGunshot::OnAmmoGrabbed()
{
	Ammo = nullptr;
	bAmmoEquiped = false;
}

void AGunshot::OnAmmoDropped()
{
	if (Ammo && !bAmmoEquiped)
	{
		auto AmmoRootPrimitive = Cast<UPrimitiveComponent>(Ammo->GetRootComponent());

		if (AmmoRootPrimitive)
		{
			AmmoRootPrimitive->SetSimulatePhysics(false);
			AmmoRootPrimitive->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Ignore);
			Ammo->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Ammo");

			bAmmoEquiped = true;
		}
	}
}
