# IAudioSessionManager2::RegisterSessionNotification

## Description

The **RegisterSessionNotification** method registers the application to receive a notification when a session is created.

## Parameters

### `SessionNotification`

A pointer to the application's implementation of the [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface. If the method call succeeds, it calls the **AddRef** method on the application's **IAudioSessionNotification** interface.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *SessionNotification* is **NULL**. |
| E_OUTOFMEMORY | Internal object could not be created due to insufficient memory. |

## Remarks

The application can register to receive a notification when a session is created, through the methods of the [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface. The application implements the **IAudioSessionNotification** interface. The methods defined in this interface receive callbacks from the system when a session is created. For example code that shows how to implement this interface, see

[IAudioSessionNotification Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification).

To begin receiving notifications, the application calls the **IAudioSessionManager2::RegisterSessionNotification** method to register its [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface. When the application no longer requires notifications, it calls the [IAudioSessionManager2::UnregisterSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-unregistersessionnotification) method to delete the registration.

> [!Important]
> You must call [IAudioSessionEnumerator::GetCount](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionenumerator-getcount) to begin receiving notifications. The session enumeration API discards new session notifications until the application has first retrieved the list of existing sessions. This is to prevent a race condition that can occur when a session notification arrives while the application using the session APIs is starting up. Calling **GetCount** triggers the enumeration API to begin sending session notifications.

**Note** Make sure that the application initializes COM with Multithreaded Apartment (MTA) model by calling `CoInitializeEx(NULL, COINIT_MULTITHREADED)` in a non-UI thread. If MTA is not initialized, the application does not receive session notifications from the session manager.
Threads that run the user interface of an application should be initialized apartment threading model.

## See also

[IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)