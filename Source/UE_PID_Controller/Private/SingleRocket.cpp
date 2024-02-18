// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "SingleRocket.h"

#include "PIDController.h"
#include "Components/ShapeComponent.h"

ASingleRocket::ASingleRocket() {}

void ASingleRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (TargetPositions.Num() > 0) {
		UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(GetRootComponent());
		const float Throttle = GetController()->Update(DeltaTime, Mesh->GetComponentLocation().Z, TargetPosition.Z);
		if (IsValid(Mesh)) {
			// RootComponent->AddForce(FVector(0, 0, Throttle * Power));
			Mesh->AddForce(FVector(0, 0, Throttle * Power));
		}

		if (IsValid(Flame)) {
			SetScale(Flame, Throttle);
		}
	}
}
