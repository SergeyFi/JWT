// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JWT/Weapons/Weapon/Gunshot.h"
#include "GunAuto.generated.h"

/**
 * 
 */
UCLASS()
class JWT_API AGunAuto : public AGunshot
{
	GENERATED_BODY()

public:

	virtual void Fire() override;

	virtual void FireStop() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	float FireRate = 0.5f;

private:

	FTimerHandle AutoFireTimer;

	bool bFire;

	UFUNCTION()
	void AutoFire();
};
