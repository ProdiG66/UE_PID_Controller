﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Rocket.h"
#include "GameFramework/Actor.h"
#include "SingleRocket.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API ASingleRocket : public ARocket {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASingleRocket();
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* Flame;
	virtual void Tick(float DeltaTime) override;
};
