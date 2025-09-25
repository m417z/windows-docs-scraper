# midiStreamPosition function

## Description

The **midiStreamPosition** function retrieves the current position in a MIDI stream.

## Parameters

### `hms`

Handle to a MIDI stream. This handle must have been returned by a call to the [midiStreamOpen](https://learn.microsoft.com/previous-versions/dd798486(v=vs.85)) function. This handle identifies the output device.

### `lpmmt`

Pointer to an [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

### `cbmmt`

Size, in bytes, of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | Specified pointer or structure is invalid. |

## Remarks

Before calling **midiStreamPosition**, set the **wType** member of the [MMTIME](https://learn.microsoft.com/previous-versions/dd757347(v=vs.85)) structure to indicate the time format you desire. After calling **midiStreamPosition**, check the **wType** member to determine if the desired time format is supported. If the desired format is not supported, **wType** will specify an alternative format.

The position is set to zero when the device is opened or reset.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)