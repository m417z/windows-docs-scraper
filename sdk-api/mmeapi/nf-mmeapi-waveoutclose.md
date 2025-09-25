# waveOutClose function

## Description

The **waveOutClose** function closes the given waveform-audio output device.

## Parameters

### `hwo`

Handle to the waveform-audio output device. If the function succeeds, the handle is no longer valid after this call.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_STILLPLAYING** | There are still buffers in the queue. |

## Remarks

The close operation fails if the device is still playing a waveform-audio buffer that was previously sent by calling **waveOutWrite**. Before calling **waveOutClose**, the application must wait for all buffers to finish playing or call the **waveOutReset** function to terminate playback.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)