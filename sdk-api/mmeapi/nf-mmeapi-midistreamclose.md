# midiStreamClose function

## Description

The **midiStreamClose** function closes an open MIDI stream.

## Parameters

### `hms`

Handle to a MIDI stream, as retrieved by using the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)