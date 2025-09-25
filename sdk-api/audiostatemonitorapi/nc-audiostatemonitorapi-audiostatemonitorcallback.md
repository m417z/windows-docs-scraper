## Description

Called when the system changes the sound level of the audio streams being monitored by an [IAudioStateMonitor](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nn-audiostatemonitorapi-iaudiostatemonitor).

## Parameters

### `audioStateMonitor` [in]

The **IAudioStateMonitor** with which the callback was registered.

### `context` [in, optional]

A void pointer that points to context information provided by the client in the call to [IAudioStateMonitor::RegisterCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-registercallback).

## Remarks

Windows dynamically mutes or lowers the level of audio streams in response to system events. For example, the volume of a podcast app's audio render stream may be lowered while an alarm is ringing. Or an audio recording app may have their capture stream muted when the app moves to the background. Register an implementation of this callback with a call to [IAudioStateMonitor::RegisterCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-registercallback) to receive notifications when the sound level for a stream changes, and then call [IAudioStateMonitor::GetSoundLevel](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nf-audiostatemonitorapi-iaudiostatemonitor-getsoundlevel) property to determine the new current audio level.

## See also