# IAudioSessionEvents::OnGroupingParamChanged

## Description

The **OnGroupingParamChanged** method notifies the client that the grouping parameter for the session has changed.

## Parameters

### `NewGroupingParam` [in]

The new grouping parameter for the session. This parameter points to a grouping-parameter GUID.

### `EventContext` [in]

The event context value. This is the same value that the caller passed to [IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam) in the call that changed the grouping parameter for the session. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The session manager calls this method each time a call to the [IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam) method changes the grouping parameter for the session.

The *EventContext* parameter provides a means for a client to distinguish between a grouping-parameter change that it initiated and one that some other client initiated. When calling the [IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam) method, a client passes in an *EventContext* parameter value that its implementation of the **OnGroupingParamChanged** method can recognize.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioSessionControl::SetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-setgroupingparam)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)