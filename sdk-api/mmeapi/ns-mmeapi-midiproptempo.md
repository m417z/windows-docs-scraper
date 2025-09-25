# MIDIPROPTEMPO structure

## Description

The **MIDIPROPTEMPO** structure contains the tempo property for a stream.

## Members

### `cbStruct`

Length, in bytes, of this structure. This member must be filled in for both the MIDIPROP_SET and MIDIPROP_GET operations of the [midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85)) function.

### `dwTempo`

Tempo of the stream, in microseconds per quarter note. The tempo is honored only if the time division for the stream is specified in quarter note format. This member is set in a MIDIPROP_SET operation and is filled on return from a MIDIPROP_GET operation.

## Remarks

The tempo property is read or written by the [midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85)) function.

## See also

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)

[midiStreamProperty](https://learn.microsoft.com/previous-versions/dd798490(v=vs.85))