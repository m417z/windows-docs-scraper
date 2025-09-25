# GetGamingDeviceModelInformation function

## Description

Gets information about the device that the game is running on.

## Parameters

### `information` [out]

A structure containing information about the device that the game is running on.

## Return value

This function does not return a value.

## Remarks

Supported in both Win32 and UWP apps.

This function gets information about the console that the game is running on, including the type of console (Xbox One, Xbox One S, etc.) and the vendor. On non-Xbox devices, it returns **GAMING_DEVICE_DEVICE_ID_NONE** and **GAMING_DEVICE_VENDOR_ID_NONE**.

If the game is running in an emulation mode, the type of device being emulated is returned. For example, if the game is running on an Xbox One X dev kit in Xbox One emulation mode, **GAMING_DEVICE_DEVICE_ID_XBOX_ONE** is returned.

## See also

[GAMING_DEVICE_MODEL_INFORMATION structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/gamingdeviceinformation/ns-gamingdeviceinformation-gaming_device_model_information)

[Gaming Device Information](https://learn.microsoft.com/previous-versions/windows/desktop/gamingdvcinfo/gaming-device-information-portal)