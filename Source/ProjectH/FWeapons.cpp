#include "FWeapons.h"

FWeapons::FWeapons(): WeaponName("Default weapon name"), CurrentAmmo(0), SpareAmmo(0), Damage(0), MaxAmmo(0), WeaponMesh(nullptr){}

FWeapons::FWeapons(FString weaponName, int currentAmmo, int spareAmmo, float damage, int maxammo,
	USkeletalMeshComponent* weaponmesh): WeaponName(weaponName), CurrentAmmo(currentAmmo), SpareAmmo(spareAmmo), Damage(damage), MaxAmmo(maxammo),
	WeaponMesh(weaponmesh){}
