## Description

The **ACX_JACK_GEO_LOCATION** enumeration is used by the [ACX_JACK_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_description) structure to help describe the geometric location of an audio jack.

## Constants

### `AcxGeoLocRear`

Indicates that the jack is located on the rear of the system.

### `AcxGeoLocFront`

Indicates that the jack is located on the front of the system.

### `AcxGeoLocLeft`

Indicates that the jack is located on the left side of the system.

### `AcxGeoLocRight`

Indicates that the jack is located on the right side of the system.

### `AcxGeoLocTop`

Indicates that the jack is located on the top of the system.

### `AcxGeoLocBottom`

Indicates that the jack is located on the bottom of the system.

### `AcxGeoLocRearPanel`

Indicates that the jack is located on the rear panel of the system.

### `AcxGeoLocRiser`

Indicates that the jack is located on a riser card.

### `AcxGeoLocInsideMobileLid`

Indicates that the jack is located on the inside lid of a mobile computer.

### `AcxGeoLocDrivebay`

Indicates that the jack is located in a drive bay.

### `AcxGeoLocHDMI`

Indicates that the jack is an HDMI connector.

### `AcxGeoLocOutsideMobileLid`

Indicates that the jack is located on the outside lid of a mobile computer.

### `AcxGeoLocATAPI`

Indicates that the jack is located internally, on an ATAPI connector.

### `AcxGeoLocNotApplicable`

Indicates that the jack location is not applicable.

### `AcxGeoLocReserved6`

This value is reserved.

### `AcxJackGeoLocationMaximum`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_JACK_GEN_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_jack_gen_location)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)