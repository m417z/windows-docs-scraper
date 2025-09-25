# midiInAddBuffer function

## Description

The **midiInAddBuffer** function sends an input buffer to a specified opened MIDI input device. This function is used for system-exclusive messages.

## Parameters

### `hmi`

Handle to the MIDI input device.

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure that identifies the buffer.

### `cbmh`

Size, in bytes, of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_STILLPLAYING** | The buffer pointed to by *lpMidiInHdr* is still in the queue. |
| **MIDIERR_UNPREPARED** | The buffer pointed to by *lpMidiInHdr* has not been prepared. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

When the buffer is filled, it is sent back to the application.

The buffer must be prepared by using the [midiInPrepareHeader](https://learn.microsoft.com/previous-versions/dd798459(v=vs.85)) function before it is passed to the **midiInAddBuffer** function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)