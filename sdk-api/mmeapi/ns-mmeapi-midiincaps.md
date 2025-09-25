# MIDIINCAPS structure

## Description

The **MIDIINCAPS** structure describes the capabilities of a MIDI input device.

## Members

### `wMid`

Manufacturer identifier of the device driver for the MIDI input device. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier of the MIDI input device. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vDriverVersion`

Version number of the device driver for the MIDI input device. The high-order byte is the major version number, and the low-order byte is the minor version number.

### `szPname`

Product name in a null-terminated string.

### `dwSupport`

Reserved; must be zero.

## See also

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)