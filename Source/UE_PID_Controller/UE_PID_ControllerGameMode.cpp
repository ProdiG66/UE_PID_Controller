// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_PID_ControllerGameMode.h"
#include "UE_PID_ControllerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_PID_ControllerGameMode::AUE_PID_ControllerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
