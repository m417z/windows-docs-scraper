# IXAudio2Voice::EnableEffect

## Description

Enables the effect at a given position in the effect chain of the voice.

## Parameters

### `EffectIndex` [in]

Zero-based index of an effect in the effect chain of the voice.

### `X2DEFAULT`

TBD

### `OperationSet` [in]

Identifies this call as part of a deferred batch. See the [XAudio2 Operation Sets](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-operation-sets) overview for more information.

## Return value

Returns S_OK if successful; otherwise, an error code. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of error codes.

## Remarks

Be careful when you enable an effect while the voice that hosts it is running. Such an action can result in a problem if the effect significantly changes the audio's pitch or volume.

The effects in a given XAudio2 voice's effect chain must consume and produce audio at that voice's processing sample rate. The only aspect of the audio format they can change is the channel count. For example a reverb effect can convert mono data to 5.1. The client can use the [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) structure's **OutputChannels** field to specify the number of channels it wants each effect to produce. Each effect in an effect chain must produce a number of channels that the next effect can consume. Any calls to **IXAudio2Voice::EnableEffect** or [IXAudio2Voice::DisableEffect](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-disableeffect) that would make the effect chain stop fulfilling these requirements will fail.

**EnableEffect** takes effect immediately when you call it from an XAudio2 callback with an *OperationSet* of **XAUDIO2_COMMIT_NOW**.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)