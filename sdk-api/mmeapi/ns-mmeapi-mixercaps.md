# MIXERCAPS structure

## Description

The **MIXERCAPS** structure describes the capabilities of a mixer device.

## Members

### `wMid`

A manufacturer identifier for the mixer device driver. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

A product identifier for the mixer device driver. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vDriverVersion`

Version number of the mixer device driver. The high-order byte is the major version number, and the low-order byte is the minor version number.

### `szPname`

Name of the product. If the mixer device driver supports multiple cards, this string must uniquely and easily identify (potentially to a user) the specific card.

### `fdwSupport`

Various support information for the mixer device driver. No extended support bits are currently defined.

### `cDestinations`

The number of audio line destinations available through the mixer device. All mixer devices must support at least one destination line, so this member cannot be zero. Destination indexes used in the **dwDestination** member of the [MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea) structure range from zero to the value specified in the **cDestinations** member minus one.

## See also

[Audio Mixer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-mixer-structures)

Audio Mixers

[MIXERLINE](https://learn.microsoft.com/windows/desktop/api/mmeapi/ns-mmeapi-mixerlinea)