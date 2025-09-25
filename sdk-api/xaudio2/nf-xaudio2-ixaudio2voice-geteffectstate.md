# IXAudio2Voice::GetEffectState

## Description

Returns the running state of the effect at a specified position in the effect chain of the voice.

## Parameters

### `EffectIndex` [in]

Zero-based index of an effect in the effect chain of the voice.

### `pEnabled` [out]

Returns TRUE If the effect is enabled. If the effect is disabled, returns FALSE.

## Return value

This method does not return a value.

## Remarks

**GetEffectState** always returns the effect's actual current state. However, this may not be the state set by the most recent [IXAudio2Voice::EnableEffect](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-enableeffect) or [IXAudio2Voice::DisableEffect](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-disableeffect) call: the actual state is only changed the next time the audio engine runs after the **IXAudio2Voice::EnableEffect** or **IXAudio2Voice::DisableEffect** call (or after the corresponding [IXAudio2::CommitChanges](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-commitchanges) call, if EnableEffect/DisableEffect was called with a deferred operation ID).

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)