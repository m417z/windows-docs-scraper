# midiOutGetVolume function

## Description

The **midiOutGetVolume** function retrieves the current volume setting of a MIDI output device.

## Parameters

### `hmo`

Handle to an open MIDI output device. This parameter can also contain the handle of a MIDI stream, as long as it is cast to **HMIDIOUT**. This parameter can also be a device identifier.

### `pdwVolume`

Pointer to the location to contain the current volume setting. The low-order word of this location contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of the specified location contains the mono volume level.

Any value set by using the [midiOutSetVolume](https://learn.microsoft.com/previous-versions/dd798480(v=vs.85)) function is returned, regardless of whether the device supports that value.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_INVALPARAM** | The specified pointer or structure is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |
| **MMSYSERR_NOTSUPPORTED** | The function is not supported. |

## Remarks

If a device identifier is used, then the result of the **midiOutGetVolume** call and the information returned in *lpdwVolume* applies to all instances of the device. If a device handle is used, then the result and information returned applies only to the instance of the device referenced by the device handle.

Not all devices support volume control. You can determine whether a device supports volume control by querying the device by using the [midiOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd798469(v=vs.85)) function and specifying the MIDICAPS_VOLUME flag.

You can also determine whether the device supports volume control on both the left and right channels by querying the device by using the [midiOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd798469(v=vs.85)) function and specifying the MIDICAPS_LRVOLUME flag.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)