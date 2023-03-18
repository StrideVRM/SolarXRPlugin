#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SolarXRDeviceData.h"
#include "SolarXRManager.generated.h"

UCLASS()
class SOLARXRPLUGIN_API USolarXRManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SolarXR")
    static bool DeserializeSolarXRData(const TArray<uint8>& InBuffer, FSolarXRDeviceDeserialized& OutDevice);

    UFUNCTION(BlueprintCallable, Category = "SolarXR")
    static bool SerializeSolarXRData(const FSolarXRDeviceToSerialize& InDevice, TArray<uint8>& OutBuffer);
};
