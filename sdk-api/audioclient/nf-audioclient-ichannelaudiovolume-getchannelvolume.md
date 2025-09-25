# IChannelAudioVolume::GetChannelVolume

## Description

The **GetChannelVolume** method retrieves the volume level for the specified channel in the audio session.

## Parameters

### `dwIndex` [in]

The channel number. If the stream format for the audio session has *N* channels, then the channels are numbered from 0 to *N*– 1. To get the number of channels, call the [IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount) method.

### `pfLevel` [out]

Pointer to a **float** variable into which the method writes the volume level of the specified channel. The volume level is in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwIndex* is set to an invalid channel number. |
| **E_POINTER** | Parameter *pfLevel* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

Clients can call the [IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes) or [IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume) method to set the per-channel volume levels in an audio session.

## See also

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount)

[IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes)

[IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume)