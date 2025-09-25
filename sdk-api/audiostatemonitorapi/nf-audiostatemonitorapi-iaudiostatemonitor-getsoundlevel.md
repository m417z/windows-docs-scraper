## Description

Gets the current sound level for the audio streams associated with an [IAudioStateMonitor](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nn-audiostatemonitorapi-iaudiostatemonitor).

## Return value

A value from the [AudioStateMonitorSoundLevel](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/ne-audiostatemonitorapi-audiostatemonitorsoundlevel) enumeration specifying the current sound level for the audio stream.

## Remarks

Windows dynamically mutes or lowers the level of audio streams in response to system events. For example, the volume of a podcast app's audio render stream may be lowered while an alarm is ringing. Or an audio recording app may have their capture stream muted when the app moves to the background. Register an implementation of the [AudioStateMonitorCallback](https://learn.microsoft.com/windows/win32/api/audiostatemonitorapi/nc-audiostatemonitorapi-audiostatemonitorcallback) event to receive notifications when the sound level for a category of audio streams changes.

## See also