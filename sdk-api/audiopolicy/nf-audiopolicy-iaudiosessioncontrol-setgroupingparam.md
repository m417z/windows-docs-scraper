# IAudioSessionControl::SetGroupingParam

## Description

The **SetGroupingParam** method assigns a session to a grouping of sessions.

## Parameters

### `Override` [in]

The new grouping parameter. This parameter must be a valid, non-**NULL** pointer to a grouping-parameter GUID. For more information, see Remarks.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates a grouping-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *Grouping* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

A client calls this method to change the grouping parameter of a session. All of the audio sessions that have the same grouping parameter value are under the control of the same volume-level slider in the system volume-control program, Sndvol. For more information, see [Grouping Parameters](https://learn.microsoft.com/windows/desktop/CoreAudio/grouping-parameters).

The client can get the current grouping parameter for the session by calling the [IAudioSessionControl::GetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getgroupingparam) method.

If a client has never called **SetGroupingParam** to assign a grouping parameter to a session, the session does not belong to any grouping. A session that does not belong to any grouping has its own, dedicated volume-level slider in the Sndvol program.

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::GetGroupingParam](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getgroupingparam)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)