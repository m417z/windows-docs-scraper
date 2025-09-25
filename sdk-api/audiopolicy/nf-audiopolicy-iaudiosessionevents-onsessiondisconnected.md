# IAudioSessionEvents::OnSessionDisconnected

## Description

The **OnSessionDisconnected** method notifies the client that the audio session has been disconnected.

## Parameters

### `DisconnectReason` [in]

The reason that the audio session was disconnected. The caller sets this parameter to one of the **AudioSessionDisconnectReason** enumeration values shown in the following table.

| Value | Description |
| --- | --- |
| DisconnectReasonDeviceRemoval | The user removed the audio endpoint device. |
| DisconnectReasonServerShutdown | The Windows audio service has stopped. |
| DisconnectReasonFormatChanged | The stream format changed for the device that the audio session is connected to. |
| DisconnectReasonSessionLogoff | The user logged off the Windows Terminal Services (WTS) session that the audio session was running in. |
| DisconnectReasonSessionDisconnected | The WTS session that the audio session was running in was disconnected. |
| DisconnectReasonExclusiveModeOverride | The (shared-mode) audio session was disconnected to make the audio endpoint device available for an exclusive-mode connection. |

For more information about WTS sessions, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

When disconnecting a session, the session manager closes the streams that belong to that session and invalidates all outstanding requests for services on those streams. The client should respond to a disconnection by releasing all of its references to the [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) interface for a closed stream and releasing all references to the service interfaces that it obtained previously through calls to the [IAudioClient::GetService](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getservice) method.

Following disconnection, many of the methods in the WASAPI interfaces that are tied to closed streams in the disconnected session return error code AUDCLNT_E_DEVICE_INVALIDATED (for example, see [IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding)). For information about recovering from this error, see [Recovering from an Invalid-Device Error](https://learn.microsoft.com/windows/desktop/CoreAudio/recovering-from-an-invalid-device-error).

If the Windows audio service terminates unexpectedly, it does not have an opportunity to notify clients that it is shutting down. In that case, clients learn that the service has stopped when they call a method such as [IAudioClient::GetCurrentPadding](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getcurrentpadding) that discovers that the service is no longer running and fails with error code AUDCLNT_E_SERVICE_NOT_RUNNING.

A client cannot generate a session-disconnected event. The system is always the source of this type of event. Thus, unlike some other [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) methods, this method does not have a context parameter.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::GetService](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getservice)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)