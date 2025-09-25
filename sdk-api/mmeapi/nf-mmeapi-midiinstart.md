# midiInStart function

## Description

The **midiInStart** function starts MIDI input on the specified MIDI input device.

## Parameters

### `hmi`

Handle to the MIDI input device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

This function resets the time stamp to zero; time stamp values for subsequently received messages are relative to the time that this function was called.

All messages except system-exclusive messages are sent directly to the client when they are received. System-exclusive messages are placed in the buffers supplied by the [midiInAddBuffer](https://learn.microsoft.com/previous-versions/dd798450(v=vs.85)) function. If there are no buffers in the queue, the system-exclusive data is thrown away without notification to the client and input continues. Buffers are returned to the client when they are full, when a complete system-exclusive message has been received, or when the [midiInReset](https://learn.microsoft.com/previous-versions/dd798461(v=vs.85)) function is used. The **dwBytesRecorded** member of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure will contain the actual length of data received.

Calling this function when input is already started has no effect, and the function returns zero.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)