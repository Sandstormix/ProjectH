// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FWeapons.h"
#include "GameFramework/Actor.h"
#include "LegacyCameraShake.h"
#include "Components/ArrowComponent.h"
#include "RangeWeapon.generated.h"

UCLASS()
class PROJECTH_API ARangeWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARangeWeapon();
	ARangeWeapon(const FString& weaponName, const int &currentAmmo, const int &spareAmmo, const float &damage, const int &maxAmmo, USkeletalMeshComponent* weaponMesh);

	~ARangeWeapon();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ULegacyCameraShake> CameraShake;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnWeaponUse();

	UFUNCTION(BlueprintCallable)
	void AddWeaponAmmo(int ammoToAdd);

	UFUNCTION(BlueprintCallable)
	void Reload();

	//Getters
	UFUNCTION(BlueprintGetter)
	USkeletalMeshComponent* GetWeaponMesh() const;

	UFUNCTION(BlueprintGetter)
	float GetWeaponDamage() const;

	UFUNCTION(BlueprintGetter)
	int GetCurrentWeaponAmmo() const;

	UFUNCTION(BlueprintGetter)
	FWeapons GetWeaponData();
	
	//Setters
	UFUNCTION(BlueprintSetter)
	void SetWeaponMesh(USkeletalMeshComponent* weaponMesh);

	UFUNCTION(BlueprintSetter)
	void SetWeaponDamage(float weaponDamage);

	UFUNCTION(BlueprintSetter)
	void SetCurrentWeaponAmmo(int weaponAmmo);

	UFUNCTION(BlueprintSetter)
	void SetWeaponData(FWeapons weaponData);

protected:
	void Init();
	
	const int MaxWeaponAmmo = 7;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintGetter="GetWeaponMesh", BlueprintSetter="SetWeaponMesh");
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(BlueprintGetter="GetWeaponDamage", BlueprintSetter="SetWeaponDamage")
	float WeaponDamage;

	UPROPERTY(BlueprintGetter="GetCurrentWeaponAmmo", BlueprintSetter="SetCurrentWeaponAmmo")
	int CurrentWeaponAmmo;

	UPROPERTY(EditAnywhere, BlueprintGetter="GetWeaponData", BlueprintSetter="SetWeaponData")
	FWeapons WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UArrowComponent* ArrowComponent;
};
