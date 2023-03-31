// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JWT/Weapons/Weapon/Gunshot.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class JWT_API AShotgun : public AGunshot
{
	GENERATED_BODY()

public:
	
	AShotgun();
	
	virtual void Fire() override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Shotgun")
	int32 ProjectilesCount = 5;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon|Shotgun")
	float SpredDistance = 40.0f;
};
