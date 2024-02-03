// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComponent;
	
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	BoxCollider->SetupAttachment(RootComponent);
}

void AInteractableActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnBoxBeginOverlap);
	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AInteractableActor::OnBoxEndOverlap);
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableActor::OnInteract(bool bCanInteract, AProjectHCharacter* playerReference)
{
	if(bCanInteract)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("Interaction"));
	}
}

void AInteractableActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void AInteractableActor::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	
}

