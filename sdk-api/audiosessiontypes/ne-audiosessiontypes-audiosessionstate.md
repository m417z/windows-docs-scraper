# AudioSessionState enumeration

## Description

The **AudioSessionState** enumeration defines constants that indicate the current state of an audio session.

## Constants

### `AudioSessionStateInactive`

The audio session is inactive. (It contains at least one stream, but none of the streams in the session is currently running.)

### `AudioSessionStateActive`

The audio session is active. (At least one of the streams in the session is running.)

### `AudioSessionStateExpired`

The audio session has expired. (It contains no streams.)

## Remarks

When a client opens a session by assigning the first stream to the session (by calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method), the initial session state is inactive. The session state changes from inactive to active when a stream in the session begins running (because the client has called the [IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start) method). The session changes from active to inactive when the client stops the last running stream in the session (by calling the [IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop) method). The session state changes to expired when the client destroys the last stream in the session by releasing all references to the stream object.

The system volume-control program, Sndvol, displays volume controls for both active and inactive sessions. Sndvol stops displaying the volume control for a session when the session state changes to expired. For more information about Sndvol, see [Audio Sessions](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-sessions).

The [IAudioSessionControl::GetState](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getstate) and [IAudioSessionEvents::OnStateChanged](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionevents-onstatechanged) methods use the constants defined in the **AudioSessionState** enumeration.

For more information about session states, see [Audio Sessions](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-sessions).

## See also

[Core Audio Constants](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-constants)

[Core Audio Enumerations](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-enumerations)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClient::Start](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-start)

[IAudioClient::Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop)

[IAudioSessionControl::GetState](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessioncontrol-getstate)

[IAudioSessionEvents::OnStateChanged](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nf-audiopolicy-iaudiosessionevents-onstatechanged)