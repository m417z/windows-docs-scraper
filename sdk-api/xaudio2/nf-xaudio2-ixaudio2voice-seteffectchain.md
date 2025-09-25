# IXAudio2Voice::SetEffectChain

## Description

Replaces the effect chain of the voice.

## Parameters

### `pEffectChain` [in, optional]

Pointer to an [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) structure that describes the new effect chain to use. If NULL is passed, the current effect chain is removed.

**Note** If *pEffectChain* is non-NULL, the [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) structure that it points to must specify at least one effect.

## Return value

Returns S_OK if successful; otherwise, an error code.

See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

The number of output channels allowed for a voice's effect chain is locked at creation of the voice. If you create the voice with an effect chain, any new effect chain passed to **SetEffectChain** must have the same number of input and output channels as the original effect chain. If you create the voice without an effect chain, the number of output channels allowed for the effect chain will default to the number of input channels for the voice. If any part of effect chain creation fails, none of it is applied.

After you attach an effect to an XAudio2 voice, XAudio2 takes control of the effect, and the client should not make any further calls to it. The simplest way to ensure this is to release all pointers to the effect.

It is invalid to call **SetEffectChain** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If you call **SetEffectChain** within a callback, it returns XAUDIO2_E_INVALID_CALL.

The [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) that is passed in as the pEffectChain argument and any [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) information contained within it are no longer needed after **SetEffectChain** successfully completes, and may be deleted immediately after **SetEffectChain** is called.

### Platform Requirements

Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Create an Effect Chain](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--create-an-effect-chain)

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)