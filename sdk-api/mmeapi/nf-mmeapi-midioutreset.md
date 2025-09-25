# midiOutReset function

## Description

The **midiOutReset** function turns off all notes on all MIDI channels for the specified MIDI output device.

## Parameters

### `hmo`

Handle to the MIDI output device. This parameter can also be the handle of a MIDI stream cast to **HMIDIOUT**.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

Any pending system-exclusive or stream output buffers are returned to the callback function and the MHDR_DONE flag is set in the **dwFlags** member of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

Terminating a system-exclusive message without sending an EOX (end-of-exclusive) byte might cause problems for the receiving device. The **midiOutReset** function does not send an EOX byte when it terminates a system-exclusive message - applications are responsible for doing this.

To turn off all notes, a note-off message for each note in each channel is sent. In addition, the sustain controller is turned off for each channel.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)