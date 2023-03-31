// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Weapon/GunAuto.h"

void AGunAuto::Fire()
{
	if (!bFire && GetAmmo()->IsAvailable())
	{
		bFire = true;
		GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &AGunAuto::AutoFire, FireRate, true);
	}
}

void AGunAuto::FireStop()
{
	Super::FireStop();

	bFire = false;
	GetWorld()->GetTimerManager().ClearTimer(AutoFireTimer);
}

void AGunAuto::AutoFire()
{
	Super::Fire();

	if (!GetAmmo()->IsAvailable())
	{
		FireStop();
	}
}
