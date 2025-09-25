# IChannelAudioVolume::GetAllVolumes

## Description

The **GetAllVolumes** method retrieves the volume levels for all the channels in the audio session.

## Parameters

### `dwCount` [in]

The number of elements in the *pfVolumes* array. The *dwCount* parameter must equal the number of channels in the stream format for the audio session. To get the number of channels, call the [IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount) method.

### `pfVolumes` [out]

Pointer to an array of volume levels for the channels in the audio session. This parameter points to a caller-allocated **float** array into which the method writes the volume levels for the individual channels. Volume levels are in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwCount* does not equal the number of channels in the stream format for the audio session. |
| **E_POINTER** | Parameter *pfVolumes* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

Clients can call the [IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes) or [IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume) method to set the per-channel volume levels in an audio session.

## See also

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount)

[IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes)

[IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume)