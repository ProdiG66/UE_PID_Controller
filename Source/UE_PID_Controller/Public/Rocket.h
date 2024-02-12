// Fill out your copyright notice in the Description page of Project Settings.

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
	UPIDController* GetController();
	void SetTarget(int Index);
	UPROPERTY(EditAnywhere, Category="PID")
	float Power;
	UPROPERTY(EditAnywhere, Category="Components")
	float FlameSize;

protected:
	virtual void BeginPlay() override;
	TWeakObjectPtr<UShapeComponent> RootComponent;
	UPROPERTY(EditAnywhere, Category="PID")
	UPIDController* Controller;
	UPROPERTY(EditAnywhere, Category="Targets")
	TArray<AActor*> Targets;
	TArray<FVector> TargetPositions;
	FVector TargetPosition;
	void SetScale(UStaticMeshComponent* Mesh, float Scale);
};
