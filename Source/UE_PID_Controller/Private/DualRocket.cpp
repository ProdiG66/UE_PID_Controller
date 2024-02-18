// Fill out your copyright notice in the Description page of Project Settings.


#include "DualRocket.h"
#include "PIDController.h"
#include "Misc/App.h"
#include "Components/ShapeComponent.h"

ADualRocket::ADualRocket() : ARocket() {}

void ADualRocket::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (TargetPositions.Num() > 0) {
		UStaticMeshComponent* Mesh = Cast<UStaticMeshComponent>(GetRootComponent());
		const float Throttle = GetController()->Update(DeltaTime, Mesh->GetComponentLocation().Y, TargetPosition.Y);
		if (IsValid(Mesh)) {
			Mesh->AddForce(FVector(0, Throttle * Power, 0));
			// this->SetActorLocation(TargetPosition);
		}

		if (IsValid(FlamePositive)) {
			SetScale(FlamePositive, -Throttle);
		}
		if (IsValid(FlameNegative)) {
			SetScale(FlameNegative, Throttle);
		}
	}
}
