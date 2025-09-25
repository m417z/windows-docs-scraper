# AUXCAPSA structure

## Description

The **AUXCAPS** structure describes the capabilities of an auxiliary output device.

## Members

### `wMid`

Manufacturer identifier for the device driver for the auxiliary audio device. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier for the auxiliary audio device. Currently, no product identifiers are defined for auxiliary audio devices.

### `vDriverVersion`

Version number of the device driver for the auxiliary audio device. The high-order byte is the major version number, and the low-order byte is the minor version number.

### `szPname`

Product name in a null-terminated string.

### `wTechnology`

Type of the auxiliary audio output:

| Name | Description |
| --- | --- |
| **AUXCAPS_AUXIN** | Audio output from auxiliary input jacks. |
| **AUXCAPS_CDAUDIO** | Audio output from an internal CD-ROM drive. |

### `dwSupport`

Describes optional functionality supported by the auxiliary audio device.

| Name | Description |
| --- | --- |
| **AUXCAPS_LRVOLUME** | Supports separate left and right volume control. |
| **AUXCAPS_VOLUME** | Supports volume control. |

If a device supports volume changes, the AUXCAPS_VOLUME flag will be set. If a device supports separate volume changes on the left and right channels, both AUXCAPS_VOLUME and the AUXCAPS_LRVOLUME will be set.

## Remarks

> [!NOTE]
> The mmeapi.h header defines AUXCAPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).