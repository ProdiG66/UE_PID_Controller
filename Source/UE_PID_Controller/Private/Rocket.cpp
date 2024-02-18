// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.


#include "Rocket.h"

#include "PIDController.h"
#include "Components/ShapeComponent.h"

// Sets default values
ARocket::ARocket() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Controller = CreateDefaultSubobject<UPIDController>(TEXT("PID Controller"));
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

void ARocket::SetScale(UStaticMeshComponent* Mesh, float Scale) {
	Scale = FMath::Clamp(Scale, 0.0f, 1.0f);

	if (Scale < 0.1f) {
		Mesh->SetActive(false);
	}
	else {
		Mesh->SetActive(true);
		Mesh->SetRelativeScale3D(FVector(Scale * FlameSize));
	}
}
