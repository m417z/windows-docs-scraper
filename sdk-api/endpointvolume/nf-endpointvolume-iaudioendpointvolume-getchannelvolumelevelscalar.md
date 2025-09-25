# IAudioEndpointVolume::GetChannelVolumeLevelScalar

## Description

The **GetChannelVolumeLevelScalar** method gets the normalized, audio-tapered volume level of the specified channel of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `nChannel` [in]

The channel number. If the audio stream contains *n* channels, the channels are numbered from 0 to *n*– 1. To obtain the number of channels, call the [IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount) method.

### `pfLevel` [out]

Pointer to a **float** variable into which the method writes the volume level. The level is expressed as a normalized value in the range from 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is greater than or equal to the number of channels in the stream. |
| **E_POINTER** | Parameter *pfLevel* is **NULL**. |

## Remarks

The volume level is normalized to the range from 0.0 to 1.0, where 0.0 is the minimum volume level and 1.0 is the maximum level. Within this range, the relationship of the normalized volume level to the attenuation of signal amplitude is described by a nonlinear, audio-tapered curve. Note that the shape of the curve might change in future versions of Windows. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

The normalized volume levels that are retrieved by this method are suitable to represent the positions of volume controls in application windows and on-screen displays.

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount)