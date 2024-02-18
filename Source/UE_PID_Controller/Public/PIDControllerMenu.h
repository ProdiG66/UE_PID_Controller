// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rocket.h"
#include "Blueprint/UserWidget.h"
#include "PIDControllerMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE_PID_CONTROLLER_API UPIDControllerMenu : public UUserWidget {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	ARocket* Rocket;
};
