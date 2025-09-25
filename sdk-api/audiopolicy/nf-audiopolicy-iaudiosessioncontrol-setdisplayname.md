# IAudioSessionControl::SetDisplayName

## Description

The **SetDisplayName** method assigns a display name to the current session.

## Parameters

### `Value` [in]

Pointer to a null-terminated, wide-character string that contains the display name for the session.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates a name-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *Value* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

In Windows Vista, the system-supplied program, Sndvol.exe, uses the display name to label the volume control for the session. If the client does not call **SetDisplayName** to assign a display name to the session, the Sndvol program uses a default, automatically generated name to label the session. The default name incorporates information such as the window title or version resource of the audio application.

If a client has more than one active session, client-specified display names are especially helpful for distinguishing among the volume controls for the various sessions.

In the case of a cross-process session, the session has no identifying information, such as an application name or process ID, from which to generate a default display name. Thus, the client must call **SetDisplayName** to avoid displaying a meaningless default display name.

The display name does not persist beyond the lifetime of the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) object. Thus, after all references to the object are released, a subsequently created version of the object (with the same application, same session GUID, and same endpoint device) will once again have a default, automatically generated display name until the client calls **SetDisplayName**.

The client can retrieve the display name for the session by calling the [IAudioSessionControl::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getdisplayname) method.

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getdisplayname)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)