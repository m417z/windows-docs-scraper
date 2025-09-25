# IAudioSessionControl::RegisterAudioSessionNotification

## Description

The **RegisterAudioSessionNotification** method registers the client to receive notifications of session events, including changes in the stream state.

## Parameters

### `NewNotifications` [in]

Pointer to a client-implemented [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface. If the method succeeds, it calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the client's **IAudioSessionEvents** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *NewNotifications* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method passes a client-implemented [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface to the session manager. Following a successful call to this method, the session manager calls the methods in the **IAudioSessionEvents** interface to notify the client of various session events. Through these methods, the client receives notifications of the following session-related events:

* Display name changes
* Volume level changes
* Session state changes (inactive to active, or active to inactive)
* Grouping parameter changes
* Disconnection of the client from the session (caused by the user removing the audio endpoint device, shutting down the session manager, or changing the stream format)

When notifications are no longer needed, the client can call the [IAudioSessionControl::UnregisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-unregisteraudiosessionnotification) method to terminate the notifications.

Before the client releases its final reference to the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, it should call [UnregisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-unregisteraudiosessionnotification) to unregister the interface. Otherwise, the application leaks the resources held by the **IAudioSessionEvents** and [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) objects. Note that **RegisterAudioSessionNotification** calls the client's [IAudioSessionEvents::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method, and **UnregisterAudioSessionNotification** calls the [IAudioSessionEvents::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the client errs by releasing its reference to the **IAudioSessionEvents** interface before calling **UnregisterAudioSessionNotification**, the session manager never releases its reference to the **IAudioSessionEvents** interface. For example, a poorly designed **IAudioSessionEvents** implementation might call **UnregisterAudioSessionNotification** from the destructor for the **IAudioSessionEvents** object. In this case, the client will not call **UnregisterAudioSessionNotification** until the session manager releases its reference to the **IAudioSessionEvents** interface, and the session manager will not release its reference to the **IAudioSessionEvents** interface until the client calls **UnregisterAudioSessionNotification**. For more information about the **AddRef** and **Release** methods, see the discussion of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface in the Windows SDK documentation.

In addition, the client should call [UnregisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-unregisteraudiosessionnotification) before releasing all of its references to the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) and [IAudioSessionManager](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager) objects. Unless the client retains a reference to at least one of these two objects, the session manager leaks the storage that it allocated to hold the registration information. After registering a notification interface, the client continues to receive notifications for only as long as at least one of these two objects exists.

For a code example that calls the **RegisterAudioSessionNotification** method, see [Audio Events for Legacy Audio Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-events-for-legacy-audio-applications).

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::UnregisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-unregisteraudiosessionnotification)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[IAudioSessionManager](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager)