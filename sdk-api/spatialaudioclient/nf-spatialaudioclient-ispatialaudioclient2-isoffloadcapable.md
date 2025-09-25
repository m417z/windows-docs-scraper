## Description

Queries whether the audio rendering endpoint that the [ISpatialAudioClient2](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient2) was created on supports hardware offloaded audio processing. The method also considers the capabilities of the [AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category) value that will be used, as use of offload is restricted to only certain **AUDIO_STREAM_CATEGORY** values.

## Parameters

### `category` [in]

A value from the [AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category) enumeration specifying the category of audio for which offload support is queried.

### `isOffloadCapable` [out]

Receives a boolean value indicating if offloaded audio processing is supported by the audio rendering endpoint.

## Return value

An HRESULT including the following values.

| Value | Description |
|-------|-------------|
| S_OK | Success |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio device associated with the audio client has been invalidated. |
| E_INVALIDARG | The value supplied in the *category* parameter is not valid. |

## Remarks

## See also