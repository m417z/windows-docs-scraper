# waveOutReset function

## Description

The **waveOutReset** function stops playback on the given waveform-audio output device and resets the current position to zero. All pending playback buffers are marked as done (WHDR_DONE) and returned to the application.

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
| **MMSYSERR_NOTSUPPORTED** | Specified device is synchronous and does not support pausing. |

## Remarks

After this function returns, the application can send new playback buffers to the device by calling [waveOutWrite](https://learn.microsoft.com/previous-versions/dd743876(v=vs.85)), or close the device by calling [waveOutClose](https://learn.microsoft.com/previous-versions/dd743856(v=vs.85)).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)