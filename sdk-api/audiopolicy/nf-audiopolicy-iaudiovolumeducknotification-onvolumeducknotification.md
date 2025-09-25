## Description

The **OnVolumeDuckNotification** method sends a notification about a pending system ducking event. For more information, see [Implementation considerations for ducking notifications](https://learn.microsoft.com/windows/desktop/CoreAudio/handling-audio-ducking-events-from-communication-devices).

## Parameters

### `sessionID` [in]

A string containing the session instance identifier of the communications session that raises the the auto-ducking event. To get the session instance identifier, call [IAudioSessionControl2::GetSessionInstanceIdentifier](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-getsessioninstanceidentifier).

### `countCommunicationSessions` [in]

The number of active communications sessions. If there are n sessions, the sessions are numbered from 0 to –1.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

After the application registers its implementation of the [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface by calling [IAudioSessionManager2::RegisterDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-registerducknotification), the session manager calls **OnVolumeDuckNotification** when it wants to send a notification about when ducking begins. The application receives the event notifications in the form of callbacks.

## See also

[IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification)

[Using a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-communication-device)