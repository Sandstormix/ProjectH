// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

APistol::APistol()
{
	
}

APistol::~APistol()
{
	
}

void APistol::OnWeaponUse()
{
	FVector RayCastStartLocation;
	FRotator RaycastStartRotator;

	RayCastStartLocation = this->GetRayCastExitPoint()->GetRelativeLocation();
	RaycastStartRotator = this->GetRayCastExitPoint()->GetRelativeRotation();

	FVector RayCastEnd = RayCastStartLocation + RaycastStartRotator.Vector() * 1000;

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, RayCastStartLocation, RayCastEnd, ECC_Visibility, CollisionParams);

	if(bHit)
	{
		DrawDebugLine(GetWorld(), RayCastStartLocation, RayCastEnd, FColor::Green, false, 2.0f, 0, 1.0f);
	}
}
