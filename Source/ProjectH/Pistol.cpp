// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

APistol::APistol()
{
	
}

APistol::~APistol()
{
	
}

void APistol::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APistol::OnWeaponUse()
{
	FVector RayCastStartLocation;
	FRotator RaycastStartRotator;

	RayCastStartLocation = this->GetRayCastExitPoint()->GetComponentLocation();
	RaycastStartRotator = this->GetRayCastExitPoint()->GetComponentRotation();

	FVector RayCastEnd = RayCastStartLocation + RaycastStartRotator.Vector() * 1000;

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, RayCastStartLocation, RayCastEnd, ECC_Visibility, CollisionParams);

	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("PEW PEW"));

	DrawDebugLine(GetWorld(), RayCastStartLocation, RayCastEnd, FColor::Green, false, 5.0f, 0, 2.0f);
	
	if(bHit)
	{
		
	}
}

