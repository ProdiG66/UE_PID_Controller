// Fill out your copyright notice in the Description page of Project Settings.


#include "DualRocket.h"
#include "PIDController.h"
#include "Components/ShapeComponent.h"

ADualRocket::ADualRocket() : ARocket() {}

void ADualRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	const float Throttle = GetController()->Update(DeltaTime, GetActorLocation().X, TargetPosition.X);
	RootComponent->AddForce(FVector(Throttle * Power, 0, 0));

	SetScale(FlamePositive, -Throttle);
	SetScale(FlameNegative, Throttle);
}
