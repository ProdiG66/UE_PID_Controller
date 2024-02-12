// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "DerivativeMeasurement.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDerivativeMeasurement : uint8 {
	Velocity UMETA(DisplayName = "Velocity"),
	ErrorRateOfChange UMETA(DisplayName = "Error Rate Of Change"),
};
