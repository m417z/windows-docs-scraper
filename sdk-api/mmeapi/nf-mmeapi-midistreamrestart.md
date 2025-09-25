# midiStreamRestart function

## Description

The **midiStreamRestart** function restarts a paused MIDI stream.

## Parameters

### `hms`

Handle to a MIDI stream. This handle must have been returned by a call to the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function. This handle identifies the output device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

Calling this function when the output is not paused has no effect, and the function returns MMSYSERR_NOERROR.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)