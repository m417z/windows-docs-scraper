# IAudioSessionManager2::UnregisterDuckNotification

## Description

The **UnregisterDuckNotification** method deletes a previous registration by the application to receive notifications.

## Parameters

### `duckNotification`

Pointer to the [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface that is implemented by the application. Pass the same interface pointer that was specified to the session manager in a previous call to the [IAudioSessionManager2::RegisterDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-registerducknotification) method. If the **UnregisterDuckNotification** method succeeds, it calls the **Release** method on the application's **IAudioVolumeDuckNotification** interface.

## Return value

If the method succeeds, it returns S_OK.
If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return value | Description |
| --- | --- |
| E_POINTER | *duckNotification* is **NULL**. |

## Remarks

The application calls this method when it no longer needs to receive notifications. The **UnregisterDuckNotification** method removes the registration of an [IAudioVolumeDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiovolumeducknotification) interface that the application previously registered with the session manager by calling the [IAudioSessionManager2::RegisterDuckNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionmanager2-registerducknotification) method.

After the application calls **UnregisterDuckNotification**, any pending events are not reported to the application.

## See also

[Default Ducking Experience](https://learn.microsoft.com/windows/desktop/CoreAudio/stream-attenuation)

[Getting Ducking Events](https://learn.microsoft.com/windows/desktop/CoreAudio/handling-audio-ducking-events-from-communication-devices)

[IAudioSessionManager2](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionmanager2)