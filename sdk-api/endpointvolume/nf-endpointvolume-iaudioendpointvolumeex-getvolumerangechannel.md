# IAudioEndpointVolumeEx::GetVolumeRangeChannel

## Description

The **GetVolumeRangeChannel** method gets the volume range for a specified channel.

## Parameters

### `iChannel` [in]

The channel number for which to get the volume range. If the audio stream has *n* channels, the channels are numbered from 0 to *n*– 1. To obtain the number of channels in the stream, call the [IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount) method.

### `pflVolumeMindB` [out]

Receives the minimum volume level for the channel, in decibels.

### `pflVolumeMaxdB` [out]

Receives the maximum volume level for the channel, in decibels.

### `pflVolumeIncrementdB` [out]

Receives the volume increment for the channel, in decibels.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfLevelMinDB*, *pfLevelMaxDB*, or *pfVolumeIncrementDB* is **NULL**. |

## See also

[IAudioEndpointVolumeEx](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumeex)