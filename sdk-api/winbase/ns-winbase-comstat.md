# COMSTAT structure

## Description

Contains information about a communications device. This structure is filled by the
[ClearCommError](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommerror) function.

## Members

### `fCtsHold`

If this member is **TRUE**, transmission is waiting for the CTS (clear-to-send) signal to be sent.

### `fDsrHold`

If this member is **TRUE**, transmission is waiting for the DSR (data-set-ready) signal to be sent.

### `fRlsdHold`

If this member is **TRUE**, transmission is waiting for the RLSD (receive-line-signal-detect) signal to be sent.

### `fXoffHold`

If this member is **TRUE**, transmission is waiting because the XOFF character was received.

### `fXoffSent`

If this member is **TRUE**, transmission is waiting because the XOFF character was transmitted. (Transmission halts when the XOFF character is transmitted to a system that takes the next character as XON, regardless of the actual character.)

### `fEof`

If this member is **TRUE**, the end-of-file (EOF) character has been received.

### `fTxim`

If this member is **TRUE**, there is a character queued for transmission that has come to the communications device by way of the
[TransmitCommChar](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-transmitcommchar) function. The communications device transmits such a character ahead of other characters in the device's output buffer.

### `fReserved`

Reserved; do not use.

### `cbInQue`

The number of bytes received by the serial provider but not yet read by a
[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile) operation.

### `cbOutQue`

The number of bytes of user data remaining to be transmitted for all write operations. This value will be zero for a nonoverlapped write.

## See also

[ClearCommError](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommerror)

[ReadFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfile)

[TransmitCommChar](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-transmitcommchar)