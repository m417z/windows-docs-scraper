# IAudioClient2::IsOffloadCapable

## Description

The **IsOffloadCapable** method retrieves information about whether or not the endpoint on which a stream is created is capable of supporting an offloaded audio stream.

## Parameters

### `Category` [in]

An enumeration that specifies the category of an audio stream.

### `pbOffloadCapable` [out]

A pointer to a Boolean value. **TRUE** indicates that the endpoint is offload-capable. **FALSE** indicates that the endpoint is not offload-capable.

## Return value

The **IsOffloadCapable** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[AUDIO_STREAM_CATEGORY](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audio_stream_category)

[IAudioClient2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient2)