# waveInStop function

## Description

The **waveInStop** function stops waveform-audio input.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

If there are any buffers in the queue, the current buffer will be marked as done (the **dwBytesRecorded** member in the header will contain the length of data), but any empty buffers in the queue will remain there.

Calling this function when input is not started has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)