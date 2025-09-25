# midiStreamOut function

## Description

The **midiStreamOut** function plays or queues a stream (buffer) of MIDI data to a MIDI output device.

## Parameters

### `hms`

Handle to a MIDI stream. This handle must have been returned by a call to the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function. This handle identifies the output device.

### `pmh`

Pointer to a [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure that identifies the MIDI buffer.

### `cbmh`

Size, in bytes, of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |
| **MIDIERR_STILLPLAYING** | The output buffer pointed to by *lpMidiHdr* is still playing or is queued from a previous call to [midiStreamOut](https://learn.microsoft.com/previous-versions/dd798487(v=vs.85)). |
| **MIDIERR_UNPREPARED** | The header pointed to by *lpMidiHdr* has not been prepared. |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The pointer specified by *lpMidiHdr* is invalid. |

## Remarks

Before the buffer is passed to [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)), it must be prepared by using the [midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85)) function.

Because the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function opens the output device in paused mode, you must call the [midiStreamRestart](https://learn.microsoft.com/previous-versions/dd798491(v=vs.85)) function before you can use **midiStreamOut** to start the playback.

For the current implementation of this function, the buffer must be smaller than 64K.

The buffer pointed to by the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure contains one or more MIDI events, each of which is defined by a [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)