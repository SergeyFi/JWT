// Fill out your copyright notice in the Description page of Project Settings.


#include "JWT/Weapons/Weapon/Gunshot.h"

AGunshot::AGunshot()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal mesh");

	RootComponent->SetupAttachment(Mesh);
	
	RootComponent = Mesh;
}
