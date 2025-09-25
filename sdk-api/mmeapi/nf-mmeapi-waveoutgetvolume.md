# waveOutGetVolume function

## Description

The **waveOutGetVolume** function retrieves the current volume level of the specified waveform-audio output device.

## Parameters

### `hwo`

Handle to an open waveform-audio output device. This parameter can also be a device identifier.

### `pdwVolume`

Pointer to a variable to be filled with the current volume setting. The low-order word of this location contains the left-channel volume setting, and the high-order word contains the right-channel setting. A value of 0xFFFF represents full volume, and a value of 0x0000 is silence.

If a device does not support both left and right volume control, the low-order word of the specified location contains the mono volume level.

The full 16-bit setting(s) set with the [waveOutSetVolume](https://learn.microsoft.com/previous-versions/dd743874(v=vs.85)) function is returned, regardless of whether the device supports the full 16 bits of volume-level control.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **MMSYSERR_NOTSUPPORTED** | Function isn't supported. |

## Remarks

If a device identifier is used, then the result of the **waveOutGetVolume** call and the information returned in *pdwVolume* applies to all instances of the device. If a device handle is used, then the result and information returned applies only to the instance of the device referenced by the device handle.

Not all devices support volume changes. To determine whether the device supports volume control, use the WAVECAPS_VOLUME flag to test the **dwSupport** member of the **WAVEOUTCAPS** structure (filled by the **waveOutGetDevCaps** function).

To determine whether the device supports left- and right-channel volume control, use the WAVECAPS_LRVOLUME flag to test the **dwSupport** member of the **WAVEOUTCAPS** structure (filled by **waveOutGetDevCaps**).

Volume settings are interpreted logarithmically. This means the perceived increase in volume is the same when increasing the volume level from 0x5000 to 0x6000 as it is from 0x4000 to 0x5000.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)