// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Projectiles/ProjectileShotgun.h"
#include "Kismet/KismetMathLibrary.h"

void AProjectileShotgun::BeginPlay()
{
	Super::BeginPlay();

	if (ProjectileClass)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Instigator = GetInstigator();

		GetWorld()->SpawnActor<AActor>
		(ProjectileClass, GetActorLocation(), GetActorRotation(), SpawnParameters);

		float Shift = FMath::RandRange(0.0, 180.0f);

		for (auto i = 0; i < ProjectilesCount; ++i)
		{
			auto NextProjectileLocation = UKismetMathLibrary::RotateAngleAxis
			(GetActorUpVector() * SpredDistance,  (360.0f / ProjectilesCount) * i + Shift, GetActorLocation());

			GetWorld()->SpawnActor<AActor>
			(ProjectileClass, NextProjectileLocation + GetActorLocation(), GetActorRotation(), SpawnParameters);
		}
	}
}
