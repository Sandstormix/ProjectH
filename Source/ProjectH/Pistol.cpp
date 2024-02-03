// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

#include "Damagable.h"
#include "EnemyAI.h"

APistol::APistol()
{
	this->WeaponData.Damage = 10;
	this->WeaponData.CurrentAmmo = 7;
	this->WeaponData.WeaponName = "Pistol";
	this->WeaponData.WeaponMesh = this->GetWeaponMesh();
}

APistol::~APistol()
{
	
}

void APistol::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APistol::AddAmmo(int ammoToAdd)
{
	this->WeaponData.CurrentAmmo += ammoToAdd;
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
			DamagableCharacter->OnDamageTake(this->WeaponData.Damage);
		}
	}

	this->WeaponData.CurrentAmmo--;
}

