# waveOutPrepareHeader function

## Description

The **waveOutPrepareHeader** function prepares a waveform-audio data block for playback.

## Parameters

### `hwo`

Handle to the waveform-audio output device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure that identifies the data block to be prepared.

### `cbwh`

Size, in bytes, of the [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure.

## Return value

Returns **MMSYSERR_NOERROR** if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |

## Remarks

Set the **lpData**, **dwBufferLength**, and **dwFlags** members of the [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure before calling this function. Set the **dwFlags** member to zero.

The **dwFlags**, **dwBufferLength**, and **dwLoops** members of the [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure can change between calls to this function and the [waveOutWrite](https://learn.microsoft.com/previous-versions/dd743876(v=vs.85)) function. If you change the size specified by **dwBufferLength** before the call to **waveOutWrite**, the new value must be less than the prepared value.

If the method succeeds, the **WHDR_PREPARED** flag is set in the **dwFlags** member of the [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure.

Preparing a header that has already been prepared has no effect, and the function returns zero.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)