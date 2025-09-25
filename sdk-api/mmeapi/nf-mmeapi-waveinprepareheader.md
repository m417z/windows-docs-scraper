# waveInPrepareHeader function

## Description

The **waveInPrepareHeader** function prepares a buffer for waveform-audio input.

## Parameters

### `hwi`

Handle to the waveform-audio input device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure that identifies the buffer to be prepared.

### `cbwh`

Size, in bytes, of the **WAVEHDR** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

The **lpData**, **dwBufferLength**, and **dwFlags** members of the **WAVEHDR** structure must be set before calling this function (**dwFlags** must be zero).

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)