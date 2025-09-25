# IAudioStreamVolume::SetAllVolumes

## Description

The **SetAllVolumes** method sets the individual volume levels for all the channels in the audio stream.

## Parameters

### `dwCount` [in]

The number of elements in the *pfVolumes* array. This parameter must equal the number of channels in the stream format. To get the number of channels, call the [IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount) method.

### `pfVolumes` [in]

Pointer to an array of volume levels for the channels in the audio stream. The number of elements in the *pfVolumes* array is specified by the *dwCount* parameter. The caller writes the volume level for each channel to the array element whose index matches the channel number. If the stream format has *N* channels, the channels are numbered from 0 to *N*– 1. Valid volume levels are in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwCount* does not equal the number of channels in the stream, or the value of a *pfVolumes* array element is not in the range 0.0 to 1.0. |
| **E_POINTER** | Parameter *pfVolumes* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## See also

[IAudioStreamVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)

[IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount)