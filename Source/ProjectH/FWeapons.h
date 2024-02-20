#pragma once
#include "Engine/DataTable.h"
#include "FWeapons.generated.h"

USTRUCT(BlueprintType)
struct FWeapons : public FTableRowBase
{
	GENERATED_BODY()
	
	FWeapons();
	FWeapons(FString weaponName, int currentAmmo, int spareAmmo, float damage, int maxammo, USkeletalMeshComponent* weaponmesh);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString WeaponName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpareAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int maxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;
};
