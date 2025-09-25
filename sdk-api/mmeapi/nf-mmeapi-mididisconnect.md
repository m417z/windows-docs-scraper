# midiDisconnect function

## Description

The **midiDisconnect** function disconnects a MIDI input device from a MIDI thru or output device, or disconnects a MIDI thru device from a MIDI output device.

## Parameters

### `hmi`

Handle to a MIDI input device or a MIDI thru device.

### `hmo`

Handle to the MIDI output device to be disconnected.

### `pReserved`

Reserved; must be **NULL**.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following:.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |

## Remarks

MIDI input, output, and thru devices can be connected by using the **midiConnect** function. Thereafter, whenever the MIDI input device receives event data in an MIM_DATA message, a message with the same event data is sent to the output device driver (or through the thru driver to the output drivers).

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)