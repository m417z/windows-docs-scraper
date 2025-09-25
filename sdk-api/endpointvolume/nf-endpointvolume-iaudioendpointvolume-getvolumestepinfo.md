# IAudioEndpointVolume::GetVolumeStepInfo

## Description

The **GetVolumeStepInfo** method gets information about the current step in the volume range.

## Parameters

### `pnStep` [out]

Pointer to a **UINT** variable into which the method writes the current step index. This index is a value in the range from 0 to **pStepCount*– 1, where 0 represents the minimum volume level and **pStepCount*– 1 represents the maximum level.

### `pnStepCount` [out]

Pointer to a **UINT** variable into which the method writes the number of steps in the volume range. This number remains constant for the lifetime of the [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) interface instance.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pnStep* and *pnStepCount* are both **NULL**. |

## Remarks

This method represents the volume level of the audio stream that enters or leaves the audio endpoint device as an index or "step" in a range of discrete volume levels. Output value **pnStepCount* is the number of steps in the range. Output value **pnStep* is the step index of the current volume level. If the number of steps is n = **pnStepCount*, then step index **pnStep* can assume values from 0 (minimum volume) to n – 1 (maximum volume).

Over the range from 0 to n – 1, successive intervals between adjacent steps do not necessarily represent uniform volume increments in either linear signal amplitude or decibels. In Windows Vista, **GetVolumeStepInfo** defines the relationship of index to volume level (signal amplitude) to be an audio-tapered curve. Note that the shape of the curve might change in future versions of Windows. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

Audio applications can call the [IAudioEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup) and [IAudioEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown) methods to increase or decrease the volume level by one interval. Either method first calculates the idealized volume level that corresponds to the next point on the audio-tapered curve. Next, the method selects the endpoint volume setting that is the best approximation to the idealized level. To obtain the range and granularity of the endpoint volume settings, call the [IEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange) method. If the audio endpoint device implements a hardware volume control, **GetVolumeRange** describes the hardware volume settings. Otherwise, the EndpointVolume API implements the endpoint volume control in software, and **GetVolumeRange** describes the volume settings of the software-implemented control.

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown)

[IAudioEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup)