# IXAudio2Voice::SetOutputVoices

## Description

Designates a new set of submix or mastering voices to receive the output of the voice.

## Parameters

### `pSendList` [in]

Array of [XAUDIO2_VOICE_SENDS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_voice_sends) structure pointers to destination voices. If *pSendList* is NULL, the voice will send its output to the current mastering voice. To set the voice to not send its output anywhere set the **OutputCount** member of **XAUDIO2_VOICE_SENDS** to 0. All of the voices in a send list must have the same input sample rate, see [XAudio2 Sample Rate Conversions](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-sample-rate-conversions) for additional information.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

This method is only valid for source and submix voices. Mastering voices can not send audio to another voice.

After calling **SetOutputVoices** a voice's current send levels will be replaced by a default send matrix. The [IXAudio2Voice::SetOutputMatrix](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputmatrix) method must be called to set a custom matrix for the new sendlist.

It is invalid to call **SetOutputVoices** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If **SetOutputVoices** is called within a callback, it returns XAUDIO2_E_INVALID_CALL.

**Note** Calling **SetOutputVoices** invalidates any send matrices previously set with [IXAudio2Voice::SetOutputMatrix](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voice-setoutputmatrix).

### Platform Requirements

Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2Voice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voice)