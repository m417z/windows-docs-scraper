## Description

The **ACX_JACK_GEN_LOCATION** enumeration is used by the [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description) structure to help describe the general location of an audio jack within a system.

## Constants

### `AcxGenLocPrimaryBox`

Indicates that the jack is located on the primary chassis of the system.

### `AcxGenLocInternal`

Indicates that the jack is located inside the primary chassis in the system.

### `AcxGenLocSeparate`

Indicates that the jack is located on a separate chassis from the primary box.

### `AcxGenLocOther`

Indicates that the jack is located somewhere other than the locations defined by this enum.

### `AcxJackGenLocationMaximum`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_GEO_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_geo_location)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)