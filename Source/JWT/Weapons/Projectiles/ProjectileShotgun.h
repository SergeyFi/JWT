// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JWT/Weapons/Projectiles/Projectile.h"
#include "ProjectileShotgun.generated.h"

/**
 * 
 */
UCLASS()
class JWT_API AProjectileShotgun : public AProjectile
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	int32 ProjectilesCount = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float SpredDistance = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<AProjectile> ProjectileClass;
};
