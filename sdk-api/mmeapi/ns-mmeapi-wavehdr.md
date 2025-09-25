# WAVEHDR structure

## Description

The **WAVEHDR** structure defines the header used to identify a waveform-audio buffer.

## Members

### `lpData`

Pointer to the waveform buffer.

### `dwBufferLength`

Length, in bytes, of the buffer.

### `dwBytesRecorded`

When the header is used in input, specifies how much data is in the buffer.

### `dwUser`

User data.

### `dwFlags`

A bitwise **OR** of zero or more flags. The following flags are defined:

| Name | Description |
| --- | --- |
| **WHDR_BEGINLOOP** | This buffer is the first buffer in a loop. This flag is used only with output buffers. |
| **WHDR_DONE** | Set by the device driver to indicate that it is finished with the buffer and is returning it to the application. |
| **WHDR_ENDLOOP** | This buffer is the last buffer in a loop. This flag is used only with output buffers. |
| **WHDR_INQUEUE** | Set by Windows to indicate that the buffer is queued for playback. |
| **WHDR_PREPARED** | Set by Windows to indicate that the buffer has been prepared with the [waveInPrepareHeader](https://learn.microsoft.com/previous-versions/dd743848(v=vs.85)) or [waveOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd743868(v=vs.85)) function. |

### `dwLoops`

Number of times to play the loop. This member is used only with output buffers.

### `lpNext`

Reserved.

### `reserved`

Reserved.

## Remarks

Use the WHDR_BEGINLOOP and WHDR_ENDLOOP flags in the **dwFlags** member to specify the beginning and ending data blocks for looping. To loop on a single block, specify both flags for the same block. Use the **dwLoops** member in the **WAVEHDR** structure for the first block in the loop to specify the number of times to play the loop.

The **lpData**, **dwBufferLength**, and **dwFlags** members must be set before calling the [waveInPrepareHeader](https://learn.microsoft.com/previous-versions/dd743848(v=vs.85)) or [waveOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd743868(v=vs.85)) function. (For either function, the **dwFlags** member must be set to zero.)

## See also

[Waveform Audio](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-audio)

[Waveform Structures](https://learn.microsoft.com/windows/desktop/Multimedia/waveform-structures)

[waveInPrepareHeader](https://learn.microsoft.com/previous-versions/dd743848(v=vs.85))

[waveOutPrepareHeader](https://learn.microsoft.com/previous-versions/dd743868(v=vs.85))