# _SERIAL_CHARS structure

## Description

The **SERIAL_CHARS** structure specifies the special characters that the serial controller driver uses for handshake flow control.

## Members

### `EofChar`

The EOF (end of file) character. Receipt of this character marks the end of the input stream.

### `ErrorChar`

The parity error replacement character. Bytes received with parity errors are replaced by this character.

### `BreakChar`

The break character. Receipt of this character indicates that a break (temporary pause) occurred in the input stream.

### `EventChar`

The event character. Receipt of this character signals a serial communication event if the SERIAL_EV_RXFLAG flag bit is set in the current wait mask. The wait mask is set by the [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request. The [IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask) request initiates a wait for the events in the wait mask.

### `XonChar`

The XON (transmit on) character to use for both transmit and receive operations. The XON and XOFF characters are used for software flow control.

### `XoffChar`

The XOFF (transmit off) character to use for both transmit and receive operations.

## Remarks

This structure is used by the [IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars) and [IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars) requests.

An **IOCTL_SERIAL_SET_CHARS** request to set the XON and XOFF characters to the same value will fail.

## See also

[IOCTL_SERIAL_GET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_chars)

[IOCTL_SERIAL_SET_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_chars)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)