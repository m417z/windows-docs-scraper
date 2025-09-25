# IXAudio2::CreateSubmixVoice

## Description

Creates and configures a submix voice.

## Parameters

### `ppSubmixVoice` [out]

On success, returns a pointer to the new [IXAudio2SubmixVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2submixvoice) object.

### `InputChannels` [in]

Number of channels in the input audio data of the submix voice.
*InputChannels* must be less than or equal to XAUDIO2_MAX_AUDIO_CHANNELS.

### `InputSampleRate` [in]

Sample rate of the input audio data of submix voice. This rate must be a multiple of XAUDIO2_QUANTUM_DENOMINATOR. *InputSampleRate* must be between XAUDIO2_MIN_SAMPLE_RATE and XAUDIO2_MAX_SAMPLE_RATE.

### `X2DEFAULT`

TBD

### `Flags` [in]

Flags that specify the behavior of the submix voice. It can be 0 or the following:

| Value | Description |
| --- | --- |
| XAUDIO2_VOICE_USEFILTER | The filter effect should be available on this voice. |

### `ProcessingStage` [in]

An arbitrary number that specifies when this voice is processed with respect to other submix voices, if the XAudio2 engine is running other submix voices. The voice is processed after all other voices that include a smaller *ProcessingStage* value and before all other voices that include a larger *ProcessingStage* value. Voices that include the same *ProcessingStage* value are processed in any order. A submix voice cannot send to another submix voice with a lower or equal *ProcessingStage* value. This prevents audio being lost due to a submix cycle.

### `pEffectChain` [in, optional]

Pointer to a list of [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) structures that describe an effect chain to use in the submix voice.

### `pSendList` [in, optional]

Pointer to a list of [XAUDIO2_VOICE_SENDS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_voice_sends) structures that describe the set of destination voices for the submix voice. If *pSendList* is NULL, the send list will default to a single output to the first mastering voice created.

## Return value

Returns S_OK if successful; otherwise, an error code.

See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

Submix voices receive the output of one or more source or submix voices. They process the output, and then send it to another submix voice or to a mastering voice.

A submix voice performs a sample rate conversion from the input sample rate to the input rate of its output voices in *pSendList*. If you specify multiple voice sends, they must all have the input same sample rate.

You cannot create any source or submix voices until a mastering voice exists, and you cannot destroy a mastering voice if any source or submix voices still exist.

When first created, submix voices are in the started state.

XAudio2 uses an internal memory pooler for voices with the same format. This means that memory allocation for voices will occur less frequently as more voices are created and then destroyed. To minimize just-in-time allocations, a title can create the anticipated maximum number of voices needed up front, and then delete them as necessary. Voices will then be reused from the XAudio2 pool. The memory pool is tied to an XAudio2 engine instance. You can reclaim all the memory used by an instance of the XAudio2 engine by destroying the XAudio2 object and recreating it as necessary (forcing the memory pool to grow via preallocation would have to be reapplied as needed).

It is invalid to call **CreateSubmixVoice** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If you call **CreateSubmixVoice** within a callback, it returns XAUDIO2_E_INVALID_CALL.

The [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) that is passed in as the *pEffectChain* argument and any [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) information contained within it are no longer needed after **CreateSubmixVoice** successfully completes, and may be deleted immediately after **CreateSubmixVoice** is called.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)

[XAudio2 Sample Rate Conversions](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-sample-rate-conversions)