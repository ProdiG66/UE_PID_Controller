// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DerivativeMeasurement.h"
#include "PIDController.generated.h"

UCLASS()
class UE_PID_CONTROLLER_API UPIDController : public UActorComponent {
	GENERATED_BODY()

public:
	UPIDController();

	UPROPERTY(EditAnywhere, Category="PID Coefficients")
	float ProportionalGain = 3;
	UPROPERTY(EditAnywhere, Category="PID Coefficients")
	float IntegralGain = 6;
	UPROPERTY(EditAnywhere, Category="PID Coefficients")
	float DerivativeGain = 3;

	float OutputMin = -1;
	float OutputMax = 1;
	UPROPERTY(EditAnywhere, Category="PID Coefficients")
	float IntegralSaturation = 0;
	EDerivativeMeasurement DerivativeMeasurement;

	float ValueLast;
	float ErrorLast;
	float IntegrationStored;
	float Velocity;
	bool DerivativeInitialized;
	void Reset();
	float Update(float DeltaTime, float CurrentValue, float TargetValue);
	float UpdateAngle(float DeltaTime, float CurrentAngle, float TargetAngle);

private:
	float AngleDifference(float A, float B);
	float CalculatePID(float DeltaTime, float Error, float ErrorRateOfChange, float Current, float ValueRateOfChange);
};
