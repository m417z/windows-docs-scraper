# IAudioSessionEvents::OnDisplayNameChanged

## Description

The **OnDisplayNameChanged** method notifies the client that the display name for the session has changed.

## Parameters

### `NewDisplayName` [in]

The new display name for the session. This parameter points to a null-terminated, wide-character string containing the new display name. The string remains valid for the duration of the call.

### `EventContext` [in]

The event context value. This is the same value that the caller passed to [IAudioSessionControl::SetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setdisplayname) in the call that changed the display name for the session. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The session manager calls this method each time a call to the [IAudioSessionControl::SetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setdisplayname) method changes the display name of the session. The Sndvol program uses a session's display name to label the volume slider for the session.

The *EventContext* parameter provides a means for a client to distinguish between a display-name change that it initiated and one that some other client initiated. When calling the [IAudioSessionControl::SetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setdisplayname) method, a client passes in an *EventContext* parameter value that its implementation of the **OnDisplayNameChanged** method can recognize.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioSessionControl::SetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setdisplayname)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)