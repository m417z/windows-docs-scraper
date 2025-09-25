# midiConnect function

## Description

The **midiConnect** function connects a MIDI input device to a MIDI thru or output device, or connects a MIDI thru device to a MIDI output device.

## Parameters

### `hmi`

Handle to a MIDI input device or a MIDI thru device. (For thru devices, this handle must have been returned by a call to the [midiOutOpen](https://learn.microsoft.com/previous-versions/dd798476(v=vs.85)) function.)

### `hmo`

Handle to the MIDI output or thru device.

### `pReserved`

Reserved; must be **NULL**.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MIDIERR_NOTREADY** | Specified input device is already connected to an output device. |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |

## Remarks

After calling this function, the MIDI input device receives event data in an MIM_DATA message whenever a message with the same event data is sent to the output device driver.

A thru driver is a special form of MIDI output driver. The system will allow only one MIDI output device to be connected to a MIDI input device, but multiple MIDI output devices can be connected to a MIDI thru device. Whenever the given MIDI input device receives event data in an MIM_DATA message, a message with the same event data is sent to the given output device driver (or through the thru driver to the output drivers).

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)