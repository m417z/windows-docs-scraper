# IXAPOParameters::GetParameters

## Description

Gets the current values for any effect-specific parameters.

## Parameters

### `pParameters` [in, out]

Receives an effect-specific parameter block.

### `ParameterByteSize` [in]

Size of pParameters, in bytes.

## Remarks

The data in *pParameters* is completely effect-specific and determined by the implementation of the **IXAPOParameters::GetParameters** function. The data returned in *pParameters* can be used to provide information about the current state of the XAPO.

Unlike SetParameters, XAudio2 does not call this method on the realtime audio processing thread. Thus, the XAPO must protect variables shared with [IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters) or [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) using appropriate synchronization. The [CXAPOParametersBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapoparametersbase) class is an implementation of [IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters) and its implementation of **GetParameters** efficiently handles this synchronization for the user.

XAudio2 calls this method from the [IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters) method.

This method may block and should never be called from the realtime audio processing thread instead get the current parameters from [CXAPOParametersBase::BeginProcess](https://learn.microsoft.com/windows/desktop/api/xapobase/nf-xapobase-cxapoparametersbase-beginprocess).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPOParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapoparameters)

[IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters)