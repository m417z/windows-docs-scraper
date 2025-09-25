# midiInGetDevCaps function

## Description

The **midiInGetDevCaps** function determines the capabilities of a specified MIDI input device.

## Parameters

### `uDeviceID`

Identifier of the MIDI input device. The device identifier varies from zero to one less than the number of devices present. This parameter can also be a properly cast device handle.

### `pmic`

Pointer to a [MIDIINCAPS](https://learn.microsoft.com/previous-versions/dd798451(v=vs.85)) structure that is filled with information about the capabilities of the device.

### `cbmic`

Size, in bytes, of the [MIDIINCAPS](https://learn.microsoft.com/previous-versions/dd798451(v=vs.85)) structure. Only *cbMidiInCaps* bytes (or less) of information is copied to the location pointed to by *lpMidiInCaps*. If *cbMidiInCaps* is zero, nothing is copied, and the function returns MMSYSERR_NOERROR.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_BADDEVICEID** | The specified device identifier is out of range. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NODRIVER** | The driver is not installed. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |

## Remarks

To determine the number of MIDI input devices present on the system, use the [midiInGetNumDevs](https://learn.microsoft.com/previous-versions/dd798456(v=vs.85)) function.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)