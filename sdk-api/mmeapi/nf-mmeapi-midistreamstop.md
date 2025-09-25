# midiStreamStop function

## Description

The **midiStreamStop** function turns off all notes on all MIDI channels for the specified MIDI output device.

## Parameters

### `hms`

Handle to a MIDI stream. This handle must have been returned by a call to the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function. This handle identifies the output device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

When you call this function, any pending system-exclusive or stream output buffers are returned to the callback mechanism and the MHDR_DONE bit is set in the **dwFlags** member of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

While the [midiOutReset](https://learn.microsoft.com/previous-versions/dd798479(v=vs.85)) function turns off all notes, **midiStreamStop** turns off only those notes that have been turned on by a MIDI note-on message.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)