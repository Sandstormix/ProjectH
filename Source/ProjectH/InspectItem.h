// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ProjectHCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "InspectItem.generated.h"

UCLASS()
class PROJECTH_API AInspectItem : public AInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInspectItem();

	virtual void OnInteract(bool bCanInteract, AProjectHCharacter* playerReference) override;
	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) override;

	UFUNCTION(BlueprintImplementableEvent)
	void ChangeToInspectionCamera();
	
	//Getters
	UFUNCTION(BlueprintGetter)
	UStaticMeshComponent* GetStaticMesh();

	UFUNCTION(BlueprintGetter)
	UCameraComponent* GetCamera();

	UFUNCTION(BlueprintGetter)
	UBoxComponent* GetBoxComponent();

	UFUNCTION(BlueprintGetter)
	ACameraActor* GetCameraActor();

	UFUNCTION(BlueprintGetter)
	AProjectHCharacter* GetCharacterReference();
	
	//Setters
	UFUNCTION(BlueprintSetter)
	void SetStaticMeshComponent(UStaticMeshComponent* staticMesh);

	UFUNCTION(BlueprintSetter)
	void SetCamera(UCameraComponent* cameraComponent);

	UFUNCTION(BlueprintSetter)
	void SetBoxComponent(UBoxComponent* boxComponent);

	UFUNCTION(BlueprintSetter)
	void SetCameraActor(ACameraActor* cameraActor);

	UPROPERTY(VisibleAnywhere)
	float CameraBlendTime;
	UPROPERTY(VisibleAnywhere)
	float CameraBlendExp;

	UPROPERTY(EditAnywhere)
	UTextRenderComponent* ItemDescription;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetStaticMesh", BlueprintSetter="SetStaticMeshComponent")
	UStaticMeshComponent* ActorStaticMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetCamera", BlueprintSetter="SetCamera")
	UCameraComponent* ActorCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetBoxComponent", BlueprintSetter="SetBoxComponent")
	UBoxComponent* ActorBoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetCharacterReference")
	AProjectHCharacter* CharacterReference;

	UPROPERTY(VisibleAnywhere, BlueprintGetter="GetCameraActor", BlueprintSetter="SetCameraActor")
	ACameraActor* CameraActor;
};
