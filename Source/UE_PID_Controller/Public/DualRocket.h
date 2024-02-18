// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rocket.h"
#include "GameFramework/Actor.h"
#include "DualRocket.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API ADualRocket : public ARocket {
	GENERATED_BODY()

public:
	ADualRocket();
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* FlamePositive;
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* FlameNegative;
	virtual void Tick(float DeltaTime) override;
};
