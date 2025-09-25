# waveOutSetPlaybackRate function

## Description

The **waveOutSetPlaybackRate** function sets the playback rate for the specified waveform-audio output device.

## Parameters

### `hwo`

Handle to the waveform-audio output device.

### `dwRate`

New playback rate setting. This setting is a multiplier indicating the current change in playback rate from the original authored setting. The playback rate multiplier must be a positive value.

The rate is specified as a fixed-point value. The high-order word contains the signed integer part of the number, and the low-order word contains the fractional part. A value of 0x8000 in the low-order word represents one-half, and 0x4000 represents one-quarter. For example, the value 0x00010000 specifies a multiplier of 1.0 (no playback rate change), and a value of 0x000F8000 specifies a multiplier of 15.5.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **MMSYSERR_NOTSUPPORTED** | Function isn't supported. |

## Remarks

Changing the playback rate does not change the sample rate but does change the playback time. Not all devices support playback rate changes. To determine whether a device supports playback rate changes, use the WAVECAPS_PLAYBACKRATE flag to test the **dwSupport** member of the **WAVEOUTCAPS** structure (filled by the **waveOutGetDevCaps** function).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)