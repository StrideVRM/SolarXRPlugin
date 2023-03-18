#pragma once

#include "CoreMinimal.h"
#include "SolarXRDeviceData.generated.h"

USTRUCT(BlueprintType)
struct FSolarXRDeviceDeserialized
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    FString Name;

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    uint32 DeviceClass;

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    uint32 DeviceFlags;

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    uint32 BatteryLevel;

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    FQuat Rotation;

    UPROPERTY(BlueprintReadOnly, Category = "SolarXR Device")
    FVector Position;
};

USTRUCT(BlueprintType)
struct FSolarXRDeviceToSerialize
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    uint32 DeviceClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    uint32 DeviceFlags;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    uint32 BatteryLevel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    FQuat Rotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SolarXR Device")
    FVector Position;
};
