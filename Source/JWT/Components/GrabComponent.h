// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GrabComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGrabDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), meta = (IsBlueprintBase = "true") )
class JWT_API UGrabComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabComponent();

	UFUNCTION(BlueprintPure, Category = "Grab")
	bool IsHeld();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Grab")
	FGrabDelegate OnGrabbed;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Grab")
	FGrabDelegate OnDropped;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grab")
	bool bIsHeld;
};
