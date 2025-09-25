# IAudioStreamVolume::SetChannelVolume

## Description

The **SetChannelVolume** method sets the volume level for the specified channel in the audio stream.

## Parameters

### `dwIndex` [in]

The channel number. If the stream format has *N* channels, the channels are numbered from 0 to *N*– 1. To get the number of channels, call the [IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount) method.

### `fLevel` [in]

The volume level for the channel. Valid volume levels are in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwIndex* is set to an invalid channel number, or parameter *fLevel* is not in the range 0.0 to 1.0. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## See also

[IAudioStreamVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)

[IAudioStreamVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudiostreamvolume-getchannelcount)