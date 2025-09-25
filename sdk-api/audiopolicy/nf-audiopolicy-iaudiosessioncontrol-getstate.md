# IAudioSessionControl::GetState

## Description

The **GetState** method retrieves the current state of the audio session.

## Parameters

### `pRetVal` [out]

Pointer to a variable into which the method writes the current session state. The state must be one of the following [AudioSessionState](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audiosessionstate) enumeration values:

AudioSessionStateActive

AudioSessionStateInactive

AudioSessionStateExpired

These values indicate that the session state is active, inactive, or expired, respectively. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pRetVal* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method indicates whether the state of the session is active, inactive, or expired. The state is active if the session has one or more streams that are running. The state changes from active to inactive when the last running stream in the session stops. The session state changes to expired when the client destroys the last stream in the session by releasing all references to the stream object.

The Sndvol program displays volume and mute controls for sessions that are in the active and inactive states. When a session expires, Sndvol stops displaying the controls for that session. If a session has previously expired, but the session state changes to active (because a stream in the session begins running) or inactive (because a client assigns a new stream to the session), Sndvol resumes displaying the controls for the session.

The client creates a stream by calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method. At the time that it creates a stream, the client assigns the stream to a session. A session begins when a client assigns the first stream to the session. Initially, the session is in the inactive state. The session state changes to active when the first stream in the session begins running. The session terminates when a client releases the final reference to the last remaining stream object in the session.

## See also

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IMMDevice::Activate](https://learn.microsoft.com/windows/desktop/api/mmdeviceapi/nf-mmdeviceapi-immdevice-activate)