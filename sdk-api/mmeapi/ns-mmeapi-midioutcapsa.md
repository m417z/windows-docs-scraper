# MIDIOUTCAPSA structure

## Description

The **MIDIOUTCAPS** structure describes the capabilities of a MIDI output device.

## Members

### `wMid`

Manufacturer identifier of the device driver for the MIDI output device. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier of the MIDI output device. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vDriverVersion`

Version number of the device driver for the MIDI output device. The high-order byte is the major version number, and the low-order byte is the minor version number.

### `szPname`

Product name in a null-terminated string.

### `wTechnology`

Type of the MIDI output device. This value can be one of the following:

| Name | Description |
| --- | --- |
| **MOD_MIDIPORT** | MIDI hardware port. |
| **MOD_SYNTH** | Synthesizer. |
| **MOD_SQSYNTH** | Square wave synthesizer. |
| **MOD_FMSYNTH** | FM synthesizer. |
| **MOD_MAPPER** | Microsoft MIDI mapper. |
| **MOD_WAVETABLE** | Hardware wavetable synthesizer. |
| **MOD_SWSYNTH** | Software synthesizer. |

### `wVoices`

Number of voices supported by an internal synthesizer device. If the device is a port, this member is not meaningful and is set to 0.

### `wNotes`

Maximum number of simultaneous notes that can be played by an internal synthesizer device. If the device is a port, this member is not meaningful and is set to 0.

### `wChannelMask`

Channels that an internal synthesizer device responds to, where the least significant bit refers to channel 0 and the most significant bit to channel 15. Port devices that transmit on all channels set this member to 0xFFFF.

### `dwSupport`

Optional functionality supported by the device. It can be one or more of the following:

| Name | Description |
| --- | --- |
| **MIDICAPS_CACHE** | Supports patch caching. |
| **MIDICAPS_LRVOLUME** | Supports separate left and right volume control. |
| **MIDICAPS_STREAM** | Provides direct support for the [midiStreamOut](https://learn.microsoft.com/previous-versions/dd798487(v=vs.85)) function. |
| **MIDICAPS_VOLUME** | Supports volume control. |

If a device supports volume changes, the MIDICAPS_VOLUME flag will be set for the dwSupport member. If a device supports separate volume changes on the left and right channels, both the MIDICAPS_VOLUME and the MIDICAPS_LRVOLUME flags will be set for this member.

## See also

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)

[midiStreamOut](https://learn.microsoft.com/previous-versions/dd798487(v=vs.85))

## Remarks

> [!NOTE]
> The mmeapi.h header defines MIDIOUTCAPS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).