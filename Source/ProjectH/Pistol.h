// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RangeWeapon.h"
#include "Pistol.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTH_API APistol : public ARangeWeapon
{
	GENERATED_BODY()
	
public:
	
	APistol();
	~APistol();
	
	void OnWeaponUse() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void AddAmmo(int ammoToAdd);
};
