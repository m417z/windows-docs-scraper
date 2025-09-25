# _SERIAL_STATUS structure

## Description

The **SERIAL_STATUS** structure contains status information about the serial port.

## Members

### `Errors`

A set of flags to indicate the receive errors that have occurred in the input stream. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Flag name | Meaning |
| --- | --- |
| SERIAL_ERROR_QUEUEOVERRUN | The serial controller driver's internal input buffer was overrun by data received from the input stream. Either the input buffer is full, or a character was received after the EOF (end of file) character. |
| SERIAL_ERROR_OVERRUN | The hardware receive FIFO was overrun by data received from the input stream. |
| SERIAL_ERROR_BREAK | A break condition occurred on the input line. |
| SERIAL_ERROR_PARITY | A parity error was detected in a byte received from the input stream. |
| SERIAL_ERROR_FRAMING | A framing error was detected in the bytes received from the input stream. |

After the serial controller driver supplies the accumulated SERIAL_ERROR_*XXX* flags to satisfy an [IOCTL_SERIAL_GET_COMMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_commstatus) request, the driver resets the flags to zero.

### `HoldReasons`

A set of flags to indicate the reasons that the serial port is currently waiting to transmit bytes to the output stream. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Flag name | Meaning |
| --- | --- |
| SERIAL_TX_WAITING_FOR_CTS | Waiting for the CTS (clear to send) signal. |
| SERIAL_TX_WAITING_FOR_DSR | Waiting for the DSR (data set ready) signal. |
| SERIAL_TX_WAITING_FOR_DCD | Waiting for the DCD (data carrier detect) signal. |
| SERIAL_TX_WAITING_FOR_XON | Waiting for the XON (transmit on) signal. |
| SERIAL_TX_WAITING_ON_BREAK | Sending a break (spacing value) signal. |
| SERIAL_TX_WAITING_XOFF_SENT | Sent an XOFF (transmit off) signal. This signal marks the end of transmission from the serial port, which then waits for the device on the other end of the line to start transmitting. The other device receives the transmitted XOFF signal as an XON signal. |

**HoldReasons** is zero if the serial port has no reason to stop transmitting bytes.

### `AmountInInQueue`

The number of bytes of data received from the serial port that are currently available to be read from the input buffer.

### `AmountInOutQueue`

The number of bytes of transmit data that are currently waiting to be written from the output buffer to the serial port.

### `EofReceived`

Whether an EOF (end of file) character has been received. This member is **TRUE** if an EOF has been received. Otherwise, it is **FALSE**. The EOF character marks the end of the input stream.

### `WaitForImmediate`

Whether the serial port is waiting to transmit an immediate character. This member is **TRUE** if the serial port is waiting to transmit an immediate character. Otherwise, it is **FALSE**. Transmission of an immediate character might be delayed if any flag bit other than SERIAL_TX_WAITING_FOR_XON is set in the **HoldReasons** member. For more information about immediate characters, see [IOCTL_SERIAL_IMMEDIATE_CHAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_immediate_char).

## Remarks

This structure is used by the [IOCTL_SERIAL_GET_COMMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_commstatus) request.

## See also

[IOCTL_SERIAL_GET_COMMSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_commstatus)

[IOCTL_SERIAL_IMMEDIATE_CHAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_immediate_char)