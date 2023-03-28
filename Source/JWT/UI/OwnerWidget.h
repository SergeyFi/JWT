// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OwnerWidget.generated.h"

/**
 * 
 */
UCLASS()
class JWT_API UOwnerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Widget")
	AActor* GetActorOwner() const;

	UFUNCTION(BlueprintCallable, Category = "Widget")
	void SetActorOwner(AActor* NewOwner);
	
protected:

	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	AActor* ActorOwner;

	UFUNCTION(BlueprintNativeEvent, Category = "Widget")
	void OnActorOwnerSet(AActor* NewOwner);
};
