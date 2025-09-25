# waveOutPause function

## Description

The **waveOutPause** function pauses playback on the given waveform-audio output device. The current position is saved. Use the [waveOutRestart](https://learn.microsoft.com/previous-versions/dd743871(v=vs.85)) function to resume playback from the current position.

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

Calling this function when the output is already paused has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)