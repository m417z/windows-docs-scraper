# waveOutWrite function

## Description

The **waveOutWrite** function sends a data block to the given waveform-audio output device.

## Parameters

### `hwo`

Handle to the waveform-audio output device.

### `pwh`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure containing information about the data block.

### `cbwh`

Size, in bytes, of the **WAVEHDR** structure.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALHANDLE** | Specified device handle is invalid. |
| **MMSYSERR_NODRIVER** | No device driver is present. |
| **MMSYSERR_NOMEM** | Unable to allocate or lock memory. |
| **WAVERR_UNPREPARED** | The data block pointed to by the *pwh* parameter hasn't been prepared. |

## Remarks

When the buffer is finished, the WHDR_DONE bit is set in the **dwFlags** member of the **WAVEHDR** structure.

The buffer must be prepared with the **waveOutPrepareHeader** function before it is passed to **waveOutWrite**. Unless the device is paused by calling the **waveOutPause** function, playback begins when the first data block is sent to the device.

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Functions](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-functions)