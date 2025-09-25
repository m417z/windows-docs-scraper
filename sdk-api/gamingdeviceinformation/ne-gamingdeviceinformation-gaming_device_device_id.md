# GAMING_DEVICE_DEVICE_ID enumeration

## Description

Indicates the type of device that the game is running on.

## Constants

### `GAMING_DEVICE_DEVICE_ID_NONE:0`

The device is not in the Xbox family.

### `GAMING_DEVICE_DEVICE_ID_XBOX_ONE:0x768BAE26`

The device is an Xbox One (original).

### `GAMING_DEVICE_DEVICE_ID_XBOX_ONE_S:0x2A7361D9`

The device is an Xbox One S.

### `GAMING_DEVICE_DEVICE_ID_XBOX_ONE_X:0x5AD617C7`

The device is an Xbox One X.

### `GAMING_DEVICE_DEVICE_ID_XBOX_ONE_X_DEVKIT:0x10F7CDE3`

The device is an Xbox One X dev kit.

## Remarks

This is a Win32 API that's supported in both Win32 and UWP apps. While it works on any device family, it's only really of value on Xbox devices.

## See also

[GAMING_DEVICE_MODEL_INFORMATION structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/gamingdeviceinformation/ns-gamingdeviceinformation-gaming_device_model_information)

[Gaming Device Information](https://learn.microsoft.com/previous-versions/windows/desktop/gamingdvcinfo/gaming-device-information-portal)