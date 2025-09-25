# X3DAUDIO_DSP_SETTINGS structure

## Description

Receives the results from a call to [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

## Members

### `pMatrixCoefficients`

Caller provided array that will be initialized with the volume level of each source channel present in each destination channel. The array must have at least (**SrcChannelCount** × **DstChannelCount**) elements.
The array is arranged with the source channels as the column index of the array and the destination channels as the row index of the array. For example, when rendering two-channel stereo input into 5.1 output that is weighted toward the front channels—but is absent from the center and low-frequency channels—the matrix might be as shown in the following table.

| Output | Left Input | Right Input |
| --- | --- | --- |
| Left | 1.0 | 0.0 |
| Right | 0.0 | 1.0 |
| Front Center | 0.0 | 0.0 |
| LFE | 0.0 | 0.0 |
| Rear Left | 0.8 | 0.0 |
| Rear Right | 0.0 | 0.8 |

Note that the left and right channels are fully mapped to the output left and right channels; 80 percent of the left and right input is mapped to the rear left and right channels.

The **pMatrixCoefficients** member can be NULL if the X3DAUDIO_CALCULATE_MATRIX flag is not specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

When using X3DAudio with XAudio2 the value returned in the **pMatrixCoefficients** member would be applied to a voice with [IXAudio2Voice::SetOutputMatrix](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputmatrix).

### `pDelayTimes`

Caller provided delay time array, which receives delays for each destination channel in milliseconds. This array must have at least **DstChannelCount** elements. X3DAudio doesn't actually perform the delay. It simply returns the coefficients that may be used to adjust a delay DSP effect placed in the effect chain.
The **pDelayTimes** member can be NULL if the X3DAUDIO_CALCULATE_DELAY flag is not specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

**Note** This member is only returned when X3DAudio is initialized for stereo output. For typical Xbox 360 usage, it will not return any data at all.

### `SrcChannelCount`

Number of source channels. This must be initialized to the number of emitter channels before calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `DstChannelCount`

Number of source channels. This must be initialized to the number of emitter channels before calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `LPFDirectCoefficient`

LPF direct-path coefficient.
Only calculated if the X3DAUDIO_CALCULATE_LPF_DIRECT flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

When using X3DAudio with XAudio2 the value returned in the LPFDirectCoefficient member would be applied to a low pass filter on a source voice with [IXAudio2Voice::SetFilterParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setfilterparameters).

### `LPFReverbCoefficient`

LPF reverb-path coefficient.

Only calculated if the X3DAUDIO_CALCULATE_LPF_REVERB flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `ReverbLevel`

Reverb send level.
Only calculated if the X3DAUDIO_CALCULATE_REVERB flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `DopplerFactor`

Doppler shift factor. Scales the resampler ratio for Doppler shift effect, where:

```
effective_frequency = DopplerFactor × original_frequency
```

Only calculated if the X3DAUDIO_CALCULATE_DOPPLER flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

When using X3DAudio with XAudio2 the value returned in the DopplerFactor would be applied to a source voice with [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio).

### `EmitterToListenerAngle`

Emitter-to-listener interior angle, expressed in radians with respect to the emitter's front orientation.

Only calculated if the X3DAUDIO_CALCULATE_EMITTER_ANGLE flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `EmitterToListenerDistance`

Distance in user-defined world units from the listener to the emitter base position.

### `EmitterVelocityComponent`

Component of emitter velocity vector projected onto emitter-to-listener vector in user-defined world units per second.

Only calculated if the X3DAUDIO_CALCULATE_DOPPLER flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

### `ListenerVelocityComponent`

Component of listener velocity vector projected onto the emitter->listener vector in user-defined world units per second.
Only calculated if the X3DAUDIO_CALCULATE_DOPPLER flag is specified when calling [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate).

## Remarks

The following members must be initialized before passing this structure to the [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate) function:

* **pMatrixCoefficients**
* **pDelayTimes**
* **SrcChannelCount**
* **DstChannelCount**

The following members are returned by passing this structure to the **X3DAudioCalculate** function:

* **pMatrixCoefficients**
* **pDelayTimes**
* **LPFDirectCoefficient**
* **LPFReverbCoefficient**
* **ReverbLevel**
* **DopplerFactor**
* **EmitterToListenerAngle**
* **EmitterToListenerDistance**
* **EmitterVelocityComponent**
* **ListenerVelocityComponent**

**Note** For **pMatrixCoefficients** and **pDelayTimes**, [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate) does not allocate additional memory. **X3DAudioCalculate** merely modifies the values at the memory locations allocated for these pointers.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)