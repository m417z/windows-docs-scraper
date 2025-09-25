# midiInReset function

## Description

The **midiInReset** function stops input on a given MIDI input device.

## Parameters

### `hmi`

Handle to the MIDI input device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |

## Remarks

This function returns all pending input buffers to the callback function and sets the MHDR_DONE flag in the **dwFlags** member of the [MIDIHDR](https://learn.microsoft.com/previous-versions/dd798449(v=vs.85)) structure.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)