# IAudioSessionManager::GetSimpleAudioVolume

## Description

The **GetSimpleAudioVolume** method retrieves a simple audio volume control.

## Parameters

### `AudioSessionGuid` [in]

Pointer to a session GUID. If the GUID does not identify a session that has been previously opened, the call opens a new but empty session. The Sndvol program does not display a volume-level control for a session unless it contains one or more active streams. If this parameter is **NULL** or points to the value GUID_NULL, the method assigns the stream to the default session.

### `StreamFlags` [in]

Specifies whether the request is for a cross-process session. Set to **TRUE** if the session is cross-process. Set to **FALSE** if the session is not cross-process.

### `AudioVolume` [out]

Pointer to a pointer variable into which the method writes a pointer to the [ISimpleAudioVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume) interface of the audio volume control object. This interface represents the simple audio volume control for the current process. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's **Release** method. If the **Activate** call fails, **AudioVolume* is **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_NOT_INITIALIZED** | The audio stream has not been successfully initialized. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *AudioVolume* is **NULL**. |
| **E_MEMORY** | Out of memory. |

## See also

[IAudioSessionManager Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)