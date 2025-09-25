# waveInStart function

## Description

The **waveInStart** function starts input on the given waveform-audio input device.

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

Buffers are returned to the application when full or when the **waveInReset** function is called (the **dwBytesRecorded** member in the header will contain the length of data). If there are no buffers in the queue, the data is thrown away without notifying the application, and input continues.

Calling this function when input is already started has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)