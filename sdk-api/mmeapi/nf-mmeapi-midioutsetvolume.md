# midiOutSetVolume function

## Description

The **midiOutSetVolume** function sets the volume of a MIDI output device.

## Parameters

### `hmo`

Handle to an open MIDI output device. This parameter can also contain the handle of a MIDI stream, as long as it is cast to **HMIDIOUT**. This parameter can also be a device identifier.

### `dwVolume`

New volume setting. The low-order word contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of *dwVolume* specifies the mono volume level, and the high-order word is ignored.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | The specified device handle is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate or lock memory. |
| **MMSYSERR_NOTSUPPORTED** | The function is not supported. |

## Remarks

If a device identifier is used, then the result of the **midiOutSetVolume** call applies to all instances of the device. If a device handle is used, then the result applies only to the instance of the device referenced by the device handle.

Not all devices support volume changes. You can determine whether a device supports it by querying the device using the [midiOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd798469(v=vs.85)) function and the MIDICAPS_VOLUME flag.

You can also determine whether the device supports volume control on both the left and right channels by querying the device using the [midiOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd798469(v=vs.85)) function and the MIDICAPS_LRVOLUME flag.

Devices that do not support a full 16 bits of volume-level control use the high-order bits of the requested volume setting. For example, a device that supports 4 bits of volume control produces the same volume setting for the following volume-level values: 0x4000, 0x43be, and 0x4fff. The [midiOutGetVolume](https://learn.microsoft.com/previous-versions/dd798473(v=vs.85)) function returns the full 16-bit value, as set by **midiOutSetVolume**, irrespective of the device's capabilities.

Volume settings are interpreted logarithmically. This means that the perceived increase in volume is the same when increasing the volume level from 0x5000 to 0x6000 as it is from 0x4000 to 0x5000.

## See also

[MIDI Functions](https://learn.microsoft.com/windows/desktop/Multimedia/midi-functions)