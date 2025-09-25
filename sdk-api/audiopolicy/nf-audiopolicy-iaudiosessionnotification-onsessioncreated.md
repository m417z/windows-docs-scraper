# IAudioSessionNotification::OnSessionCreated

## Description

The **OnSessionCreated** method notifies the registered processes that the audio session has been created.

## Parameters

### `NewSession` [in]

Pointer to the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) interface of the audio session that was created.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

After registering its [IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification) interface, the application receives event notifications in the form of callbacks through the methods of the interface.

The audio engine calls **OnSessionCreated** when a new session is activated on the device endpoint.
This method is called from the session manager thread. This method must take a reference to the session in the *NewSession* parameter if it wants to keep the reference after this call completes.

## See also

[IAudioSessionNotification](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionnotification)