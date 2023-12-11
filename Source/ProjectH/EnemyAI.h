// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damagable.h"
#include "GameFramework/Character.h"
#include "EnemyAI.generated.h"

UCLASS()
class PROJECTH_API AEnemyAI : public ACharacter, public IDamagable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OnDamageTake(float damageAmount) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();

	//Getters
	UFUNCTION(BlueprintGetter)
	float GetCurrentHealth() const;

	UFUNCTION(BlueprintGetter)
	bool bGetIsWounded() const;

	UFUNCTION(BlueprintGetter)
	bool bGetIsDead() const;
	
	//Setters
	UFUNCTION(BlueprintSetter)
	void SetCurrentHealth(float health);

	UFUNCTION(BlueprintSetter)
	void bSetIsWounded(bool isWounded);

	UFUNCTION(BlueprintSetter)
	void bSetIsDead(bool isDead);
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetCurrentHealth", BlueprintSetter="SetCurrentHealth")
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="bGetIsWounded", BlueprintSetter="bSetIsWounded")
	bool bIsWounded;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="bGetIsDead", BlueprintSetter="bSetIsDead")
	bool bIsDead;
};
