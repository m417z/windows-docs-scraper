## Description

Gets the maximum supported frame count per processing pass.

## Parameters

### `category` [in]

The \<xref:NE:audiosessiontypes._AUDIO_STREAM_CATEGORY> of the audio stream for which support is queried.

### `offloadEnabled` [in]

A boolean value specifying whether the returned frame count should be calculated with audio offload support considered. If this flag is set to true, the returned frame count is what it would be if the stream is activated for offload mode. However, if this flag is set to true but the audio endpoint does not support offload mode, then the flag has no effect. Use [ISpatialAudioClient2::IsOffloadCapable](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient2-isoffloadcapable) to check if offload mode is supported.

### `objectFormat` [in]

A pointer to a \<xref:NS:mmeapi.tWAVEFORMATEX> structure specifying the format of the audio stream for which support is queried.

### `frameCountPerBuffer` [out]

Receives a pointer to an **INT32** indicating the maximum supported frame count for the audio device and the specified input parameters.

## Return value

An HRESULT including the following values.

| Value | Description |
|-------|-------------|
| S_OK | Success |
| AUDCLNT_E_DEVICE_INVALIDATED | The audio device associated with the audio client has been invalidated. |

## Remarks

The value returned by this method can be used to allocate source buffer. This value will change if the endpoint cadence changes. The caller must specify same [AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category) and [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-waveformatex) values that will be used when creating the stream. The *offloadEnabled* parameter must be set to TRUE if the stream will be created with the [SPATIAL_AUDIO_STREAM_OPTIONS_OFFLOAD](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/ne-spatialaudioclient-spatial_audio_stream_options) flag.

## See also