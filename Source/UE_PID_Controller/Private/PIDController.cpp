// Fill out your copyright notice in the Description page of Project Settings.


#include "PIDController.h"


UPIDController::UPIDController() {}

void UPIDController::Reset() {
	DerivativeInitialized = false;
}

float UPIDController::Update(float DeltaTime, float CurrentValue, float TargetValue) {
	const float Error = TargetValue - CurrentValue;
	const float ErrorRateOfChange = (Error - ErrorLast) / DeltaTime;
	const float ValueRateOfChange = (CurrentValue - ValueLast) / DeltaTime;
	return CalculatePID(DeltaTime, Error, ErrorRateOfChange, CurrentValue, ValueRateOfChange);
}

float UPIDController::UpdateAngle(float DeltaTime, float CurrentAngle, float TargetAngle) {
	const float Error = AngleDifference(TargetAngle, CurrentAngle);
	const float ErrorRateOfChange = AngleDifference(Error, ErrorLast) / DeltaTime;
	const float ValueRateOfChange = AngleDifference(CurrentAngle, ValueLast) / DeltaTime;
	return CalculatePID(DeltaTime, Error, ErrorRateOfChange, CurrentAngle, ValueRateOfChange);
}

float UPIDController::AngleDifference(float A, float B) {
	float Result = fmodf((A - B + 540), 360);
	if (Result > 180) {
		Result -= 360;
	}
	return Result;
}

float UPIDController::CalculatePID(float DeltaTime, float Error, float ErrorRateOfChange, float Current,
									float ValueRateOfChange) {
	if (DeltaTime <= 0) {
		return 0;
	}
	const float P = ProportionalGain * Error;
	IntegrationStored = FMath::Clamp(IntegrationStored + (Error * DeltaTime), -IntegralSaturation, IntegralSaturation);
	const float I = IntegralGain * IntegrationStored;
	ErrorLast = Error;
	ValueLast = Current;
	Velocity = ValueRateOfChange;
	float DeriveMeasure = 0;
	if (DerivativeInitialized) {
		if (DerivativeMeasurement == EDerivativeMeasurement::Velocity) {
			DeriveMeasure = -ValueRateOfChange;
		}
		else {
			DeriveMeasure = ErrorRateOfChange;
		}
	}
	else {
		DerivativeInitialized = true;
	}
	const float D = DerivativeGain * DeriveMeasure;
	const float Result = P + I + D;
	return FMath::Clamp(Result, OutputMin, OutputMax);
}
