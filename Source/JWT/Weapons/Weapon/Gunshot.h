// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	USkeletalMeshComponent* Mesh;
};
