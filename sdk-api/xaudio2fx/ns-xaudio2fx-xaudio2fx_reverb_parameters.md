# XAUDIO2FX_REVERB_PARAMETERS structure

## Description

Describes parameters for use in the reverb APO.

## Members

### `WetDryMix`

Percentage of the output that will be reverb. Allowable values are from 0 to 100.

### `ReflectionsDelay`

The delay time of the first reflection relative to the direct path. Permitted range is from 0 to 300 milliseconds.

**Note** All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates. See remarks section below for additional information.

### `ReverbDelay`

Delay of reverb relative to the first reflection. Permitted range is from 0 to 85 milliseconds.

**Note** All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates. See remarks section below for additional information.

### `RearDelay`

Delay for the left rear output and right rear output. Permitted range is from 0 to 5 milliseconds.

**Note** All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates. See remarks section below for additional information.

### `SideDelay`

Delay for the left side output and right side output. Permitted range is from 0 to 5 milliseconds.

**Note** This value is supported beginning with Windows 10.

**Note** All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates. See remarks section below for additional information.

### `PositionLeft`

Position of the left input within the simulated space relative to the listener. With *PositionLeft* set to the minimum value, the left input is placed close to the listener. In this position, early reflections are dominant, and the reverb decay is set back in the sound field and reduced in amplitude. With *PositionLeft* set to the maximum value, the left input is placed at a maximum distance from the listener within the simulated room. *PositionLeft* does not affect the reverb decay time (liveness of the room), only the apparent position of the source relative to the listener. Permitted range is from 0 to 30 (no units).

### `PositionRight`

Same as *PositionLeft*, but affecting only the right input. Permitted range is from 0 to 30 (no units).

**Note** PositionRight is ignored in mono-in/mono-out mode.

### `PositionMatrixLeft`

Gives a greater or lesser impression of distance from the source to the listener. Permitted range is from 0 to 30 (no units).

### `PositionMatrixRight`

Gives a greater or lesser impression of distance from the source to the listener. Permitted range is from 0 to 30 (no units).

**Note** *PositionMatrixRight* is ignored in mono-in/mono-out mode.

### `EarlyDiffusion`

Controls the character of the individual wall reflections. Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface. Permitted range is from 0 to 15 (no units).

### `LateDiffusion`

Controls the character of the individual wall reverberations. Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface. Permitted range is from 0 to 15 (no units).

### `LowEQGain`

Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. The values correspond to dB of gain as follows:

|  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
| Gain (dB) | -8 | -7 | -6 | -5 | -4 | -3 | -2 | -1 | 0 | +1 | +2 | +3 | +4 |

**Note** A *LowEQGain* value of 8 results in the decay time of low frequencies being equal to the decay time at 1 kHz.

Permitted range is from 0 to 12 (no units).

### `LowEQCutoff`

Sets the corner frequency of the low pass filter that is controlled by the *LowEQGain* parameter. The values correspond to frequency in Hz as follows:

|  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| Frequency (Hz) | 50 | 100 | 150 | 200 | 250 | 300 | 350 | 400 | 450 | 500 |

Permitted range is from 0 to 9 (no units).

### `HighEQGain`

Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. When set to zero, high frequencies decay at the same rate as 1 kHz. When set to maximum value, high frequencies decay at a much faster rate than 1 kHz.

|  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| Gain (dB) | -8 | -7 | -6 | -5 | -4 | -3 | -2 | -1 | 0 |

Permitted range is from 0 to 8 (no units).

### `HighEQCutoff`

Sets the corner frequency of the high pass filter that is controlled by the *HighEQGain* parameter. The values correspond to frequency in kHz as follows:

|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Value | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
| Frequency (kHz) | 1 | 1.5 | 2 | 2.5 | 3 | 3.5 | 4 | 4.5 | 5 | 5.5 | 6 | 6.5 | 7 | 7.5 | 8 |

Permitted range is from 0 to 14 (no units).

### `RoomFilterFreq`

Sets the corner frequency of the low pass filter for the room effect. Permitted range is from 20 to 20,000 Hz.

**Note** All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates. See remarks section below for additional information.

### `RoomFilterMain`

Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation. Permitted range is from -100 to 0 dB.

### `RoomFilterHF`

Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (*RoomFilterFreq*). Permitted range is from -100 to 0 dB.

### `ReflectionsGain`

Adjusts the intensity of the early reflections. Permitted range is from -100 to 20 dB.

### `ReverbGain`

Adjusts the intensity of the reverberations. Permitted range is from -100 to 20 dB.

### `DecayTime`

Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB. Permitted range is from 0.1 to infinity seconds.

### `Density`

Controls the modal density in the late field reverberation. For colorless spaces, *Density* should be set to the maximum value (100). As Density is decreased, the sound becomes hollow (comb filtered). This is an effect that can be useful if you are trying to model a silo. Permitted range as a percentage is from 0 to 100.

### `RoomSize`

The apparent size of the acoustic space. Permitted range is from 1 to 100 feet.

### `DisableLateField`

If set to TRUE, disables late field reflection calculations. Disabling late field reflection calculations results in a significant CPU time savings.

**Note** The DirectX SDK versions of XAUDIO2 don't support this member.

## Remarks

All parameters related to sampling rate or time are relative to a 48kHz voice and must be scaled for use with other sampling rates. For example, setting *ReflectionsDelay* to 300ms gives a true 300ms delay when the reverb is hosted in a 48kHz voice, but becomes a 150ms delay when hosted in a 24kHz voice.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)

[XAudio2CreateReverb](https://learn.microsoft.com/windows/desktop/api/xaudio2fx/nf-xaudio2fx-xaudio2createreverb)