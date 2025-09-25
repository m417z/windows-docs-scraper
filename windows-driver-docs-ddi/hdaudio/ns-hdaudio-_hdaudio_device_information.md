# _HDAUDIO_DEVICE_INFORMATION structure

## Description

The HDAUDIO_DEVICE_INFORMATION structure specifies the hardware capabilities of the HD Audio bus controller.

## Members

### `Size`

Specifies the size in bytes of the HDAUDIO_DEVICE_INFORMATION structure.

### `DeviceVersion`

Specifies the HD Audio controller device version.

### `DriverVersion`

Specifies the HD Audio bus driver version.

### `CodecsDetected`

Specifies the number of codecs that the HD Audio controller detects on the HD Audio Link.

### `IsStripingSupported`

Specifies whether the HD Audio controller supports [striping](https://learn.microsoft.com/windows-hardware/drivers/audio/striping). If **TRUE**, it supports striping (with at least two SDO lines). If **FALSE**, it does not support striping.

## Remarks

The [GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information) routine uses this structure to provide information about the HD Audio controller's device-specific capabilities to clients.

## See also

[GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information)