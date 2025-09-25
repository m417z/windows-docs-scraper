# IXAPOParameters::SetParameters

## Description

Sets effect-specific parameters.

## Parameters

### `pParameters`

Effect-specific parameter block.

### `ParameterByteSize`

Size of pParameters, in bytes.

## Remarks

The data in *pParameters* is completely effect-specific and determined by the implementation of the **IXAPOParameters::SetParameters** function. The data passed to **SetParameters** can be used to set the state of the XAPO and control the behavior of the [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) function.

**SetParameters** can only be called on the real-time audio processing thread; no synchronization between **SetParameters** and the [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) method is necessary. However, the [IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters) method may be called from any thread as it adds in the required synchronization to deliver a copy (asynchronously) of the parameters to **SetParameters** on the real-time thread; no synchronization between **IXAudio2Voice::SetEffectParameters** and the **IXAPO::Process** method is necessary.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters)

[IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters)