# midiOutLongMsg function

## Description

The **midiOutLongMsg** function sends a system-exclusive MIDI message to the specified MIDI output device.

## Parameters

### `hmo`

Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to **HMIDIOUT**.

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure that identifies the MIDI buffer.

### `cbmh`

Size, in bytes, of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_NOTREADY** | The hardware is busy with other data. |
| **MIDIERR_UNPREPARED** | The buffer pointed to by *lpMidiOutHdr* has not been prepared. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |

## Remarks

Before the buffer is passed to **midiOutLongMsg**, it must be prepared by using the [midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85)) function. The MIDI output device driver determines whether the data is sent synchronously or asynchronously.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)