# waveOutBreakLoop function

## Description

The **waveOutBreakLoop** function breaks a loop on the given waveform-audio output device and allows playback to continue with the next block in the driver list.

## Parameters

### `hwo`

Handle to the waveform-audio output device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

The blocks making up the loop are played to the end before the loop is terminated.

Calling this function when nothing is playing or looping has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)