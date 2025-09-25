# waveInAddBuffer function

## Description

The **waveInAddBuffer** function sends an input buffer to the given waveform-audio input device. When the buffer is filled, the application is notified.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure that identifies the buffer.

### `cbwh`

Size, in bytes, of the **WAVEHDR** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_UNPREPARED** | The buffer pointed to by the *pwh* parameter hasn't been prepared. |

## Remarks

When the buffer is filled, the WHDR_DONE bit is set in the **dwFlags** member of the **WAVEHDR** structure.

The buffer must be prepared with the **waveInPrepareHeader** function before it is passed to this function.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)