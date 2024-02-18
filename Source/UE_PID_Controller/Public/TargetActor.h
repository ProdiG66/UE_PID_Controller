// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rocket.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API ATargetActor : public AActor {
	GENERATED_BODY()

public:
	ATargetActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	ARocket* Rocket;
};
