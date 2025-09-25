## Description

Microsoft USB Audio Sideband USB controller Set of Parameters.

```cpp
// {7FE4A3DB-B637-4168-B853-4317079560D2}
DEFINE_GUID(SIDEBANDAUDIO_PARAMS_SET_USB_CONTROLLER,
    0x7fe4a3db, 0xb637, 0x4168, 0xb8, 0x53, 0x43, 0x17, 0x7, 0x95, 0x60, 0xd2);
```

## Constants

### `SIOP_TYPE_USBAUD_CONTROLLER_CONFIG_INFO_DEVICE_BEHIND_HUB`

Provides USB sideband audio information, for example about a USB headset endpoint.

### `SBUSBAUD_CONTROLLER_CONFIG_INFO_TYPE_INVALID`

An invalid controller config type.

## Remarks

Some systems may not be able to support a USB Sideband device behind a hub.

## See also

[usbsidebandaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbsidebandaudio/)