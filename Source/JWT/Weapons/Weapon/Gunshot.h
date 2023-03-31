// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "JWT/Components/GrabComponent.h"
#include "JWT/Weapons/Ammo/Ammo.h"
#include "JWT/Weapons/Weapon/Weapon.h"
#include "Gunshot.generated.h"

/**
 * 
 */
UCLASS()
class JWT_API AGunshot : public AWeapon
{
	GENERATED_BODY()

public:
	AGunshot();

	virtual void Fire() override;

	UFUNCTION(BlueprintPure, Category = "Weapon")
	AAmmo* GetAmmo();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	USkeletalMeshComponent* AmmoAnchor;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	UCapsuleComponent* AmmoGrabVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<AAmmo> AmmoClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	int32 AmmoPerShot = 1;

private:
	
	UPROPERTY()
	AAmmo* Ammo;

	bool bAmmoEquiped;

	UFUNCTION()
	void OnAmmoGrabVolumeOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnAmmoGrabbed();

	UFUNCTION()
	void OnAmmoDropped();
};
