# midiInStop function

## Description

The **midiInStop** function stops MIDI input on the specified MIDI input device.

## Parameters

### `hmi`

Handle to the MIDI input device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

If there are any system-exclusive messages or stream buffers in the queue, the current buffer is marked as done (the **dwBytesRecorded** member of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure will contain the actual length of data), but any empty buffers in the queue remain there and are not marked as done.

Calling this function when input is not started has no effect, and the function returns zero.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)