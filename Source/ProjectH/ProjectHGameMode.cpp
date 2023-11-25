// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectHGameMode.h"
#include "ProjectHCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectHGameMode::AProjectHGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
