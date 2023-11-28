// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Doors.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTH_API ADoors : public AInteractableActor
{
	GENERATED_BODY()

public:
	ADoors();

	virtual void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex) override;

	virtual void OnInteract(bool bCanInteract) override;

	UPROPERTY(BlueprintReadWrite)
	float DoorOpenAngle;

	UFUNCTION(BlueprintCallable)
	void OpenDoors(float doorAngle);

	UPROPERTY(EditAnywhere)
	bool bOpenDoorInside;
	
protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(VisibleAnywhere)
	bool bPlayerIsInRange;
};
