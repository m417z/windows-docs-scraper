# IAudioSessionManager2::UnregisterSessionNotification

## Description

The **UnregisterSessionNotification** method deletes the registration to receive a notification when a session is created.

## Parameters

### `SessionNotification`

A pointer to the application's implementation of the [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface. Pass the same interface pointer that was specified to the session manager in a previous call to [IAudioSessionManager2::RegisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-registersessionnotification) to register for notification.

If the **UnregisterSessionNotification** method succeeds, it calls the **Release** method on the application's [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *SessionNotification* is **NULL**. |

## Remarks

The application calls this method when it no longer needs to receive notifications. The **UnregisterSessionNotification** method removes the registration of an [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface that the application previously registered with the session manager by calling the [IAudioSessionControl::RegisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-registeraudiosessionnotification) method.

## See also

[IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)