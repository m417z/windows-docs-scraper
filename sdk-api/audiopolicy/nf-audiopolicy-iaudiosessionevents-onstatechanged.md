# IAudioSessionEvents::OnStateChanged

## Description

The **OnStateChanged** method notifies the client that the stream-activity state of the session has changed.

## Parameters

### `NewState` [in]

The new session state. The value of this parameter is one of the following [AudioSessionState](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audiosessionstate) enumeration values:

AudioSessionStateActive

AudioSessionStateInactive

AudioSessionStateExpired

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

A client cannot generate a session-state-change event. The system is always the source of this type of event. Thus, unlike some other [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) methods, this method does not supply a context parameter.

The system changes the state of a session from inactive to active at the time that a client opens the first stream in the session. A client opens a stream by calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method. The system changes the session state from active to inactive at the time that a client closes the last stream in the session. The client that releases the last reference to an [IAudioClient](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient) object closes the stream that is associated with the object.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)