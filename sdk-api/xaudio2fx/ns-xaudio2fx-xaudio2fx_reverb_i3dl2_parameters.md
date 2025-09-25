# XAUDIO2FX_REVERB_I3DL2_PARAMETERS structure

## Description

Describes I3DL2 (Interactive 3D Audio Rendering Guidelines Level 2.0) parameters for use in the [ReverbConvertI3DL2ToNative](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/nf-xaudio2fx-reverbconverti3dl2tonative) function.

## Members

### `WetDryMix`

Percentage of the output that will be reverb. Allowable values are from 0 to 100.

### `Room`

Attenuation of the room effect. Allowable values in hundredths of a decibel are from -10000 to 0.

### `RoomHF`

Attenuation of the room high-frequency effect. Allowable values in hundredths of a decibel are from -10000 to 0.

### `RoomRolloffFactor`

Rolloff factor for the reflected signals. Allowable values are from 0.0 to 10.0. Rolloff factor is ignored for built-in reverb effects.

### `DecayTime`

Reverberation decay time at low frequencies. Allowable values in seconds are from 0.1 to 20.0.

### `DecayHFRatio`

Ratio of the decay time at high frequencies to the decay time at low frequencies. Allowable values are from 0.1 to 2.0.

### `Reflections`

Attenuation of early reflections relative to **Room**. Allowable values in hundredths of a decibel are from -10000 to 1000.

### `ReflectionsDelay`

Delay time of the first reflection relative to the direct path. Allowable values in seconds are from 0.0 to 0.3.

### `Reverb`

Attenuation of late reverberation relative to **Room**. Allowable values in hundredths of a decibel are from -10000 to 2000.

### `ReverbDelay`

Time limit between the early reflections and the late reverberation relative to the time of the first reflection. Allowable values in seconds are from 0.0 to 0.1.

### `Diffusion`

Echo density in the late reverberation decay. Allowable values as a percentage are from 0 to 100.

### `Density`

Modal density in the late reverberation decay. Allowable values as a percentage are from 0 to 100.

### `HFReference`

Reference high frequency. Allowable values in Hz are from 20.0 to 20000.0.

## Remarks

There are many preset values defined for the **XAUDIO2FX_REVERB_I3DL2_PARAMETERS** structure. For more information, see [XAUDIO2FX_I3DL2_PRESET](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2fx-i3dl2-preset).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[ReverbConvertI3DL2ToNative](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/nf-xaudio2fx-reverbconverti3dl2tonative)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAUDIO2FX_I3DL2_PRESET](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2fx-i3dl2-preset)

[XAudio Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)