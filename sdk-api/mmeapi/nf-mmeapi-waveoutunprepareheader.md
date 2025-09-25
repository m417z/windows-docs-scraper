# waveOutUnprepareHeader function

## Description

The **waveOutUnprepareHeader** function cleans up the preparation performed by the [waveOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd743868(v=vs.85)) function. This function must be called after the device driver is finished with a data block. You must call this function before freeing the buffer.

## Parameters

### `hwo`

Handle to the waveform-audio output device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure identifying the data block to be cleaned up.

### `cbwh`

Size, in bytes, of the **WAVEHDR** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_STILLPLAYING** | The data block pointed to by the *pwh* parameter is still in the queue. |

## Remarks

This function complements **waveOutPrepareHeader**. You must call this function before freeing the buffer. After passing a buffer to the device driver with the **waveOutWrite** function, you must wait until the driver is finished with the buffer before calling **waveOutUnprepareHeader**.

Unpreparing a buffer that has not been prepared has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)