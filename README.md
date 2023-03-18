<h1>SolarXR Plugin for Unreal Engine 5</h1>

This plugin provides support for the SolarXR-Protocol in Unreal Engine 5, allowing developers to easily integrate device tracking using the SolarXR-Protocol into their projects.

<h2>Features</h2>

* Serialize and deserialize SolarXR-Protocol messages
* Expose easy-to-use structures for handling SolarXR data in both C++ and Blueprints
* Automatically handle flatbuffer serialization and deserialization internally

<h2>Prerequisites</h2>

Unreal Engine 5.1 or later

<h2>Installation</h2>

* Clone or download this repository.
* Copy the "SolarXRPlugin" folder into your Unreal Engine project's "Plugins" folder.
* Restart the Unreal Editor. The plugin should now be recognized and enabled by default. You can disable or enable it in the "Edit" -> "Plugins" menu under the "Tracking" category.

<h2>Usage</h2>

<h3>In C++</h3>

Include the SolarXRManager header and the SolarXRDeviceData header in your source file:

<html>
<head>
#include "SolarXRManager.h"<br>
#include "SolarXRDeviceData.h"
</head>
</html>

To deserialize SolarXR data, call the DeserializeSolarXRData function:<br>

TArray<uint8> InBuffer; // Input data buffer with serialized SolarXR data. <br>
FSolarXRDeviceDeserialized OutDevice; // Output data structure to store deserialized data. <br>

bool bSuccess = USolarXRManager::DeserializeSolarXRData(InBuffer, OutDevice); <br>
if (bSuccess) { <br>
    // Successfully deserialized the SolarXR data. <br>
    // Use the deserialized data as needed in your application. <br>
    FString DeviceName = OutDevice.Name; <br>
    FVector DevicePosition = OutDevice.Position; <br>
    FQuat DeviceRotation = OutDevice.Rotation; <br>
} else { <br>
    // Failed to deserialize the data. Handle the error as needed. <br>
} <br>

To serialize SolarXR data, call the SerializeSolarXRData function:

FSolarXRDeviceToSerialize InDevice; // Input data structure with SolarXR device data to be serialized. <br>
InDevice.Name = "Tracker001"; <br>
InDevice.Position = FVector(100, 200, 300); <br>
InDevice.Rotation = FQuat(FRotator(90, 0, 0)); <br>

TArray<uint8> OutBuffer; // Output data buffer to store the serialized data.

bool bSuccess = USolarXRManager::SerializeSolarXRData(InDevice, OutBuffer); <br>
if (bSuccess) { <br>
    // Successfully serialized the SolarXR data. <br>
    // Send the serialized data through a network socket, save to a file, or use as needed. <br>
} else { <br>
    // Failed to serialize the data. Handle the error as needed. <br>
} <br>

<h3>In Blueprints</h3>

To deserialize SolarXR data, call the "Deserialize Solar XR Data" function from the USolarXRManager class. After deserialization, you can access the fields in the FSolarXRDeviceDeserialized structure, such as Name, Position, and Rotation.
To serialize SolarXR data, create an instance of the FSolarXRDeviceToSerialize structure, set its fields, and call the "Serialize Solar XR Data" function from the USolarXRManager class.
The functions are exposed to Blueprints and can be used in the visual scripting environment.

Use the FSolarXRDeviceDeserialized structure to access the deserialized fields and the FSolarXRDeviceToSerialize structure to add fields for serialization.

<b>License</b>

This project is licensed under the MIT License.

<b>Acknowledgments</b>

SolarXR-Protocol: https://github.com/SlimeVR/SolarXR-Protocol
