# waveOutSetVolume function

## Description

The **waveOutSetVolume** function sets the volume level of the specified waveform-audio output device.

## Parameters

### `hwo`

Handle to an open waveform-audio output device. This parameter can also be a device identifier.

### `dwVolume`

New volume setting. The low-order word contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of *dwVolume* specifies the volume level, and the high-order word is ignored.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **MMSYSERR_NOTSUPPORTED** | Function is not supported. |

## Remarks

If a device identifier is used, then the result of the **waveOutSetVolume** call applies to all instances of the device. If a device handle is used, then the result applies only to the instance of the device referenced by the device handle.

Not all devices support volume changes. To determine whether the device supports volume control, use the WAVECAPS_VOLUME flag to test the **dwSupport** member of the [WAVEOUTCAPS](https://learn.microsoft.com/previous-versions/dd743855(v=vs.85)) structure (filled by the [waveOutGetDevCaps](https://learn.microsoft.com/previous-versions/dd743857(v=vs.85)) function). To determine whether the device supports volume control on both the left and right channels, use the WAVECAPS_LRVOLUME flag.

Most devices do not support the full 16 bits of volume-level control and will not use the least-significant bits of the requested volume setting. For example, if a device supports 4 bits of volume control, the values 0x4000, 0x4FFF, and 0x43BE will all be truncated to 0x4000. The **waveOutGetVolume** function returns the full 16-bit setting set with **waveOutSetVolume**.

Volume settings are interpreted logarithmically. This means the perceived increase in volume is the same when increasing the volume level from 0x5000 to 0x6000 as it is from 0x4000 to 0x5000.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)