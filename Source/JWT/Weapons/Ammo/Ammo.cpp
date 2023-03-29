// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Ammo/Ammo.h"

// Sets default values
AAmmo::AAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

int32 AAmmo::GetAmmoCurrent() const
{
	return AmmoCurrent;
}

int32 AAmmo::GetAmmoMax() const
{
	return AmmoMax;
}

void AAmmo::Remove(const int32 Ammo)
{
	AmmoCurrent -= Ammo;

	if (AmmoCurrent < 0)
	{
		AmmoCurrent = 0;
	}
}

bool AAmmo::IsAvailable() const
{
	return AmmoCurrent > 0;
}
