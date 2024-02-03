// Fill out your copyright notice in the Description page of Project Settings.


#include "InspectItem.h"

#include "ProjectHCharacter.h"

// Sets default values
AInspectItem::AInspectItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AInspectItem::OnInteract(bool bCanInteract, AProjectHCharacter* playerReference)
{
	if(CharacterReference)
	{
		ChangeToInspectionCamera();
	}
}

void AInspectItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AInspectItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInspectItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInspectItem::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBoxBeginOverlap(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, SweepResult);
	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
	{
		CharacterReference = Cast<AProjectHCharacter>(OtherActor);
		CharacterReference->SetInteractableObjectInRange(this);
	}
}

void AInspectItem::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	Super::OnBoxEndOverlap(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex);
	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
	{
		CharacterReference->SetInteractableObjectInRange(nullptr);
		CharacterReference = nullptr;
	}
}


UStaticMeshComponent* AInspectItem::GetStaticMesh()
{
	return ActorStaticMesh;
}

UCameraComponent* AInspectItem::GetCamera()
{
	return ActorCameraComponent;
}

UBoxComponent* AInspectItem::GetBoxComponent()
{
	return ActorBoxComponent;
}

ACameraActor* AInspectItem::GetCameraActor()
{
	return CameraActor;
}

AProjectHCharacter* AInspectItem::GetCharacterReference()
{
	return CharacterReference;
}

void AInspectItem::SetStaticMeshComponent(UStaticMeshComponent* staticMesh)
{
	ActorStaticMesh = staticMesh;
}

void AInspectItem::SetCamera(UCameraComponent* cameraComponent)
{
	ActorCameraComponent = cameraComponent;
}

void AInspectItem::SetBoxComponent(UBoxComponent* boxComponent)
{
	ActorBoxComponent = boxComponent;
}

void AInspectItem::SetCameraActor(ACameraActor* cameraActor)
{
	CameraActor = cameraActor;
}

