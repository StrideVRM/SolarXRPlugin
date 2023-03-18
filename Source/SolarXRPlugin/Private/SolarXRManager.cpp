#include "SolarXRManager.h"
#include "Generated/all_generated.h"

bool USolarXRManager::DeserializeSolarXRData(const TArray<uint8>& InBuffer, FSolarXRDeviceDeserialized& OutDevice)
{
    SolarXR::SolarDeviceMessage deviceMessage;

    if (deviceMessage.ParseFromArray(InBuffer.GetData(), InBuffer.Num()))
    {
        if (deviceMessage.has_name())
        {
            OutDevice.Name = UTF8_TO_TCHAR(deviceMessage.name().c_str());
        }

        if (deviceMessage.has_position())
        {
            const auto& position = deviceMessage.position();
            OutDevice.Position = FVector(position.x(), position.y(), position.z());
        }

        if (deviceMessage.has_rotation())
        {
            const auto& rotation = deviceMessage.rotation();
            OutDevice.Rotation = FQuat(rotation.x(), rotation.y(), rotation.z(), rotation.w());
        }

        return true;
    }

    return false;
}

bool USolarXRManager::SerializeSolarXRData(const FSolarXRDeviceToSerialize& InDevice, TArray<uint8>& OutBuffer)
{
    SolarXR::SolarDeviceMessage deviceMessage;

    if (!InDevice.Name.IsEmpty())
    {
        deviceMessage.set_name(TCHAR_TO_UTF8(*InDevice.Name));
    }

    auto* position = new SolarXR::Vector3();
    position->set_x(InDevice.Position.X);
    position->set_y(InDevice.Position.Y);
    position->set_z(InDevice.Position.Z);
    deviceMessage.set_allocated_position(position);

    auto* rotation = new SolarXR::Quaternion();
    rotation->set_x(InDevice.Rotation.X);
    rotation->set_y(InDevice.Rotation.Y);
    rotation->set_z(InDevice.Rotation.Z);
    rotation->set_w(InDevice.Rotation.W);
    deviceMessage.set_allocated_rotation(rotation);

    std::string buffer;
    if (deviceMessage.SerializeToString(&buffer))
    {
        OutBuffer.Empty(buffer.size());
        OutBuffer.Append(reinterpret_cast<const uint8*>(buffer.data()), buffer.size());
        return true;
    }

    return false;
}
