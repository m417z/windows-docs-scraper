## Description

The **KSWAVE_COMPATCAPS** structure is used to describe the compatible capabilities of a device.

## Members

### `ulDeviceType`

Specifies the following flags:

| Flag | Meaning |
|---|---|
| KSWAVE_COMPATCAPS_INPUT | Indicates that the device accepts input. |
| KSWAVE_COMPATCAPS_OUTPUT | Indicates that the device produces output. |

## Remarks

This structure is used by the [KSPROPERTY_WAVE_COMPATIBLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-compatible-capabilities) property.

## See also

[KSPROPERTY_WAVE_COMPATIBLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-wave-compatible-capabilities)