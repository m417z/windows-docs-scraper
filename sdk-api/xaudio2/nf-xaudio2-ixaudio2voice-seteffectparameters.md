# IXAudio2Voice::SetEffectParameters

## Description

Sets parameters for a given effect in the voice's effect chain.

## Parameters

### `EffectIndex` [in]

Zero-based index of an effect within the voice's effect chain.

### `pParameters` [in]

Returns the current values of the effect-specific parameters.

### `ParametersByteSize` [in]

Size of the **pParameters** array in bytes.

### `X2DEFAULT`

TBD

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful; otherwise, an error code. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

Fails with E_NOTIMPL if the effect does not support a generic parameter control interface.

## Remarks

The specific effect being used determines the valid size and format of the *pParameters* buffer. The call will fail if *pParameters* is invalid or if *ParametersByteSize* is not exactly the size that the effect expects. The client must take care to direct the **SetEffectParameters** call to the right effect. If this call is directed to a different effect that happens to accept the same parameter block size, the parameters will be interpreted differently. This may lead to unexpected results.

The memory pointed to by *pParameters* must *not* be freed immediately, because XAudio2 will need to refer to it later when the parameters actually are applied to the effect. This happens during the next audio processing pass if the *OperationSet* argument is **XAUDIO2_COMMIT_NOW**. Otherwise, the parameters are applied to the effect later, during the first processing pass after the [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) function is called with the same *OperationSet* argument.

**SetEffectParameters** takes effect immediately when called from an XAudio2 callback with an *OperationSet* of **XAUDIO2_COMMIT_NOW**.

**Note** [IXAudio2Voice::GetEffectParameters](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-geteffectparameters) always returns the effect's actual current parameters. However, these may not match the parameters set by the most recent call to **IXAudio2Voice::SetEffectParameters**. The actual parameters are only changed the next time the audio engine runs after the **IXAudio2Voice::SetEffectParameters** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if **IXAudio2Voice::SetEffectParameters** was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAPOParameters::SetParameters](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapoparameters-setparameters)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)