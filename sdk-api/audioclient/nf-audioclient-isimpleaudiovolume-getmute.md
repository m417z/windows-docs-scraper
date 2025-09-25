# ISimpleAudioVolume::GetMute

## Description

The **GetMute** method retrieves the current muting state for the audio session.

## Parameters

### `pbMute` [out]

Pointer to a **BOOL** variable into which the method writes the muting state. **TRUE** indicates that muting is enabled. **FALSE** indicates that it is disabled.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pbMute* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## See also

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)

[ISimpleAudioVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmute)