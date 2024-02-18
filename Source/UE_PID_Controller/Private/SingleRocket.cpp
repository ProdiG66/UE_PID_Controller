// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "SingleRocket.h"

#include "PIDController.h"
#include "Components/ShapeComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASingleRocket::ASingleRocket() {
	Flame = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Flame"));
	Flame->SetupAttachment(RootComponent);
	Flame->SetRelativeRotation(FRotator(0, 0, 180));
}

void ASingleRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (TargetPositions.Num() > 0) {
		const float Throttle = GetController()->Update(DeltaTime, Mesh->GetComponentLocation().Z, TargetPosition.Z);
		if (IsValid(Mesh)) {
			Mesh->AddForce(FVector(0, 0, Throttle * Power));
		}

		if (IsValid(Flame)) {
			SetThrust(Flame, Throttle);
		}
	}
}
