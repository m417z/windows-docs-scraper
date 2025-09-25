# VIDEOHDR structure

## Description

The **VIDEOHDR** structure is used by the [capVideoStreamCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capvideocallback) function.

## Members

### `lpData`

Pointer to locked data buffer.

### `dwBufferLength`

Length of data buffer.

### `dwBytesUsed`

Bytes actually used.

### `dwTimeCaptured`

Milliseconds from start of stream.

### `dwUser`

User-defined data.

### `dwFlags`

The flags are defined as follows.

| Flag | Meaning |
| --- | --- |
| VHDR_DONE | Done bit |
| VHDR_PREPARED | Set if this header has been prepared |
| VHDR_INQUEUE | Reserved for driver |
| VHDR_KEYFRAME | Key Frame |

### `dwReserved`

Reserved for driver.

## See also

[Multimedia Timer Structures](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timer-structures)

[Multimedia Timers](https://learn.microsoft.com/windows/desktop/Multimedia/multimedia-timers)

[capVideoStreamCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capvideocallback)