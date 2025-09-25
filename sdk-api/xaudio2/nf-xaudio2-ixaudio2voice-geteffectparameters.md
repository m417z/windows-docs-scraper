# IXAudio2Voice::GetEffectParameters

## Description

Returns the current effect-specific parameters of a given effect in the voice's effect chain.

## Parameters

### `EffectIndex` [in]

Zero-based index of an effect within the voice's effect chain.

### `pParameters` [out]

Returns the current values of the effect-specific parameters.

### `ParametersByteSize` [out]

Size, in bytes, of the pParameters array.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

Fails with E_NOTIMPL if the effect does not support a generic parameter control interface.

## Remarks

**GetEffectParameters** always returns the effect's actual current parameters. However, these may not match the parameters set by the most recent call to [IXAudio2Voice::SetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-seteffectparameters): the actual parameters are only changed the next time the audio engine runs after the **IXAudio2Voice::SetEffectParameters** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetEffectParameters** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAPOParameters::GetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-getparameters)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)