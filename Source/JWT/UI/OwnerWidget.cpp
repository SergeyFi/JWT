// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/UI/OwnerWidget.h"

AActor* UOwnerWidget::GetActorOwner() const
{
	return ActorOwner;
}

void UOwnerWidget::SetActorOwner(AActor* NewOwner)
{
	ActorOwner = NewOwner;
}
