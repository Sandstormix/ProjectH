// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeWeapon.h"

#include "Damagable.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARangeWeapon::ARangeWeapon()
{	
	Init();
}

ARangeWeapon::ARangeWeapon(const FString& weaponName, const int &currentAmmo, const int &spareAmmo, const float &damage, const int &maxAmmo,
	 USkeletalMeshComponent* weaponMesh): WeaponMesh(nullptr), WeaponDamage(0), CurrentWeaponAmmo(0),
		RayCastExitPoint(nullptr), WeaponData(weaponName, currentAmmo, spareAmmo, damage, maxAmmo, weaponMesh)
{
	Init();
}

ARangeWeapon::~ARangeWeapon()
{
	
}

void ARangeWeapon::Init()
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

	WeaponData.CurrentAmmo--;
	UGameplayStatics::PlayWorldCameraShake(GetWorld(), CameraShake, this->GetActorLocation(), 0, 500);
}

void ARangeWeapon::AddWeaponAmmo(int ammoToAdd)
{
	WeaponData.SpareAmmo += ammoToAdd;
}

void ARangeWeapon::Reload()
{
	const int ammoToAdd = WeaponData.maxAmmo - WeaponData.CurrentAmmo;
	if(WeaponData.SpareAmmo - ammoToAdd >= 0 )
	{
		WeaponData.SpareAmmo -= ammoToAdd;
		WeaponData.CurrentAmmo += ammoToAdd;
	}
	else if(WeaponData.SpareAmmo - ammoToAdd < 0)
	{
		WeaponData.CurrentAmmo += WeaponData.SpareAmmo;
		WeaponData.SpareAmmo = 0;
	}
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

