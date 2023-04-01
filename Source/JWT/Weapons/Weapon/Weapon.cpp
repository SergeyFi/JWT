// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Weapon/Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AWeapon::Fire()
{
	if (ProjectileClass)
	{
		FRotator Spread;

		if (NeedSpreading)
		{
			Spread.Yaw += FMath::RandRange(-SpreadingAngle, SpreadingAngle);
			Spread.Pitch += FMath::RandRange(-SpreadingAngle, SpreadingAngle);	
		}
		
		auto SpawnLocation = GetRootComponent()->GetSocketLocation("Muzzle");
		SpawnLocation += MuzzleShift;
		
		auto SpawnRotation = GetRootComponent()->GetSocketRotation("Muzzle");
		SpawnRotation += Spread;

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator = GetInstigator();
		
		GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParameters);
	}
}

void AWeapon::FireStop()
{
	
}
