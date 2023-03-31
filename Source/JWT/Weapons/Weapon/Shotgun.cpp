// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Weapon/Shotgun.h"
#include "Kismet/KismetMathLibrary.h"

AShotgun::AShotgun()
{
	AmmoPerShot = 0;
}

void AShotgun::Fire()
{
	Super::Fire();

	for (auto i = 0; i < ProjectilesCount; ++i)
	{
		auto MuzzleTransform = GetRootComponent()->GetSocketTransform("Muzzle");

		MuzzleShift = UKismetMathLibrary::RotateAngleAxis
		(MuzzleTransform.GetRotation().GetUpVector() * SpredDistance,  (360.0f / ProjectilesCount) * i, MuzzleTransform.GetLocation());

		Super::Fire();
	}

	MuzzleShift = FVector::ZeroVector;

	GetAmmo()->Remove(1);
}
