## Description

The **ACX_JACK_CONFIG_FLAGS** enumeration is used to describe the properties of a physical jack to an audio class extension (ACX).

## Constants

### `AcxJackConfigNoFlags`

Indicates that there are no flags set.

### `AcxJackConfigJackDetection`

Indicates if the audio hardware can detect whether a device is plugged in.

### `AcxJackConfigValidFlags`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)