# IXAudio2::CreateSourceVoice

## Description

Creates and configures a source voice.

## Parameters

### `ppSourceVoice` [out]

If successful, returns a pointer to the new [IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice) object.

### `pSourceFormat` [in]

Pointer to a one of the structures in the table below. This structure contains the expected format for all audio buffers submitted to the source voice.
XAudio2 supports PCM and ADPCM voice types.

| Format tag | Wave format structure | Size (in bytes) |
| --- | --- | --- |
| WAVE_FORMAT_PCM (0x0001) | [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) | 16 |
| -or- | [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) | 18 |
| WAVE_FORMAT_IEEE_FLOAT (0x0003) [32-bit] | [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) | 18 |
| WAVE_FORMAT_ADPCM (0x0002) [MS-ADPCM] | [ADPCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) | 50 |
| WAVE_FORMAT_EXTENSIBLE (0xFFFE) | [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ksmedia/ns-ksmedia-waveformatextensible) | 40 |

XAudio2 supports the following PCM formats.

* 8-bit (unsigned) integer PCM
* 16-bit integer PCM (optimal format for XAudio2)
* 20-bit integer PCM (either in 24 or 32 bit containers)
* 24-bit integer PCM (either in 24 or 32 bit containers)
* 32-bit integer PCM
* 32-bit float PCM (preferred format after 16-bit integer)

The number of channels in a source voice must be less than or equal to XAUDIO2_MAX_AUDIO_CHANNELS. The sample rate of a source voice must be between XAUDIO2_MIN_SAMPLE_RATE and XAUDIO2_MAX_SAMPLE_RATE.

**Note** PCM data formats such as [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) and **ADPCMWAVEFORMAT** that require more information than provided by **WAVEFORMATEX** have a **WAVEFORMATEX** structure as the first member in their format structures. When you create a source voice with one of those formats, cast the format's structure as a **WAVEFORMATEX** structure and use it as the value for *pSourceFormat*.

### `X2DEFAULT`

TBD

### `Flags` [in]

Flags that specify the behavior of the source voice. A flag can be 0 or a combination of one or more of the following:

| Value | Description |
| --- | --- |
| XAUDIO2_VOICE_NOPITCH | No pitch control is available on the voice. |
| XAUDIO2_VOICE_NOSRC | No sample rate conversion is available on the voice. The voice's outputs must have the same sample rate.<br><br>**Note** The XAUDIO2_VOICE_NOSRC flag causes the voice to behave as though the XAUDIO2_VOICE_NOPITCH flag also is specified. |
| XAUDIO2_VOICE_USEFILTER | The filter effect should be available on this voice. |

**Note** The XAUDIO2_VOICE_MUSIC flag is not supported on Windows.

### `MaxFrequencyRatio` [in]

Highest allowable frequency ratio that can be set on this voice. The value for this argument must be between XAUDIO2_MIN_FREQ_RATIO and XAUDIO2_MAX_FREQ_RATIO. Subsequent calls to [IXAudio2SourceVoice::SetFrequencyRatio](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setfrequencyratio) are clamped between XAUDIO2_MIN_FREQ_RATIO and **MaxFrequencyRatio**.
The maximum value for this argument is defined as XAUDIO2_MAX_FREQ_RATIO, which allows pitch to be raised by up to 10 octaves.

If *MaxFrequencyRatio* is less than 1.0, the voice will use that ratio immediately after being created (rather than the default of 1.0).

| Xbox 360 |
| --- |
| For XMA voices, there is one more restriction on the *MaxFrequencyRatio* argument and the voice's sample rate. The product of these two numbers cannot exceed XAUDIO2_MAX_RATIO_TIMES_RATE_XMA_MONO for one-channel voices or XAUDIO2_MAX_RATIO_TIMES_RATE_XMA_MULTICHANNEL for voices with any other number of channels. If the value specified for *MaxFrequencyRatio* is too high for the specified format, the call to **CreateSourceVoice** fails and produces a debug message. |

**Note** You can use the lowest possible *MaxFrequencyRatio* value to reduce XAudio2's memory usage.

### `pCallback` [in, optional]

Pointer to a client-provided callback interface, [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback).

### `pEffectChain` [in, optional]

Pointer to a list of [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) structures that describe an effect chain to use in the source voice.

### `pSendList` [in, out]

Pointer to a list of [XAUDIO2_VOICE_SENDS](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_voice_sends) structures that describe the set of destination voices for the source voice. If pSendList is NULL, the send list defaults to a single output to the first mastering voice created.

## Return value

Returns S_OK if successful; otherwise, an error code.

See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2-specific error codes.

## Remarks

Source voices read audio data from the client. They process the data and send it to the XAudio2 processing graph.

A source voice includes a variable-rate sample rate conversion, to convert data from the source format sample rate to the output rate required for the voice send list. If you use a NULL send list, the target sample rate will be the mastering voice's input sample rate. If you provide a single voice in pSendList, that voice's input sample rate is the target rate. If you provide multiple voices in the pSendList, all the source voice's output voices must be running at the same input sample rate.

You cannot create any source or submix voices until a mastering voice exists, and you cannot destroy a mastering voice if any source or submix voices still exist.

Source voices are always processed before any submix or mastering voices. This means that you do not need a ProcessingStage parameter to control the processing order.

When first created, source voices are in the stopped state.

XAudio2 uses an internal memory pooler for voices with the same format. This means memory allocation for voices will occur less frequently as more voices are created and then destroyed. To minimize just-in-time allocations, a title can create the anticipated maximum number of voices needed up front, and then delete them as necessary. Voices will then be reused from the XAudio2 pool. The memory pool is tied to an XAudio2 engine instance. You can reclaim all the memory used by an instance of the XAudio2 engine by destroying the XAudio2 object and recreating it as necessary (forcing the memory pool to grow via preallocation would have to be reapplied as needed).

It is invalid to call **CreateSourceVoice** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If you call **CreateSourceVoice** within a callback, it returns XAUDIO2_E_INVALID_CALL.

The [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) that is passed in as the pEffectChain argument and any [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) information contained within it are no longer needed after **CreateSourceVoice** successfully completes, and may be deleted immediately after **CreateSourceVoice** is called.

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio2 Sample Rate Conversions](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-sample-rate-conversions)