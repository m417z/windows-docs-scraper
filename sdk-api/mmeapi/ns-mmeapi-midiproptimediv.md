# MIDIPROPTIMEDIV structure

## Description

The **MIDIPROPTIMEDIV** structure contains the time division property for a stream.

## Members

### `cbStruct`

Length, in bytes, of this structure. This member must be filled in for both the MIDIPROP_SET and MIDIPROP_GET operations of the [midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85)) function.

### `dwTimeDiv`

Time division for this stream, in the format specified in the *Standard MIDI Files 1.0* specification. The low 16 bits of this **DWORD** value contain the time division. This member is set in a MIDIPROP_SET operation and is filled on return from a MIDIPROP_GET operation.

## Remarks

The time division property is read or written by the [midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85)) function.

## See also

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)

[midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85))