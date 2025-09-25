# ISimpleAudioVolume::SetMasterVolume

## Description

The **SetMasterVolume** method sets the master volume level for the audio session.

## Parameters

### `fLevel` [in]

The new master volume level. Valid volume levels are in the range 0.0 to 1.0.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates a volume-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *fLevel* is not in the range 0.0 to 1.0. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method generates a volume-change event only if the method call changes the volume level of the session. For example, if the volume level is 0.4 when the call occurs, and the call sets the volume level to 0.4, no event is generated.

## See also

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)

[ISimpleAudioVolume::GetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-getmastervolume)