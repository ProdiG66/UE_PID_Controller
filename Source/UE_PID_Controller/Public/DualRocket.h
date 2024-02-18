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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	UParticleSystemComponent* FlamePositive;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	UParticleSystemComponent* FlameNegative;
	virtual void Tick(float DeltaTime) override;
};
