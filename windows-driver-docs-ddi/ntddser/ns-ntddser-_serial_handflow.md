# _SERIAL_HANDFLOW structure

## Description

The **SERIAL_HANDFLOW** structure specifies the handshake and flow control settings for a serial port.

## Members

### `ControlHandShake`

A bitmask that specifies the control lines that the serial port uses for flow control. This member is set to zero or to the bitwise-OR or one or more of the following flags.

| Value | Description |
| --- | --- |
| SERIAL_DTR_CONTROL | DTR (data terminal ready) is enabled. |
| SERIAL_DTR_HANDSHAKE | DTR is used for input flow control. |
| SERIAL_CTS_HANDSHAKE | CTS (clear to send) is used for output flow control. |
| SERIAL_DSR_HANDSHAKE | DSR (data set ready) is used for output flow control. |
| SERIAL_DCD_HANDSHAKE | DCD (data carrier detect) is used for output flow control. |
| SERIAL_DSR_SENSITIVITY | Ignore characters arriving at the serial port when the DSR line is inactive. |
| SERIAL_ERROR_ABORT | Abort a transmit or receive operation if an error occurs. |

SerCx2 supports the SERIAL_CTS_HANDSHAKE flag, and may or may not support the other six flags defined for this member, depending on the serial controller driver and the capabilities of the serial controller hardware. SerCx supports only the first four flags in the preceding table. Serial.sys supports all of the flags in the preceding table.

### `FlowReplace`

A bitmask that specifies flow control behavior. This member is set to zero or to the bitwise-OR or one or more of the following flags.

| Value | Description |
| --- | --- |
| SERIAL_AUTO_TRANSMIT | Use XON/XOFF for flow control of transmitted data. |
| SERIAL_AUTO_RECEIVE | Use XON/XOFF for flow control of received data. |
| SERIAL_ERROR_CHAR | Insert the error character into the received data when an error occurs. For more information, see the description of the **ErrorChar** member in [SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars). |
| SERIAL_NULL_STRIPPING | Automatically strip null characters from received data. |
| SERIAL_BREAK_CHAR | Insert the break character into the received data when a break occurs. For more information, see the description of the **BreakChar** member in [SERIAL_CHARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_chars). |
| SERIAL_RTS_CONTROL | RTS (request to send) is enabled. |
| SERIAL_RTS_HANDSHAKE | RTS is used for output flow control. |
| SERIAL_XOFF_CONTINUE | Continue to transmit after sending XOFF to the device on the other end of the line. |

SerCx2 supports the SERIAL_RTS_CONTROL and SERIAL_RTS_HANDSHAKE flags, but typically does not support the other six flags defined for this member, depending on the serial controller driver and the capabilities of the serial controller hardware. SerCx supports only the SERIAL_RTS_CONTROL and SERIAL_RTS_HANDSHAKE flags. Serial.sys supports all of the flags in the preceding table.

### `XonLimit`

XON limit. When the number of characters in the internal receive buffer falls below the XON limit, the serial controller driver uses the flow control signals to tell the sender to resume sending characters.

### `XoffLimit`

XOFF limit. When the number of characters in the internal receive buffer reaches the XOFF limit, the serial controller driver uses the flow control signals to tell the sender to stop sending characters.

## Remarks

This structure is used by the [IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow) and [IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow) requests.

After sending an XOFF (transmit off) character, the serial port stops transmitting immediately, without sending any more characters. This behavior supports serial ports that interpret any character that follows an XOFF as an implied XON (transmit on).

SerCx2 and SerCx support only subsets of the flags that are defined for the **ControlHandShake** and **FlowControl** members. An **IOCTL_SERIAL_SET_HANDFLOW** request that specifies an unsupported flag is completed with STATUS_NOT_IMPLEMENTED.

## See also

[IOCTL_SERIAL_GET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_handflow)

[IOCTL_SERIAL_SET_HANDFLOW](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_handflow)