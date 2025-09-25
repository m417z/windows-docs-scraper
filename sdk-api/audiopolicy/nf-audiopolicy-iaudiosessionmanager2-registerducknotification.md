# IAudioSessionManager2::RegisterDuckNotification

## Description

The **RegisterDuckNotification** method registers the application with the session manager to receive ducking notifications.

## Parameters

### `sessionID`

Pointer to a null-terminated string that contains a session instance identifier. Applications that are playing a media stream and want to provide custom stream attenuation or ducking behavior, pass their own session instance identifier. For more information, see Remarks.

Other applications
that do not want to alter their streams but want to get all the ducking notifications
must pass **NULL**.

### `duckNotification`

Pointer to the application's implementation of the [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface. The implementation is called when ducking events are raised by the audio system and notifications are sent to the registered applications.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *duckNotification* is **NULL**. |
| E_OUTOFMEMORY | Internal object could not be created due to insufficient memory. |

## Remarks

*Stream Attenuation* or *ducking* is a new feature in Windows 7. An application playing a media stream can make the stream behave differently when a new communication stream is opened on the default communication device. For example, the original media stream can be paused while the new communication stream is open. To provide this custom implementation for stream attenuation, the application can opt out of the default stream attenuation experience by calling [IAudioSessionControl::SetDuckingPreference](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol2-setduckingpreference) and then register itself to receive notifications when session events occur. For stream attenuation, a session event is raised by the system when a communication stream is opened or closed on the default communication device. For more information about this feature, see [Getting Ducking Events](https://learn.microsoft.com/windows/desktop/CoreAudio/handling-audio-ducking-events-from-communication-devices).

To begin receiving notifications, the application calls the **RegisterDuckNotification** method to register its [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface with the session manager. When the application no longer requires notifications, it calls the [IAudioSessionManager2::UnregisterDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-unregisterducknotification) method to delete the registration.

The application receives notifications about the ducking events through the methods of the [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface. The application implements **IAudioVolumeDuckNotification**. After the registration call has succeeded, the system calls the methods of this interface when session events occur.

## See also

[IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)

[Using a Communication Device](https://learn.microsoft.com/windows/desktop/CoreAudio/using-the-communication-device)