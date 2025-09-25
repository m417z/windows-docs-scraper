# MIDIHDR structure

## Description

The **MIDIHDR** structure defines the header used to identify a MIDI system-exclusive or stream buffer.

## Members

### `lpData`

Pointer to MIDI data.

### `dwBufferLength`

Size of the buffer.

### `dwBytesRecorded`

Actual amount of data in the buffer. This value should be less than or equal to the value given in the **dwBufferLength** member.

### `dwUser`

Custom user data.

### `dwFlags`

Flags giving information about the buffer.

| Name | Description |
| --- | --- |
| **MHDR_DONE** | Set by the device driver to indicate that it is finished with the buffer and is returning it to the application. |
| **MHDR_INQUEUE** | Set by Windows to indicate that the buffer is queued for playback. |
| **MHDR_ISSTRM** | Set to indicate that the buffer is a stream buffer. |
| **MHDR_PREPARED** | Set by Windows to indicate that the buffer has been prepared by using the [midiInPrepareHeader](https://learn.microsoft.com/previous-versions/dd798459(v=vs.85)) or [midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85)) function. |

### `lpNext`

Reserved; do not use.

### `reserved`

Reserved; do not use.

### `dwOffset`

Offset into the buffer when a callback is performed. (This callback is generated because the MEVT_F_CALLBACK flag is set in the **dwEvent** member of the [MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85)) structure.) This offset enables an application to determine which event caused the callback.

### `dwReserved`

Reserved; do not use.

## See also

MIDI Structures

[MIDIEVENT](https://learn.microsoft.com/previous-versions/dd798448(v=vs.85))

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)

[midiInPrepareHeader](https://learn.microsoft.com/previous-versions/dd798459(v=vs.85))

[midiOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd798477(v=vs.85))