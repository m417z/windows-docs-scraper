# IXAudio2Voice::SetOutputMatrix

## Description

Sets the volume level of each channel of the final output for the voice. These channels are mapped to the input channels of a specified destination voice.

## Parameters

### `pDestinationVoice` [in]

Pointer to a destination [IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice) for which to set volume levels.

**Note** If the voice sends to a single target voice then specifying NULL will cause **SetOutputMatrix** to operate on that target voice.

### `SourceChannels` [in]

Confirms the output channel count of the voice. This is the number of channels that are produced by the last effect in the chain.

### `DestinationChannels` [in]

Confirms the input channel count of the destination voice.

### `pLevelMatrix` [in]

Array of [*SourceChannels* × *DestinationChannels*] volume levels sent to the destination voice. The level sent from source channel *S* to destination channel *D* is specified in the form *pLevelMatrix*[*SourceChannels* × *D* + *S*].

For example, when rendering two-channel stereo input into 5.1 output that is weighted toward the front channels—but is absent from the center and low-frequency channels—the matrix might have the values shown in the following table.

| Output | Left Input [Array Index] | Right Input [Array Index] |
| --- | --- | --- |
| Left | 1.0 [0] | 0.0 [1] |
| Right | 0.0 [2] | 1.0 [3] |
| Front Center | 0.0 [4] | 0.0 [5] |
| LFE | 0.0 [6] | 0.0 [7] |
| Rear Left | 0.8 [8] | 0.0 [9] |
| Rear Right | 0.0 [10] | 0.8 [11] |

**Note** The left and right input are fully mapped to the output left and right channels; 80 percent of the left and right input is mapped to the rear left and right channels.

See Remarks for more information on volume levels.

### `X2DEFAULT`

TBD

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

## Remarks

This method is valid only for source and submix voices, because mastering voices write directly to the device with no matrix mixing.

Volume levels are expressed as floating-point amplitude multipliers between -XAUDIO2_MAX_VOLUME_LEVEL and XAUDIO2_MAX_VOLUME_LEVEL (-2²⁴ to 2²⁴), with a maximum gain of 144.5 dB. A volume level of 1.0 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase. See [XAudio2 Volume and Pitch Control](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-volume-and-pitch-control) for additional information on volume control.

The [X3DAudio](https://learn.microsoft.com/windows/desktop/xaudio2/x3daudio-overview) function [X3DAudioCalculate](https://learn.microsoft.com/windows/desktop/api/x3daudio/nf-x3daudio-x3daudiocalculate) can produce an output matrix for use with **SetOutputMatrix** based on a sound's position and a listener's position.

**Note** [IXAudio2Voice::GetOutputMatrix](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-getoutputmatrix) always returns the levels most recently set by **IXAudio2Voice::SetOutputMatrix**. However, they may not actually be in effect yet: they only take effect the next time the audio engine runs after the **IXAudio2Voice::SetOutputMatrix** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetOutputMatrix** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Change Voice Volume](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--change-voice-volume)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)