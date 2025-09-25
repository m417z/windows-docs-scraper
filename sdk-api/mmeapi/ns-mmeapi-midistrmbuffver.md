# MIDISTRMBUFFVER structure

## Description

The **MIDISTRMBUFFVER** structure contains version information for a long MIDI event of the MEVT_VERSION type.

## Members

### `dwVersion`

Version of the stream. The high 16 bits contain the major version, and the low 16 bits contain the minor version. The version number for the first implementation of MIDI streams should be 1.0.

### `dwMid`

Manufacturer identifier. Manufacturer identifiers are defined in Manufacturer and Product Identifiers.

### `dwOEMVersion`

OEM version of the stream. Original equipment manufacturers can use this field to version-stamp any custom events they have specified. If a custom event is specified, it must be the first event sent after the stream is opened.

## See also

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)