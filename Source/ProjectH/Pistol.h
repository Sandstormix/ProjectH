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

	APistol();
	~APistol();

public:
	void OnWeaponUse() override;
	
};
