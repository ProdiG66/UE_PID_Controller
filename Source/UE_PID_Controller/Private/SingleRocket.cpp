// Fill out your copyright notice in the Description page of Project Settings.


#include "SingleRocket.h"

#include "PIDController.h"
#include "Components/ShapeComponent.h"

ASingleRocket::ASingleRocket() {}

void ASingleRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	const float Throttle = GetController()->Update(DeltaTime, GetActorLocation().Z, TargetPosition.Z);
	RootComponent->AddForce(FVector(0, 0, Throttle * Power));

	SetScale(Flame, Throttle);
}
