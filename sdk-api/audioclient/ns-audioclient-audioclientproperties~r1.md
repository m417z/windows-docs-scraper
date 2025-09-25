# AudioClientProperties structure

## Description

The **AudioClientProperties** structure is used to set the parameters that describe the properties of the client's audio stream.

## Members

### `cbSize`

The size of the **AudioClientProperties** structure, in bytes.

### `bIsOffload`

Boolean value to indicate whether or not the audio stream is hardware-offloaded.

### `eCategory`

An enumeration that is used to specify the category of the audio stream.

### - Options

A member of the [AUDCLNT_STREAMOPTIONS](https://learn.microsoft.com/windows/desktop/api/audioclient/ne-audioclient-audclnt_streamoptions) enumeration describing the characteristics of the stream.

Supported in Windows 8.1 and later.

## Remarks

Starting with Windows 10, hardware-offloaded audio streams must be event driven. This means that if you call [IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties) and set the *bIsOffload* parameter of the **AudioClientProperties** to TRUE, you must specify the **AUDCLNT_STREAMFLAGS_EVENTCALLBACK** flag in the *StreamFlags* parameter to [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize).

## See also

[AUDCLNT_STREAMOPTIONS](https://learn.microsoft.com/windows/desktop/api/audioclient/ne-audioclient-audclnt_streamoptions)

[AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category)

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IAudioClient2::SetClientProperties](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient2-setclientproperties)