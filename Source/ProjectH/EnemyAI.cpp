// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetCurrentHealth(100.0f);
	bSetIsWounded(false);
	bSetIsDead(false);
}

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyAI::OnDamageTake(float damageAmount)
{
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, "Damage");
	SetCurrentHealth(GetCurrentHealth() - damageAmount);
	if(GetCurrentHealth() <= 0)
	{
		bSetIsDead(true);
		OnDeath();
	}
	else if(GetCurrentHealth() <= 50)
	{
		bSetIsWounded(true);
	}
}

float AEnemyAI::GetCurrentHealth() const
{
	return CurrentHealth;
}

bool AEnemyAI::bGetIsWounded() const
{
	return bIsWounded;
}

bool AEnemyAI::bGetIsDead() const
{
	return bIsDead;
}

void AEnemyAI::SetCurrentHealth(float health)
{
	CurrentHealth = health;
}

void AEnemyAI::bSetIsWounded(bool isWounded)
{
	bIsWounded = isWounded;
}

void AEnemyAI::bSetIsDead(bool isDead)
{
	bIsDead = isDead;
}

