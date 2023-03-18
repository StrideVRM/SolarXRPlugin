SolarXR Plugin for Unreal Engine 5

This plugin provides support for the SolarXR-Protocol in Unreal Engine 5, allowing developers to easily integrate device tracking using the SolarXR-Protocol into their projects.

Features

* Serialize and deserialize SolarXR-Protocol messages
* Expose easy-to-use structures for handling SolarXR data in both C++ and Blueprints
* Automatically handle flatbuffer serialization and deserialization internally

Prerequisites

Unreal Engine 5.1 or later

Installation

* Clone or download this repository.
* Copy the "SolarXRPlugin" folder into your Unreal Engine project's "Plugins" folder.
* Restart the Unreal Editor. The plugin should now be recognized and enabled by default. You can disable or enable it in the "Edit" -> "Plugins" menu under the "Tracking" category.

Usage

In C++

Include the SolarXRManager header and the SolarXRDeviceData header in your source file:

#include "SolarXRManager.h"
#include "SolarXRDeviceData.h"

To deserialize SolarXR data, call the DeserializeSolarXRData function:

TArray<uint8> InBuffer; // Input data buffer with serialized SolarXR data.
FSolarXRDeviceDeserialized OutDevice; // Output data structure to store deserialized data.

bool bSuccess = USolarXRManager::DeserializeSolarXRData(InBuffer, OutDevice);
if (bSuccess) {
    // Successfully deserialized the SolarXR data.
    // Use the deserialized data as needed in your application.
    FString DeviceName = OutDevice.Name;
    FVector DevicePosition = OutDevice.Position;
    FQuat DeviceRotation = OutDevice.Rotation;
} else {
    // Failed to deserialize the data. Handle the error as needed.
}

To serialize SolarXR data, call the SerializeSolarXRData function:

FSolarXRDeviceToSerialize InDevice; // Input data structure with SolarXR device data to be serialized.
InDevice.Name = "Tracker001";
InDevice.Position = FVector(100, 200, 300);
InDevice.Rotation = FQuat(FRotator(90, 0, 0));

TArray<uint8> OutBuffer; // Output data buffer to store the serialized data.

bool bSuccess = USolarXRManager::SerializeSolarXRData(InDevice, OutBuffer);
if (bSuccess) {
    // Successfully serialized the SolarXR data.
    // Send the serialized data through a network socket, save to a file, or use as needed.
} else {
    // Failed to serialize the data. Handle the error as needed.
}

In Blueprints

To deserialize SolarXR data, call the "Deserialize Solar XR Data" function from the USolarXRManager class. After deserialization, you can access the fields in the FSolarXRDeviceDeserialized structure, such as Name, Position, and Rotation.
To serialize SolarXR data, create an instance of the FSolarXRDeviceToSerialize structure, set its fields, and call the "Serialize Solar XR Data" function from the USolarXRManager class.
The functions are exposed to Blueprints and can be used in the visual scripting environment.

Use the FSolarXRDeviceDeserialized structure to access the deserialized fields and the FSolarXRDeviceToSerialize structure to add fields for serialization.

License

This project is licensed under the MIT License.

Acknowledgments

SolarXR-Protocol: https://github.com/SlimeVR/SolarXR-Protocol
