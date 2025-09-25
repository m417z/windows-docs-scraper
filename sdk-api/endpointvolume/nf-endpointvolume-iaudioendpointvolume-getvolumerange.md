# IAudioEndpointVolume::GetVolumeRange

## Description

The **GetVolumeRange** method gets the volume range, in decibels, of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `pflVolumeMindB` [out]

Pointer to the minimum volume level. This parameter points to a **float** variable into which the method writes the minimum volume level in decibels. This value remains constant for the lifetime of the [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) interface instance.

### `pflVolumeMaxdB` [out]

Pointer to the maximum volume level. This parameter points to a **float** variable into which the method writes the maximum volume level in decibels. This value remains constant for the lifetime of the **IAudioEndpointVolume** interface instance.

### `pflVolumeIncrementdB` [out]

Pointer to the volume increment. This parameter points to a **float** variable into which the method writes the volume increment in decibels. This increment remains constant for the lifetime of the **IAudioEndpointVolume** interface instance.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfLevelMinDB*, *pfLevelMaxDB*, or *pfVolumeIncrementDB* is **NULL**. |

## Remarks

The volume range from vmin = **pfLevelMinDB* to vmax = **pfLevelMaxDB* is divided into *n* uniform intervals of size vinc = **pfVolumeIncrementDB*, where

n = (vmax – vmin) / vinc.

The values vmin, vmax, and vinc are measured in decibels. The client can set the volume level to one of n + 1 discrete values in the range from vmin to vmax.

The [IAudioEndpointVolume::SetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevel) and [IAudioEndpointVolume::SetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevel) methods accept only volume levels in the range from vmin to vmax. If the caller specifies a volume level outside of this range, the method fails and returns E_INVALIDARG. If the caller specifies a volume level that falls between two steps in the volume range, the method sets the endpoint volume level to the step that lies closest to the requested volume level and returns S_OK. However, a subsequent call to [IAudioEndpointVolume::GetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelvolumelevel) or [IAudioEndpointVolume::GetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getmastervolumelevel) retrieves the volume level requested by the previous call to **SetChannelVolumeLevel** or **SetMasterVolumeLevel**, not the step value.

If the volume control is implemented in hardware, **GetVolumeRange** describes the range and granularity of the hardware volume settings. In contrast, the steps that are reported by the [IEndpointVolume::GetVolumeStepInfo](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumestepinfo) method correspond to points on an audio-tapered curve that are calculated in software by the [IEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown) and [IEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup) methods. Either method first calculates the idealized volume level that corresponds to the next point on the curve. Next, the method selects the hardware volume setting that is the best approximation to the idealized level. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelvolumelevel)

[IAudioEndpointVolume::GetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getmastervolumelevel)

[IAudioEndpointVolume::SetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevel)

[IAudioEndpointVolume::SetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevel)

[IEndpointVolume::GetVolumeStepInfo](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumestepinfo)

[IEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown)

[IEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup)