# IAudioEndpointVolume::GetMasterVolumeLevelScalar

## Description

The **GetMasterVolumeLevelScalar** method gets the master volume level of the audio stream that enters or leaves the audio endpoint device. The volume level is expressed as a normalized, audio-tapered value in the range from 0.0 to 1.0.

## Parameters

### `pfLevel` [out]

Pointer to the master volume level. This parameter points to a **float** variable into which the method writes the volume level. The level is expressed as a normalized value in the range from 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfLevel* is **NULL**. |

## Remarks

The volume level is normalized to the range from 0.0 to 1.0, where 0.0 is the minimum volume level and 1.0 is the maximum level. Within this range, the relationship of the normalized volume level to the attenuation of signal amplitude is described by a nonlinear, audio-tapered curve. Note that the shape of the curve might change in future versions of Windows. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

The normalized volume levels that are retrieved by this method are suitable to represent the positions of volume controls in application windows and on-screen displays.

For a code example that calls **GetMasterVolumeLevelScalar**, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)