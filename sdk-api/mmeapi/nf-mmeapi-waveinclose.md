# waveInClose function

## Description

The **waveInClose** function closes the given waveform-audio input device.

## Parameters

### `hwi`

Handle to the waveform-audio input device. If the function succeeds, the handle is no longer valid after this call.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_STILLPLAYING** | There are still buffers in the queue. |

## Remarks

If there are input buffers that have been sent with the **waveInAddBuffer** function and that haven't been returned to the application, the close operation will fail. Call the **waveInReset** function to mark all pending buffers as done.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)