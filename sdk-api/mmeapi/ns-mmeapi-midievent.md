# MIDIEVENT structure

## Description

The MIDIEVENT structure describes a MIDI event in a stream buffer.

## Members

### `dwDeltaTime`

Time, in MIDI ticks, between the previous event and the current event. The length of a tick is defined by the time format and possibly the tempo associated with the stream. (The definition is identical to the specification for a tick in a standard MIDI file.)

### `dwStreamID`

Reserved; must be zero.

### `dwEvent`

Event code and event parameters or length. To parse this information, use the [MEVT_EVENTTYPE](https://learn.microsoft.com/previous-versions/dd798442(v=vs.85)) and [MEVT_EVENTPARM](https://learn.microsoft.com/previous-versions/dd798441(v=vs.85)) macros. See Remarks.

### `dwParms`

If **dwEvent** specifies MEVT_F_LONG and the length of the buffer, this member contains parameters for the event. This parameter data must be padded with zeros so that an integral number of **DWORD** values are stored. For example, if the event data is five bytes long, three pad bytes must follow the data for a total of eight bytes. In this case, the low 24 bits of **dwEvent** would contain the value 5.

If **dwEvent** specifies MEVT_F_SHORT, do not use this member in the stream buffer.

## Remarks

The high byte of **dwEvent** contains flags and an event code. Either the MEVT_F_LONG or MEVT_F_SHORT flag must be specified. The MEVT_F_CALLBACK flag is optional. The following table describes these flags.

| Flag | Meaning |
| --- | --- |
| MEVT_F_CALLBACK | The system generates a callback when the event is about to be executed. |
| MEVT_F_LONG | The event is a long event. The low 24 bits of dwEvent contain the length of the event parameters included in dwParms. |
| MEVT_F_SHORT | The event is a short event. The event parameters are contained in the low 24 bits of dwEvent. |

The remainder of the high byte contains one of the following event codes:

| Event Code | Meaning |
| --- | --- |
| MEVT_COMMENT | Long event. The event data will be ignored. This event is intended to store commentary information about the stream that might be useful to authoring programs or sequencers if the stream data were to be stored in a file in stream format. In a buffer of this data, the zero byte identifies the comment class and subsequent bytes contain the comment data. |
| MEVT_LONGMSG | Long event. The event data is transmitted verbatim. The event data is assumed to be system-exclusive data; that is, running status will be cleared when the event is executed and running status from any previous events will not be applied to any channel events in the event data. Using this event to send a group of channel messages at the same time is not recommended; a set of MEVT_SHORTMSG events with zero delta times should be used instead. |
| MEVT_NOP | Short event. This event is a placeholder; it does nothing. The low 24 bits are ignored. This event will still generate a callback if MEVT_F_CALLBACK is set in dwEvent. |
| MEVT_SHORTMSG | Short event. The data in the low 24 bits of dwEvent is a MIDI short message. (For a description of how a short message is packed into a DWORD value, see the midiOutShortMsg function.) |
| MEVT_TEMPO | Short event. The data in the low 24 bits of dwEvent contain the new tempo for following events. The tempo is specified in the same format as it is for the tempo change meta-event in a MIDI file — that is, in microseconds per quarter note. (This event will have no effect if the time format specified for the stream is SMPTE time.) |
| MEVT_VERSION | Long event. The event data must contain a MIDISTRMBUFFVER structure. |

## See also

[MEVT_EVENTPARM](https://learn.microsoft.com/previous-versions/dd798441(v=vs.85))

[MEVT_EVENTTYPE](https://learn.microsoft.com/previous-versions/dd798442(v=vs.85))

[MIDI Structures](https://learn.microsoft.com/windows/desktop/Multimedia/midi-structures)

[MIDISTRMBUFFVER](https://learn.microsoft.com/previous-versions/dd798493(v=vs.85))

[Musical Instrument Digital Interface (MIDI)](https://learn.microsoft.com/windows/desktop/Multimedia/musical-instrument-digital-interface--midi)

[midiOutShortMsg](https://learn.microsoft.com/previous-versions/dd798481(v=vs.85))