// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "Rocket.h"

#include "PIDController.h"
#include "Components/ShapeComponent.h"
#include "Particles/ParticleSystemComponent.h"

ARocket::ARocket() {
	PrimaryActorTick.bCanEverTick = true;
	Controller = CreateDefaultSubobject<UPIDController>(TEXT("PID Controller"));
	Controller->ProportionalGain = 6;
	Controller->IntegralGain = 1;
	Controller->DerivativeGain = 10;
	Controller->IntegralSaturation = 0.5;
	Controller->DerivativeMeasurement = EDerivativeMeasurement::ErrorRateOfChange;
	Power = 100;
	FlameSize = 1;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RocketMesh"));
	SetRootComponent(Mesh);
}

UPIDController* ARocket::GetController() {
	return Controller;
}

void ARocket::SetTarget(int Index) {
	UE_LOG(LogTemp, Warning, TEXT("Index: %i"), Index);
	if (Index < TargetPositions.Num()) {
		TargetPosition = TargetPositions[Index];
		UE_LOG(LogTemp, Warning, TEXT("Target: %i | TargetPosition: %f, %f, %f"), Index, TargetPosition.X,
				TargetPosition.Y, TargetPosition.Z);
	}
}

void ARocket::BeginPlay() {
	Super::BeginPlay();
	for (const AActor* Target : Targets) {
		TargetPositions.Add(Target->GetActorLocation());
	}
}

void ARocket::SetThrust(UParticleSystemComponent* Particles, float Thrust) {
	Thrust = FMath::Clamp(Thrust, 0.0f, 1.0f);

	Particles->SetFloatParameter(FName("Rate"), Thrust);
	Particles->SetFloatParameter(FName("Velocity"), Thrust);
	Particles->SetVectorParameter(FName("Velocity"), FVector(Thrust));
	if (Thrust < 0.01f) {
		Particles->SetActive(false);
	}
	else {
		Particles->SetActive(true);
	}
}
