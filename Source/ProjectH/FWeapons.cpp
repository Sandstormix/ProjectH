#include "FWeapons.h"

FWeapons::FWeapons(): WeaponName("Default weapon name"), CurrentAmmo(0), SpareAmmo(0), Damage(0), maxAmmo(0), WeaponMesh(nullptr){}

FWeapons::FWeapons(FString weaponName, int currentAmmo, int spareAmmo, float damage, int maxammo,
	USkeletalMeshComponent* weaponmesh): WeaponName(weaponName), CurrentAmmo(currentAmmo), SpareAmmo(spareAmmo), Damage(damage), maxAmmo(maxammo),
	WeaponMesh(weaponmesh){}
