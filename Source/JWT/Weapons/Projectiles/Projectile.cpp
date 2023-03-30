// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Projectiles/Projectile.h"
#include "JWT/Components/HealthComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->InitialSpeed = Speed;

	Sphere = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	RootComponent = Sphere;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnProjectileOverlap);

	ProjectileMovement->OnProjectileStop.AddDynamic(this, &AProjectile::OnProjectileStop);
}

void AProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == GetInstigator())
	{
		return;
	}
	
	if (OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulse(ProjectileMovement->Velocity * ImpulseScale);

		Destroy();
	}

	auto HealthComponent = OtherActor->FindComponentByClass<UHealthComponent>();

	if (HealthComponent)
	{
		HealthComponent->RemoveHealth(Damage);
	}
}

void AProjectile::OnProjectileStop(const FHitResult& ImpactResult)
{
	Destroy();
}
