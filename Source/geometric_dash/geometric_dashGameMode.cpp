// Copyright Epic Games, Inc. All Rights Reserved.

#include "geometric_dashGameMode.h"
#include "geometric_dashCharacter.h"
#include "UObject/ConstructorHelpers.h"

Ageometric_dashGameMode::Ageometric_dashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
