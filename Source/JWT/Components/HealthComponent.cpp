// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Components/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
}

void UHealthComponent::RemoveHealth(float Damage)
{
	Health -= Damage;

	if (Health <= 0.0f)
	{
		Health = 0.0f;
		
		OnHealthEnd.Broadcast();
	}
}

float UHealthComponent::GetHealth() const
{
	return Health;
}

float UHealthComponent::GetHealthMax() const
{
	return HealthMax;
}
