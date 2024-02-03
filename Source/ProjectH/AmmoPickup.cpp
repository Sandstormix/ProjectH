// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoPickup.h"

#include "Pistol.h"
#include "ProjectHCharacter.h"

// Sets default values
AAmmoPickup::AAmmoPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AAmmoPickup::OnInteract(bool bCanInteract, AProjectHCharacter* playerReference)
{
	if(playerReference)
	{
			GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("XDDDDDDDDDD"));
	    	Cast<APistol>(playerReference->GetPlayerRangeWeapon())->AddAmmo(7);
	}
}

void AAmmoPickup::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
	{
		PlayerReference = Cast<AProjectHCharacter>(OtherActor);
		PlayerReference->SetInteractableObjectInRange(this);
	}
}

void AAmmoPickup::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if(OtherActor == Cast<AProjectHCharacter>(OtherActor))
	{
		PlayerReference->SetInteractableObjectInRange(nullptr);
		PlayerReference = nullptr;
	}
}

// Called when the game starts or when spawned
void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

