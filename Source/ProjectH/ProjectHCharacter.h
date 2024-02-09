// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InteractableActor.h"
#include "PlayerHUD.h"
#include "RangeWeapon.h"
#include "ProjectHCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;

UCLASS(config=Game)
class AProjectHCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

protected:
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetTRightHandWeaponSocket")
	FTransform TRightHandWeaponSocket;
	
public:
	AProjectHCharacter();

protected:
	virtual void BeginPlay();

public:
		
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

	UFUNCTION(BlueprintCallable)
	void CallObjectInteraction();
	
protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	
	//Getters
	UFUNCTION(BlueprintGetter)
	ARangeWeapon* GetPlayerRangeWeapon() const;

	UFUNCTION(BlueprintGetter)
	FTransform GetTRightHandWeaponSocket();

	UFUNCTION(BlueprintGetter)
	AInteractableActor* GetInteractableObjectInRange() const;

	UFUNCTION(BlueprintGetter)
	bool GetbIsWeaponOut();

	UFUNCTION(BlueprintGetter)
	bool GetbIsShooting();

	UFUNCTION(BlueprintGetter)
	float GetPlayerHealth();

	UFUNCTION(BlueprintGetter)
	UPlayerHUD* GetPlayerHUD() const;
	
	//Setters
	UFUNCTION(BlueprintSetter)
	void SetPlayerRangeWeapon(ARangeWeapon* pistol);

	UFUNCTION(BlueprintSetter)
	void SetInteractableObjectInRange(AInteractableActor* interactableActor);

	UFUNCTION(BlueprintSetter)
	void SetbIsWeaponOut(bool isWeaponOut);

	UFUNCTION(BlueprintSetter)
	void SetbIsShooting(bool isShooting);

	UFUNCTION(BlueprintSetter)
	void SetPlayerHealth(float playerHealth);

	UFUNCTION(BlueprintSetter)
	void SetPlayerHud(UPlayerHUD* playerHud);
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetPlayerRangeWeapon", BlueprintSetter="SetPlayerRangeWeapon")
	ARangeWeapon* Pistol;
	
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetInteractableObjectInRange", BlueprintSetter="SetInteractableObjectInRange")
	AInteractableActor* InteractableActor;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetbIsWeaponOut", BlueprintSetter="SetbIsWeaponOut")
	bool bIsWeaponOut;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetbIsShooting", BlueprintSetter="SetbIsShooting")
	bool bIsShootting;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetPlayerHealth", BlueprintSetter="SetPlayerHealth")
	float PlayerHealth;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetPlayerHUD", BlueprintSetter="SetPlayerHud")
	UPlayerHUD* PlayerHUD;
};

