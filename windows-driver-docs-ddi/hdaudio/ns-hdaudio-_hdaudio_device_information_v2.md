# _HDAUDIO_DEVICE_INFORMATION_V2 structure

## Description

The _HDAUDIO_DEVICE_INFORMATION_V2 structure specifies the hardware capabilities of the HD Audio bus controller.

## Members

### `Size`

Specifies the size in bytes of the _HDAUDIO_DEVICE_INFORMATION_V2 structure.

### `DeviceVersion`

Specifies the HD Audio controller device version.

### `DriverVersion`

Specifies the HD Audio bus driver version.

### `CodecsDetected`

Specifies the number of codecs that the HD Audio controller detects on the HD Audio Link.

### `IsStripingSupported`

Specifies whether the HD Audio controller supports [Striping](https://learn.microsoft.com/windows-hardware/drivers/audio/striping). If **TRUE**, it supports striping (with at least two SDO lines). If **FALSE**, it does not support striping.

### `CtrlRevision`

HDA controller revision.

### `CtrlVendorId`

HDA controller vendor ID.

### `CtrlDeviceId`

HDA controller device ID.

## Remarks

With the release of Windows 1903 the GetDeviceInformation method of all the HDAUDIO_BUS_INTERFACE* was expanded to also accept a larger input structure: _HDAUDIO_DEVICE_INFORMATION_V2. The original input structure of [HDAUDIO_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_device_information) continues to be supported.

If the hdaudbus supports the new size, it inits all the fields and sets the Size field to sizeof(_HDAUDIO_DEVICE_INFORMATION_V2), else it returns the information only for _HDAUDIO_DEVICE_INFORMATION and sets the Size field to sizeof(_HDAUDIO_DEVICE_INFORMATION).

**Usage Examples**

```cpp
_HDAUDIO_DEVICE_INFORMATION_V2 info;

_HDAUDIO_DEVICE_INFORMATION_V2_INIT(&info);

status = m_BusIntV3->GetDeviceInformation(m_BusIntV3->Context, (PHDAUDIO_DEVICE_INFORMATION)&info);
```

The [GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information) routine uses the _HDAUDIO_DEVICE_INFORMATION_V2 structure to provide information about the HD Audio controller's device-specific capabilities to clients.

## See also

[HDAUDIO_DEVICE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_device_information)

[GetDeviceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pget_device_information)