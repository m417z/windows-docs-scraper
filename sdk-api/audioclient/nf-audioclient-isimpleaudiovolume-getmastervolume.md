# ISimpleAudioVolume::GetMasterVolume

## Description

The **GetMasterVolume** method retrieves the client volume level for the audio session.

## Parameters

### `pfLevel` [out]

Pointer to a **float** variable into which the method writes the client volume level. The volume level is a value in the range 0.0 to 1.0.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pfLevel* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method retrieves the client volume level for the session. This is the volume level that the client set in a previous call to the [ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume) method.

## See also

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)

[ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume)