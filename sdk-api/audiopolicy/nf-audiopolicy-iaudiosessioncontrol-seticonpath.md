# IAudioSessionControl::SetIconPath

## Description

The **SetIconPath** method assigns a display icon to the current session.

## Parameters

### `Value` [in]

Pointer to a null-terminated, wide-character string that specifies the path and file name of an .ico, .dll, or .exe file that contains the icon. For information about icon paths, see the Windows SDK documentation.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates an icon-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *Value* is **NULL**. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

In Windows Vista, the system-supplied program, Sndvol.exe, uses the display icon (along with the display name) to label the volume control for the session. If the client does not call **SetIconPath** to assign an icon to the session, the Sndvol program uses the icon from the application window as the default icon for the session.

In the case of a cross-process session, the session is not associated with a single application process. Thus, Sndvol has no application-specific icon to use by default, and the client must call **SetIconPath** to avoid displaying a meaningless icon.

The display icon does not persist beyond the lifetime of the [IAudioSessionControl](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol) object. Thus, after all references to the object are released, a subsequently created version of the object (with the same application, same session GUID, and same endpoint device) will once again have a default icon until the client calls **SetIconPath**.

The client can retrieve the display icon for the session by calling the [IAudioSessionControl::GetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-geticonpath) method.

## See also

[IAudioSessionControl Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessioncontrol)

[IAudioSessionControl::GetIconPath](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-geticonpath)