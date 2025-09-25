# IAudioSessionEvents::OnIconPathChanged

## Description

The **OnIconPathChanged** method notifies the client that the display icon for the session has changed.

## Parameters

### `NewIconPath` [in]

The path for the new display icon for the session. This parameter points to a string that contains the path for the new icon. The string pointer remains valid only for the duration of the call.

### `EventContext` [in]

The event context value. This is the same value that the caller passed to [IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath) in the call that changed the display icon for the session. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The session manager calls this method each time a call to the [IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath) method changes the display icon for the session. The Sndvol program uses a session's display icon to label the volume slider for the session.

The *EventContext* parameter provides a means for a client to distinguish between a display-icon change that it initiated and one that some other client initiated. When calling the [IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath) method, a client passes in an *EventContext* parameter value that its implementation of the **OnIconPathChanged** method can recognize.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioSessionControl::SetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-seticonpath)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)