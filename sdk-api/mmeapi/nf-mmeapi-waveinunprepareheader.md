# waveInUnprepareHeader function

## Description

The **waveInUnprepareHeader** function cleans up the preparation performed by the [waveInPrepareHeader](https://learn.microsoft.com/previous-versions/dd743848(v=vs.85)) function. This function must be called after the device driver fills a buffer and returns it to the application. You must call this function before freeing the buffer.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure identifying the buffer to be cleaned up.

### `cbwh`

Size, in bytes, of the **WAVEHDR** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_STILLPLAYING** | The buffer pointed to by the *pwh* parameter is still in the queue. |

## Remarks

This function complements the **waveInPrepareHeader** function.

You must call this function before freeing the buffer. After passing a buffer to the device driver with the **waveInAddBuffer** function, you must wait until the driver is finished with the buffer before calling **waveInUnprepareHeader**. Unpreparing a buffer that has not been prepared has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)