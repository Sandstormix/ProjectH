// Fill out your copyright notice in the Description page of Project Settings.


#include "Doors.h"

#include "ProjectHCharacter.h"

ADoors::ADoors()
{
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	if(MeshComponent)
		DoorMesh->SetupAttachment(MeshComponent);
	
}

void ADoors::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBoxBeginOverlap(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, SweepResult);
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("This a door"));
		if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
		{
			PlayerReference = Cast<AProjectHCharacter>(OtherActor);
			bPlayerIsInRange = true;
			PlayerReference->SetInteractableObjectInRange(this);
		}
}

void ADoors::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	Super::OnBoxEndOverlap(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex);
		if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
		{
			PlayerReference->SetInteractableObjectInRange(nullptr);
			bPlayerIsInRange = false;
		
			PlayerReference = nullptr;
		}
}


void ADoors::OnInteract(bool bCanInteract)
{
	bCanInteract = bPlayerIsInRange;
	if(bCanInteract)
	{
		OpenDoors(DoorOpenAngle);	
	}
}

void ADoors::OpenDoors(float doorAngle)
{
	if(bOpenDoorInside)
	{
		const FRotator NewDoorRotation = FRotator(0.0f, doorAngle, 0.0f);
		DoorMesh->SetWorldRotation(NewDoorRotation);
	}
	else
	{
		const FRotator NewDoorRotation = FRotator(0.0f, doorAngle, 0.0f);
		DoorMesh->SetWorldRotation(NewDoorRotation);
	}
}








// void ADoors::OnDoorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("XDDDDD"));
// 	
// 	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
// 	{
// 		PlayerReference = Cast<AProjectHCharacter>(OtherActor);
// 		bPlayerIsInRange = true;
// 		PlayerReference->SetInteractableObjectInRange(this);
// 	}
// }
//
// void ADoors::OnDoorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
// {
// 	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
// 	{
// 		PlayerReference->SetInteractableObjectInRange(nullptr);
// 		bPlayerIsInRange = false;
// 	
// 		PlayerReference = nullptr;
// 	}
// }