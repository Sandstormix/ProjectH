// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Add default functionality here for any IInteractable functions that are not pure virtual.
void IInteractable::OnInteract(bool bCanInteract)
{
	GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Yellow, TEXT("Use this function to call OnInteractEvents"));
}

