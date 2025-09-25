# IAudioEndpointVolume::GetChannelVolumeLevel

## Description

The **GetChannelVolumeLevel** method gets the volume level, in decibels, of the specified channel in the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `nChannel` [in]

The channel number. If the audio stream has *n* channels, the channels are numbered from 0 to *n*– 1. To obtain the number of channels in the stream, call the [IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount) method.

### `pfLevelDB` [out]

Pointer to a **float** variable into which the method writes the volume level in decibels. To get the range of volume levels obtained from this method, call the [IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange) method.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is greater than or equal to the number of channels in the stream. |
| **E_POINTER** | Parameter *pfLevelDB* is **NULL**. |

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount)

[IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange)