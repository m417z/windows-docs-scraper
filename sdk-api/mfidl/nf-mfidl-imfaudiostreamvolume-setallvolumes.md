# IMFAudioStreamVolume::SetAllVolumes

## Description

Sets the individual volume levels for all of the channels in the audio stream.

## Parameters

### `dwCount` [in]

Number of elements in the *pfVolumes* array. The value must equal the number of channels. To get the number of channels, call [IMFAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfaudiostreamvolume-getchannelcount).

### `pfVolumes` [in]

Address of an array of size *dwCount*, allocated by the caller. The array specifies the volume levels for all of the channels. Before calling the method, set each element of the array to the desired volume level for the channel.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiostreamvolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)