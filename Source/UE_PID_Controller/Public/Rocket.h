// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PIDController.h"
#include "GameFramework/Actor.h"
#include "Rocket.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API ARocket : public AActor {
	GENERATED_BODY()

public:
	ARocket();
	UFUNCTION(BlueprintPure, BlueprintCallable)
	UPIDController* GetController();
	UFUNCTION(BlueprintCallable)
	void SetTarget(int Index);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PID")
	float Power;
	UPROPERTY(EditAnywhere, Category="Components")
	float FlameSize;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PID")
	UPIDController* Controller;
	UPROPERTY(EditAnywhere, Category="Targets")
	TArray<AActor*> Targets;
	TArray<FVector> TargetPositions;
	UPROPERTY(EditAnywhere, Category="Targets")
	FVector TargetPosition;
	void SetScale(UStaticMeshComponent* Mesh, float Scale);
};
