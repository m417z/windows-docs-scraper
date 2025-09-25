## Description

Describes flash control properties in the **PROPSETID_VIDCAP_CAMERACONTROL_FLASH** camera control property set. This structure specifies property values that are used by applications to configure the camera's flash.

## Members

### `Flash`

Indicates requested flash settings. This value must be one of these possible values:

| Value | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLASH_OFF | The flash should never activate. |
| KSPROPERTY_CAMERACONTROL_FLASH_ON | The flash should activate regardless of lighting conditions. |
| KSPROPERTY_CAMERACONTROL_FLASH_AUTO | The flash should be controlled by the device and driver based on lighting conditions. |

### `Capabilities`

Indicates the flash modes that the device supports. This value is a bitwise **OR** of these possible values:

| Value | Meaning |
|---|---|
| KSPROPERTY_CAMERACONTROL_FLASH_FLAGS_AUTO | The device and driver automatically control flash settings. |
| KSPROPERTY_CAMERACONTROL_FLASH_FLAGS_MANUAL | The user manually sets the flash settings. |

## See also

[KSPROPERTY_CAMERACONTROL_FLASH_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-cameracontrol-flash-property)