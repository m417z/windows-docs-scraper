# midiOutGetDevCaps function

## Description

The **midiOutGetDevCaps** function queries a specified MIDI output device to determine its capabilities.

## Parameters

### `uDeviceID`

Identifier of the MIDI output device. The device identifier specified by this parameter varies from zero to one less than the number of devices present. The MIDI_MAPPER constant is also a valid device identifier.

This parameter can also be a properly cast device handle.

### `pmoc`

Pointer to a [MIDIOUTCAPS](https://learn.microsoft.com/previous-versions/dd798467(v=vs.85)) structure. This structure is filled with information about the capabilities of the device.

### `cbmoc`

Size, in bytes, of the [MIDIOUTCAPS](https://learn.microsoft.com/previous-versions/dd798467(v=vs.85)) structure. Only *cbMidiOutCaps* bytes (or less) of information is copied to the location pointed to by *lpMidiOutCaps*. If *cbMidiOutCaps* is zero, nothing is copied, and the function returns MMSYSERR_NOERROR.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NODRIVER** | The driver is not installed. |
| **MMSYSERR_NOMEM** | The system is unable to load mapper string description. |

## Remarks

To determine the number of MIDI output devices present in the system, use the [midiOutGetNumDevs](https://learn.microsoft.com/previous-versions/dd798472(v=vs.85)) function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)