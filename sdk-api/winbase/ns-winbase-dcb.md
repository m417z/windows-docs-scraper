# DCB structure

## Description

Defines the control setting for a serial communications device.

## Members

### `DCBlength`

The length of the structure, in bytes. The caller must set this member to
`sizeof(DCB)`.

### `BaudRate`

The baud rate at which the communications device operates. This member can be an actual baud rate value, or
one of the following indexes.

| Value | Meaning |
| --- | --- |
| **CBR_110**<br><br>110 | 110 bps |
| **CBR_300**<br><br>300 | 300 bps |
| **CBR_600**<br><br>600 | 600 bps |
| **CBR_1200**<br><br>1200 | 1200 bps |
| **CBR_2400**<br><br>2400 | 2400 bps |
| **CBR_4800**<br><br>4800 | 4800 bps |
| **CBR_9600**<br><br>9600 | 9600 bps |
| **CBR_14400**<br><br>14400 | 14400 bps |
| **CBR_19200**<br><br>19200 | 19200 bps |
| **CBR_38400**<br><br>38400 | 38400 bps |
| **CBR_57600**<br><br>57600 | 57600 bps |
| **CBR_115200**<br><br>115200 | 115200 bps |
| **CBR_128000**<br><br>128000 | 128000 bps |
| **CBR_256000**<br><br>256000 | 256000 bps |

### `fBinary`

If this member is **TRUE**, binary mode is enabled. Windows does not support
nonbinary mode transfers, so this member must be **TRUE**.

### `fParity`

If this member is **TRUE**, parity checking is performed and errors are
reported.

### `fOutxCtsFlow`

If this member is **TRUE**, the CTS (clear-to-send) signal is monitored for output
flow control. If this member is **TRUE** and CTS is turned off, output is suspended until
CTS is sent again.

### `fOutxDsrFlow`

If this member is **TRUE**, the DSR (data-set-ready) signal is monitored for output
flow control. If this member is **TRUE** and DSR is turned off, output is suspended until
DSR is sent again.

### `fDtrControl`

The DTR (data-terminal-ready) flow control. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DTR_CONTROL_DISABLE**<br><br>0x00 | Disables the DTR line when the device is opened and leaves it disabled. |
| **DTR_CONTROL_ENABLE**<br><br>0x01 | Enables the DTR line when the device is opened and leaves it on. |
| **DTR_CONTROL_HANDSHAKE**<br><br>0x02 | Enables DTR handshaking. If handshaking is enabled, it is an error for the application to adjust the line by using the [EscapeCommFunction](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-escapecommfunction) function. |

### `fDsrSensitivity`

If this member is **TRUE**, the communications driver is sensitive to the state of
the DSR signal. The driver ignores any bytes received, unless the DSR modem input line is high.

### `fTXContinueOnXoff`

If this member is **TRUE**, transmission continues after the input buffer has come
within **XoffLim** bytes of being full and the driver has transmitted the
**XoffChar** character to stop receiving bytes. If this member is
**FALSE**, transmission does not continue until the input buffer is within
**XonLim** bytes of being empty and the driver has transmitted
the **XonChar** character to resume reception.

### `fOutX`

Indicates whether XON/XOFF flow control is used during transmission. If this member is
**TRUE**, transmission stops when the **XoffChar** character is
received and starts again when the **XonChar** character is received.

### `fInX`

Indicates whether XON/XOFF flow control is used during reception. If this member is
**TRUE**, the **XoffChar** character is sent when the input buffer
comes within **XoffLim** bytes of being full, and the **XonChar**
character is sent when the input buffer comes within **XonLim** bytes of being
empty.

### `fErrorChar`

Indicates whether bytes received with parity errors are replaced with the character specified by the
**ErrorChar** member. If this member is **TRUE** and the
**fParity** member is **TRUE**, replacement occurs.

### `fNull`

If this member is **TRUE**, null bytes are discarded when received.

### `fRtsControl`

The RTS (request-to-send) flow control. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RTS_CONTROL_DISABLE**<br><br>0x00 | Disables the RTS line when the device is opened and leaves it disabled. |
| **RTS_CONTROL_ENABLE**<br><br>0x01 | Enables the RTS line when the device is opened and leaves it on. |
| **RTS_CONTROL_HANDSHAKE**<br><br>0x02 | Enables RTS handshaking. The driver raises the RTS line when the "type-ahead" (input) buffer is less than one-half full and lowers the RTS line when the buffer is more than three-quarters full. If handshaking is enabled, it is an error for the application to adjust the line by using the [EscapeCommFunction](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-escapecommfunction) function. |
| **RTS_CONTROL_TOGGLE**<br><br>0x03 | Specifies that the RTS line will be high if bytes are available for transmission. After all buffered bytes have been sent, the RTS line will be low. |

### `fAbortOnError`

If this member is **TRUE**, the driver terminates all read and write operations with
an error status if an error occurs. The driver will not accept any further communications operations until the
application has acknowledged the error by calling the
[ClearCommError](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommerror) function.

### `fDummy2`

Reserved; do not use.

### `wReserved`

Reserved; must be zero.

### `XonLim`

The minimum number of bytes in use allowed in the input buffer before flow control is activated to allow
transmission by the sender. This assumes that either XON/XOFF, RTS, or DTR input flow control is specified in
the **fInX**, **fRtsControl**, or
**fDtrControl** members.

### `XoffLim`

The minimum number of free bytes allowed in the input buffer before flow control is activated to inhibit
the sender. Note that the sender may transmit characters after the flow control signal has been activated, so
this value should never be zero. This assumes that either XON/XOFF, RTS, or DTR input flow control is specified
in the **fInX**, **fRtsControl**, or
**fDtrControl** members. The maximum number of bytes in use allowed is calculated by
subtracting this value from the size, in bytes, of the input buffer.

### `ByteSize`

The number of bits in the bytes transmitted and received.

### `Parity`

The parity scheme to be used. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **EVENPARITY**<br><br>2 | Even parity. |
| **MARKPARITY**<br><br>3 | Mark parity. |
| **NOPARITY**<br><br>0 | No parity. |
| **ODDPARITY**<br><br>1 | Odd parity. |
| **SPACEPARITY**<br><br>4 | Space parity. |

### `StopBits`

The number of stop bits to be used. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ONESTOPBIT**<br><br>0 | 1 stop bit. |
| **ONE5STOPBITS**<br><br>1 | 1.5 stop bits. |
| **TWOSTOPBITS**<br><br>2 | 2 stop bits. |

### `XonChar`

The value of the XON character for both transmission and reception.

### `XoffChar`

The value of the XOFF character for both transmission and reception.

### `ErrorChar`

The value of the character used to replace bytes received with a parity error.

### `EofChar`

The value of the character used to signal the end of data.

### `EvtChar`

The value of the character used to signal an event.

### `wReserved1`

Reserved; do not use.

## Remarks

When a **DCB** structure is used to configure the 8250, the
following restrictions apply to the values specified for the **ByteSize** and
**StopBits** members:

* The number of data bits must be 5 to 8 bits.
* The use of 5 data bits with 2 stop bits is an invalid combination, as is 6, 7, or 8 data bits with 1.5 stop
  bits.

## See also

[BuildCommDCB](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-buildcommdcba)

[ClearCommError](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-clearcommerror)

[EscapeCommFunction](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-escapecommfunction)

[GetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommstate)

[SetCommState](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setcommstate)