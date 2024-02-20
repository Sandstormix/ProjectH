// Fill out your copyright notice in the Description page of Project Settings.


#include "Pistol.h"

#include "Damagable.h"
#include "EnemyAI.h"

APistol::APistol(): ARangeWeapon("Pistol", 7, 0, 10, 7, this->GetWeaponMesh()){}

APistol::~APistol(){}

void APistol::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

