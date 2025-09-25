# IAudioStreamVolume::GetAllVolumes

## Description

The **GetAllVolumes** method retrieves the volume levels for all the channels in the audio stream.

## Parameters

### `dwCount` [in]

The number of elements in the *pfVolumes* array. The *dwCount* parameter must equal the number of channels in the stream format. To get the number of channels, call the [IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount) method.

### `pfVolumes` [out]

Pointer to an array of volume levels for the channels in the audio stream. This parameter points to a caller-allocated **float** array into which the method writes the volume levels for the individual channels. Volume levels are in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwCount* does not equal the number of channels in the stream. |
| **E_POINTER** | Parameter *pfVolumes* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

Clients can call the [IAudioStreamVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-setallvolumes) or [IAudioStreamVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-setchannelvolume) method to set the per-channel volume levels in an audio stream.

## See also

[IAudioStreamVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)

[IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount)

[IAudioStreamVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-setallvolumes)

[IAudioStreamVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-setchannelvolume)