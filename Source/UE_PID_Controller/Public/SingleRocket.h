// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rocket.h"
#include "GameFramework/Actor.h"
#include "SingleRocket.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API ASingleRocket : public ARocket {
	GENERATED_BODY()

public:
	ASingleRocket();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components")
	UParticleSystemComponent* Flame;
	virtual void Tick(float DeltaTime) override;
};
