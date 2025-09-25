# midiStreamPause function

## Description

The **midiStreamPause** function pauses playback of a specified MIDI stream.

## Parameters

### `hms`

Handle to a MIDI stream. This handle must have been returned by a call to the [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) function. This handle identifies the output device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

The current playback position is saved when playback is paused. To resume playback from the current position, use the [midiStreamRestart](https://learn.microsoft.com/previous-versions/dd798491(v=vs.85)) function.

Calling this function when the output is already paused has no effect, and the function returns MMSYSERR_NOERROR.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)