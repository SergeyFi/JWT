// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ammo.generated.h"


UCLASS(Abstract, meta = (IsBlueprintBase = "true"))
class JWT_API AAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmo();

	UFUNCTION(BlueprintPure, Category = "Ammo")
	int32 GetAmmoCurrent() const;

	UFUNCTION(BlueprintPure, Category = "Ammo")
	int32 GetAmmoMax() const;

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	void Remove(const int32 Ammo);

	UFUNCTION(BlueprintPure, Category = "Ammo")
	bool IsAvailable() const;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
	int32 AmmoCurrent;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
	int32 AmmoMax;

};
