// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "DualRocket.h"
#include "PIDController.h"
#include "Misc/App.h"
#include "Components/ShapeComponent.h"
#include "Particles/ParticleSystemComponent.h"

ADualRocket::ADualRocket() {
	FlamePositive = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Right"));
	FlamePositive->SetupAttachment(RootComponent);
	FlamePositive->SetRelativeRotation(FRotator(0, 0, 90));
	FlameNegative = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Left"));
	FlameNegative->SetupAttachment(RootComponent);
	FlameNegative->SetRelativeRotation(FRotator(0, 0, 270));
}

void ADualRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (TargetPositions.Num() > 0) {
		const float Throttle = GetController()->Update(DeltaTime, Mesh->GetComponentLocation().Y, TargetPosition.Y);
		if (IsValid(Mesh)) {
			Mesh->AddForce(FVector(0, Throttle * Power, 0));
		}

		if (IsValid(FlamePositive)) {
			SetThrust(FlamePositive, -Throttle);
		}
		if (IsValid(FlameNegative)) {
			SetThrust(FlameNegative, Throttle);
		}
	}
}
