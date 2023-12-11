// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

#include "Damagable.h"
#include "EnemyAI.h"

APistol::APistol()
{
	this->WeaponDamage = 10.0f;
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

	FVector RayCastEnd = RayCastStartLocation + RaycastStartRotator.Vector() * 10000;

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, RayCastStartLocation, RayCastEnd, ECC_Pawn, CollisionParams);

	DrawDebugLine(GetWorld(), RayCastStartLocation, RayCastEnd, FColor::Green, false, 5.0f, 0, 2.0f);
	
	if(bHit)
	{
		if(IDamagable* DamagableCharacter = Cast<IDamagable>(HitResult.GetActor()))
		{
			DamagableCharacter->OnDamageTake(this->WeaponDamage);
		}
	}
}

