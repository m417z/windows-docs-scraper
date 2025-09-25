# IMFAudioStreamVolume::GetAllVolumes

## Description

Retrieves the volume levels for all of the channels in the audio stream.

## Parameters

### `dwCount` [in]

Number of elements in the *pfVolumes* array. The value must equal the number of channels. To get the number of channels, call [IMFAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfaudiostreamvolume-getchannelcount).

### `pfVolumes` [out]

Address of an array of size *dwCount*, allocated by the caller. The method fills the array with the volume level for each channel in the stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiostreamvolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)