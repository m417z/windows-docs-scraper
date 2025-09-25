# IAudioSessionControl::UnregisterAudioSessionNotification

## Description

The **UnregisterAudioSessionNotification** method deletes a previous registration by the client to receive notifications.

## Parameters

### `NewNotifications` [in]

Pointer to a client-implemented [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface. The client passed this same interface pointer to the session manager in a previous call to the [IAudioSessionControl::RegisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-registeraudiosessionnotification) method. If the **UnregisterAudioSessionNotification** method succeeds, it calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the client's **IAudioSessionEvents** interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *NewNotifications* is **NULL**. |
| **E_NOTFOUND** | The specified interface was not previously registered by the client or has already been removed. |

## Remarks

The client calls this method when it no longer needs to receive notifications. The **UnregisterAudioSessionNotification** method removes the registration of an [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface that the client previously registered with the session manager by calling the [IAudioSessionControl::RegisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-registeraudiosessionnotification) method.

Before the client releases its final reference to the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, it should call **UnregisterAudioSessionNotification** to unregister the interface. Otherwise, the application leaks the resources held by the **IAudioSessionEvents** and [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) objects. Note that [RegisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-registeraudiosessionnotification) calls the client's [IAudioSessionEvents::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method, and **UnregisterAudioSessionNotification** calls the [IAudioSessionEvents::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the client errs by releasing its reference to the **IAudioSessionEvents** interface before calling **UnregisterAudioSessionNotification**, the session manager never releases its reference to the **IAudioSessionEvents** interface. For example, a poorly designed **IAudioSessionEvents** implementation might call **UnregisterAudioSessionNotification** from the destructor for the **IAudioSessionEvents** object. In this case, the client will not call **UnregisterAudioSessionNotification** until the session manager releases its reference to the **IAudioSessionEvents** interface, and the session manager will not release its reference to the **IAudioSessionEvents** interface until the client calls **UnregisterAudioSessionNotification**. For more information about the **AddRef** and **Release** methods, see the discussion of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface in the Windows SDK documentation.

For a code example that calls the **UnregisterAudioSessionNotification** method, see [Audio Events for Legacy Audio Applications](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-events-for-legacy-audio-applications).

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::RegisterAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-registeraudiosessionnotification)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)