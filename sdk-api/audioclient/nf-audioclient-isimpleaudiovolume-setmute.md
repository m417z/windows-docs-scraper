# ISimpleAudioVolume::SetMute

## Description

The **SetMute** method sets the muting state for the audio session.

## Parameters

### `bMute` [in]

The new muting state. **TRUE** enables muting. **FALSE** disables muting.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates a volume-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method generates a volume-change event only if the method call changes the muting state of the session from disabled to enabled, or from enabled to disabled. For example, if muting is enabled when the call occurs, and the call enables muting, no event is generated.

This method applies the same muting state to all channels in the audio session. The endpoint device always applies muting uniformly across all the channels in the session. There are no [IChannelAudioVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume) methods for setting the muting states of individual channels.

The client can get the muting state of the audio session by calling the [SimpleAudioVolume::GetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-getmute) method.

## See also

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[ISimpleAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-isimpleaudiovolume)

[ISimpleAudioVolume::GetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-getmute)