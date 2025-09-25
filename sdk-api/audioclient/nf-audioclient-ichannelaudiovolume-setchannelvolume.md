# IChannelAudioVolume::SetChannelVolume

## Description

The **SetChannelVolume** method sets the volume level for the specified channel in the audio session.

## Parameters

### `dwIndex` [in]

The channel number. If the stream format for the audio session has *N* channels, the channels are numbered from 0 to *N*– 1. To get the number of channels, call the [IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount) method.

### `fLevel` [in]

The volume level for the channel. Valid volume levels are in the range 0.0 to 1.0.

### `EventContext` [in]

Pointer to the event-context GUID. If a call to this method generates a channel-volume-change event, the session manager sends notifications to all clients that have registered [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interfaces with the session manager. The session manager includes the *EventContext* pointer value with each notification. Upon receiving a notification, a client can determine whether it or another client is the source of the event by inspecting the *EventContext* value. This scheme depends on the client selecting a value for this parameter that is unique among all clients in the session. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *dwIndex* is set to an invalid channel number, or parameter *fLevel* is not in the range 0.0 to 1.0. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method, if it succeeds, generates a channel-volume-change event regardless of whether the new channel volume level differs in value from the previous channel volume level.

## See also

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[IChannelAudioVolume Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-ichannelaudiovolume)

[IChannelAudioVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-getchannelcount)