// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlendSpaceAnalysis.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "RangeWeapon.generated.h"

UCLASS()
class PROJECTH_API ARangeWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARangeWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnWeaponUse();

	//Getters
	UFUNCTION(BlueprintGetter)
	UStaticMeshComponent* GetWeaponMesh() const;

	UFUNCTION(BlueprintGetter)
	float GetWeaponDamage() const;

	UFUNCTION(BlueprintGetter)
	int GetCurrentWeaponAmmo() const;
	
	//Setters
	UFUNCTION(BlueprintSetter)
	void SetWeaponMesh(UStaticMeshComponent* weaponMesh);

	UFUNCTION(BlueprintSetter)
	void SetWeaponDamage(float weaponDamage);

	UFUNCTION(BlueprintSetter)
	void SetCurrentWeaponAmmo(int weaponAmmo);

protected:
	const int MaxWeaponAmmo = 7;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetWeaponMesh", BlueprintSetter="SetWeaponMesh");
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(BlueprintGetter="GetWeaponDamage", BlueprintSetter="SetWeaponDamage")
	float WeaponDamage;

	UPROPERTY(BlueprintGetter="GetCurrentWeaponAmmo", BlueprintSetter="SetCurrentWeaponAmmo")
	int CurrentWeaponAmmo;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* RayCastExitPoint;
};
