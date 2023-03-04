// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JWT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void RemoveHealth(float Damage);

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FHealthDelegate OnHealthEnd;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (ClampMin=0.0f))
	float Health = 100.0f;
};
