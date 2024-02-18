// Copyright (c) 2024 Jan Enri Arquero. All rights reserved.

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
