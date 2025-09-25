# KSDATARANGE_MUSIC structure

## Description

The KSDATARANGE_MUSIC structure specifies a range of DirectMusic MIDI formats.

## Members

### `DataRange`

Specifies the MajorFormat and SubFormat GUIDs as well as the Specifier GUID for the DirectMusic data. This member is an initialized [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure.

### `Technology`

Specifies the type of MIDI output device. This member can be one of the following GUIDs:

#### KSMUSIC_TECHNOLOGY_PORT

The device is a MIDI hardware port.

#### KSMUSIC_TECHNOLOGY_SYNTH

The device is a synthesizer.

#### KSMUSIC_TECHNOLOGY_SQSYNTH

The device is a square-wave synthesizer.

#### KSMUSIC_TECHNOLOGY_FMSYNTH

The device is an FM synthesizer.

#### KSMUSIC_TECHNOLOGY_MAPPER

The device is the Microsoft MIDI mapper.

#### KSMUSIC_TECHNOLOGY_WAVETABLE

The device is a hardware wavetable synthesizer.

#### KSMUSIC_TECHNOLOGY_SWSYNTH

The device is a software synthesizer.

### `Channels`

Specifies the maximum number of simultaneous channels that can be played by an internal synthesizer device. If the device is a port, this member is not meaningful and is set to zero.

### `Notes`

Specifies the maximum number of simultaneous notes that can be played by an internal synthesizer device. If the device is a port, this member is not meaningful and is set to zero.

### `ChannelMask`

Specifies which channels an internal synthesizer device responds to, where the least significant bit refers to channel 0 and the most significant bit to channel 15. Port devices that transmit on all channels set this member to 0xFFFF.

## Remarks

For examples of data ranges that use the KSDATARANGE_MUSIC structure, see [MIDI Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/midi-stream-data-range) and [DirectMusic Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/directmusic-stream-data-range).

For information about data ranges and intersection handling, see [Data-Intersection Handlers](https://learn.microsoft.com/windows-hardware/drivers/audio/data-intersection-handlers).

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))