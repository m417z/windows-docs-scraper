## Description

The **OnVolumeUnduckNotification** method sends a notification about a pending system unducking event. For more information, see [Implementation Considerations for Ducking Notifications](https://learn.microsoft.com/windows/desktop/CoreAudio/handling-audio-ducking-events-from-communication-devices).

## Parameters

### `sessionID` [in]

A string containing the session instance identifier of the terminating communications session that initiated the ducking. To get the session instance identifier, call [IAudioSessionControl2::GetSessionInstanceIdentifier](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-getsessioninstanceidentifier).

## Return value

If the method succeeds, it returns S_OK.

## Remarks

After the application registers its implementation of the [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface by calling [IAudioSessionManager2::RegisterDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-registerducknotification), the session manager calls **OnVolumeUnduckNotification** when it wants to send a notification about when ducking ends. The application receives the event notifications in the form of callbacks.

## See also

[IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification)

[Using a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-communication-device)