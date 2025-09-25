# IXAudio2::CreateMasteringVoice

## Description

Creates and configures a mastering voice.

## Parameters

### `ppMasteringVoice` [out]

 If successful, returns a pointer to the new [IXAudio2MasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2masteringvoice) object.

### `X2DEFAULT`

TBD

### `Flags` [in]

 Flags that specify the behavior of the mastering voice. This can be 0 or ``XAUDIO2_NO_VIRTUAL_AUDIO_CLIENT``.

### `InputChannels` [in]

Number of channels the mastering voice expects in its input audio.
*InputChannels* must be less than or equal to XAUDIO2_MAX_AUDIO_CHANNELS.

You can set *InputChannels* to XAUDIO2_DEFAULT_CHANNELS, which causes XAudio2 to try to detect the system speaker configuration setup.

### `InputSampleRate` [in]

Sample rate of the input audio data of the mastering voice. This rate must be a multiple of XAUDIO2_QUANTUM_DENOMINATOR.
*InputSampleRate* must be between XAUDIO2_MIN_SAMPLE_RATE and XAUDIO2_MAX_SAMPLE_RATE.

You can set *InputSampleRate* to XAUDIO2_DEFAULT_SAMPLERATE, with the default being determined by the current platform.

Windows XP defaults to 44100.

Windows Vista and Windows 7 default to the setting specified in the Sound Control Panel. The default for this setting is 44100 (or 48000 if required by the driver).

Flags

### `StreamCategory` [in, optional]

The audio stream category to use for this mastering voice.

### `pEffectChain` [in, optional]

Pointer to an [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) structure that describes an effect chain to use in the mastering voice, or NULL to use no effects.

### `szDeviceId` [in]

Identifier of the device to receive the output audio. Specifying the default value of NULL causes XAudio2 to select the global default audio device. On Windows 10 or later, NULL will also opt-in to the WASAPI virtualized client unless `XAUDIO2_NO_VIRTUAL_AUDIO_CLIENT` is passed in Flags.

## Return value

Returns S_OK if successful; otherwise, an error code. Returns ERROR_NOT_FOUND if no default audio device exists and NULL is passed in as the szDeviceId parameter.

See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

Mastering voices receive the output of one or more source or submix voices. They process the data, and send it to the audio output device.

Typically, you should create a mastering voice with an input sample rate that will be used by the majority of the title's audio content. The mastering voice performs a sample rate conversion from this input sample rate to the actual device output rate.

You cannot create a source or submix voices until a mastering voice exists. You cannot destroy a mastering voice if any source or submix voices still exist.

Mastering voices are always processed after all source and submix voices. This means that you need not specify a *ProcessingStage* parameter to control the processing order.

XAudio2 only allows one mastering voice to exist at once. If you attempt to create more than one voice, XAUDIO2_E_INVALID_CALL is returned. If an additional mastering voice is needed, for example for an output device with a different audio category set, you will need to create an additional XAudio2 instance.

When first created, mastering voices are in the started state.

It is invalid to call **CreateMasteringVoice** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If you call **CreateMasteringVoice** within a callback, it returns XAUDIO2_E_INVALID_CALL.

The [XAUDIO2_EFFECT_CHAIN](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_chain) that is passed in as the pEffectChain argument and any [XAUDIO2_EFFECT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_effect_descriptor) information contained within it are no longer needed after **CreateMasteringVoice** successfully completes, and may be deleted immediately after **CreateMasteringVoice** is called.

Note that the DirectX SDK XAUDIO2 version of **CreateMasteringVoice** took a DeviceIndex argument instead of a szDeviceId and a StreamCategory argument. This reflects the changes needed for the standard Windows device enumeration model.

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)

[XAudio2 Sample Rate Conversions](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-sample-rate-conversions)