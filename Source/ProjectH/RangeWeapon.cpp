// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeWeapon.h"

// Sets default values
ARangeWeapon::ARangeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	RootComponent = WeaponMesh;

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

UStaticMeshComponent* ARangeWeapon::GetWeaponMesh()
{
	return WeaponMesh;
}

void ARangeWeapon::SetWeaponMesh(UStaticMeshComponent* weaponMesh)
{
	WeaponMesh = weaponMesh;
}

