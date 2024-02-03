// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeWeapon.h"

// Sets default values
ARangeWeapon::ARangeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon Mesh"));
	RootComponent = WeaponMesh;
	RayCastExitPoint = CreateDefaultSubobject<USphereComponent>(TEXT("Ray Cast Exit Point"));
	RayCastExitPoint->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARangeWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARangeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARangeWeapon::OnWeaponUse()
{
}

void ARangeWeapon::AddWeaponAmmo(int ammoToAdd)
{
	
}

USkeletalMeshComponent* ARangeWeapon::GetWeaponMesh() const
{
	return WeaponMesh;
}

float ARangeWeapon::GetWeaponDamage() const
{
	return WeaponDamage;
}

int ARangeWeapon::GetCurrentWeaponAmmo() const
{
	return CurrentWeaponAmmo;
}

USphereComponent* ARangeWeapon::GetRayCastExitPoint()
{
	return RayCastExitPoint;
}

FWeapons ARangeWeapon::GetWeaponData()
{
	return WeaponData;
}

void ARangeWeapon::SetWeaponMesh(USkeletalMeshComponent* weaponMesh)
{
	WeaponMesh = weaponMesh;
}

void ARangeWeapon::SetWeaponDamage(float weaponDamage)
{
	WeaponDamage = weaponDamage;
}

void ARangeWeapon::SetCurrentWeaponAmmo(int weaponAmmo)
{
	CurrentWeaponAmmo = weaponAmmo;
}

void ARangeWeapon::SetRayCastExitPoint(USphereComponent* rayCastExitPoint)
{
	RayCastExitPoint = rayCastExitPoint;
}

void ARangeWeapon::SetWeaponData(FWeapons weaponData)
{
	WeaponData = weaponData;
}

