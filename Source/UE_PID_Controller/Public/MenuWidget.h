// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PIDControllerMenu.h"
#include "Rocket.h"
#include "GameFramework/Actor.h"
#include "MenuWidget.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API AMenuWidget : public AActor {
	GENERATED_BODY()

public:
	AMenuWidget();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	ARocket* Rocket;
	UFUNCTION(BlueprintCallable)
	void SetRocket(UPIDControllerMenu* Menu);
};
