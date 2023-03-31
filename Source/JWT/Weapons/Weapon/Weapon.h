// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JWT/Weapons/Projectiles/Projectile.h"
#include "Weapon.generated.h"

UCLASS(Abstract, meta = (IsBlueprintBase = "true"))
class JWT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void FireStop();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FVector MuzzleShift;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	bool NeedSpreading;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon", meta = (EditCondition = "NeedSpreading"))
	float SpreadingAngle;
};
