# IMFAudioStreamVolume::GetChannelVolume

## Description

Retrieves the volume level for a specified channel in the audio stream.

## Parameters

### `dwIndex` [in]

Zero-based index of the audio channel. To get the number of channels, call [IMFAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfaudiostreamvolume-getchannelcount).

### `pfLevel` [out]

Receives the volume level for the channel.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiostreamvolume)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)