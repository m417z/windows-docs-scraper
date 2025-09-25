# _SERIAL_COMMPROP structure

## Description

The **SERIAL_COMMPROP** structure specifies the properties of a serial port.

## Members

### `PacketLength`

The size, in bytes, of the data packet that starts with this structure and that contains the requested property data. This size includes the **SERIAL_COMMPROP** structure and any additional **ProvChar** array elements that follow this structure.

### `PacketVersion`

The version of this structure. The current version number is 2.

### `ServiceMask`

A bitmask that indicates which services are implemented by this communications provider. This member is always set to SERIAL_SP_SERIALCOMM by serial communications providers, including modem providers. The **ProvSubType** member indicates the specific type of serial communications that are implemented (for example, modem).

### `Reserved1`

Not used.

### `MaxTxQueue`

Maximum transmit queue size. The maximum size, in bytes, of the serial controller driver's internal output buffer. A value of zero indicates that no maximum value is imposed by the serial provider.

### `MaxRxQueue`

Maximum receive queue size. The maximum size, in bytes, of the serial controller driver's internal input buffer. A value of zero indicates that no maximum value is imposed by the serial provider.

### `MaxBaud`

The maximum acceptable baud rate. An [extension-based serial controller driver](https://learn.microsoft.com/previous-versions/dn265239(v=vs.85)) sets this member to a baud rate expressed in bits per second (bps). For example, if the serial controller supports a maximum baud rate of 115,200 bps, the driver sets **MaxBaud** = 115200.

However, Serial.sys and many older serial controller drivers set **MaxBaud** to one of the SERIAL_BAUD_*XXX* flag bits that are defined in the Ntddser.h header file. The following values are defined for this member.

| Value | Description |
| --- | --- |
| SERIAL_BAUD_075 | 75 bps |
| SERIAL_BAUD_110 | 110 bps |
| SERIAL_BAUD_134_5 | 134.5 bps |
| SERIAL_BAUD_150 | 150 bps |
| SERIAL_BAUD_300 | 300 bps |
| SERIAL_BAUD_600 | 600 bps |
| SERIAL_BAUD_1200 | 1,200 bps |
| SERIAL_BAUD_1800 | 1,800 bps |
| SERIAL_BAUD_2400 | 2,400 bps |
| SERIAL_BAUD_4800 | 4,800 bps |
| SERIAL_BAUD_7200 | 7,200 bps |
| SERIAL_BAUD_9600 | 9,600 bps |
| SERIAL_BAUD_14400 | 14,400 bps |
| SERIAL_BAUD_19200 | 19,200 bps |
| SERIAL_BAUD_38400 | 38,400 bps |
| SERIAL_BAUD_56K | 56,000 bps |
| SERIAL_BAUD_57600 | 57,600 bps |
| SERIAL_BAUD_115200 | 115,200 bps |
| SERIAL_BAUD_128K | 128,000 bps |
| SERIAL_BAUD_USER | Programmable baud rates are available. |

### `ProvSubType`

The specific communications provider type. When the **ServiceMask** member is set to SERIAL_SP_SERIALCOMM, **ProvSubType** is set to one of the following values.

| Value | Meaning |
| --- | --- |
| SERIAL_SP_UNSPECIFIED | Unspecified |
| SERIAL_SP_RS232 | RS-232 serial port |
| SERIAL_SP_PARALLEL | Parallel port |
| SERIAL_SP_RS422 | RS-422 serial port |
| SERIAL_SP_RS423 | RS-423 serial port |
| SERIAL_SP_RS449 | RS-449 serial port |
| SERIAL_SP_MODEM | Modem device |
| SERIAL_SP_FAX | FAX device |
| SERIAL_SP_SCANNER | Scanner device |
| SERIAL_SP_BRIDGE | Unspecified network bridge |
| SERIAL_SP_LAT | LAT protocol |
| SERIAL_SP_TELNET | TCP/IP Telnet® protocol |
| SERIAL_SP_X25 | X.25 standards |

### `ProvCapabilities`

The capabilities offered by the provider. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Value | Description |
| --- | --- |
| SERIAL_PCF_DTRDSR | DTR (data terminal ready) and DSR (data set ready) are supported. |
| SERIAL_PCF_RTSCTS | RTS (request to send) and CTS (clear to send) are supported. |
| SERIAL_PCF_CD | CD (carrier detect) is supported. |
| SERIAL_PCF_PARITY_CHECK | Parity checking is supported. |
| SERIAL_PCF_XONXOFF | XON (transmit on) and XOFF (transmit off) flow control are supported. |
| SERIAL_PCF_SETXCHAR | The XON and XOFF characters are settable. |
| SERIAL_PCF_TOTALTIMEOUTS | Total-elapsed-time time-outs are supported. |
| SERIAL_PCF_INTTIMEOUTS | Interval time-outs are supported. |
| SERIAL_PCF_SPECIALCHARS | Special characters are supported. |
| SERIAL_PCF_16BITMODE | Special 16-bit mode is supported. |

### `SettableParams`

A bitmask that indicates the communication parameter that can be changed. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Value | Description |
| --- | --- |
| SERIAL_SP_PARITY | Parity type (even or odd) |
| SERIAL_SP_BAUD | Baud rate |
| SERIAL_SP_DATABITS | Data bits |
| SERIAL_SP_STOPBITS | Stop bits |
| SERIAL_SP_HANDSHAKING | Handshaking (flow control) |
| SERIAL_SP_PARITY_CHECK | Parity checking |
| SERIAL_SP_CARRIER_DETECT | Carrier detect |

### `SettableBaud`

A bitmask that indicates the baud rates that can be used. For a table that describes the SERIAL_BAUD_*XXX* flag bits that are defined for this member, see the description of the **MaxBaud** member. **SettableBaud** is set to zero or to the bitwise-OR or one or more of these flag bits.

Serial controller drivers set the SERIAL_BAUD_USER flag bit in the **SettableBaud** bitmask value to indicate that they support higher baud rates than those that can be expressed by the other SERIAL_BAUD_*XXX* flag bits. For example, a driver that supports baud rates of 57600, 115200, 230400, and 460800 bps sets **SettableBaud** = (SERIAL_BAUD_57600 | SERIAL_BAUD_115200 | SERIAL_BAUD_USER).

### `SettableData`

The number of data bits that can be set. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Value | Description |
| --- | --- |
| SERIAL_DATABITS_5 | 5 data bits |
| SERIAL_DATABITS_6 | 6 data bits |
| SERIAL_DATABITS_7 | 7 data bits |
| SERIAL_DATABITS_8 | 8 data bits |
| SERIAL_DATABITS_16 | 16 data bits |
| SERIAL_DATABITS_16X | Special wide path through serial hardware lines |

### `SettableStopParity`

The stop-bit and parity settings that can be selected. This member is set to zero or to the bitwise-OR of one or more of the following flag bits.

| Value | Description |
| --- | --- |
| SERIAL_STOPBITS_10 | One stop bit. |
| SERIAL_STOPBITS_15 | One and a half stop bits. |
| SERIAL_STOPBITS_20 | Two stop bits. |
| SERIAL_PARITY_NONE | No parity bit is used. |
| SERIAL_PARITY_ODD | Odd parity. The parity bit is 1 if the number of 1s in the character value is even. Otherwise, the parity bit is 0. |
| SERIAL_PARITY_EVEN | Even parity. The parity bit is 1 if the number of 1s in the character value is odd. Otherwise, the parity bit is 0. |
| SERIAL_PARITY_MARK | The parity bit is always set to 1. |
| SERIAL_PARITY_SPACE | The parity bit is always set to 0. |

### `CurrentTxQueue`

Transmit queue size. This member specifies the size, in bytes, of the serial controller driver's internal output buffer. A value of zero indicates that the buffer size is unavailable.

For SerCx2 and SerCx, the associated serial controller driver typically sets this member to zero. Serial.sys sets this member to a nonzero value that indicates the output buffer size.

### `CurrentRxQueue`

Receive queue size. This member specifies the size, in bytes, of the serial controller driver's internal input buffer. A value of zero indicates that the buffer size is unavailable.

For SerCx2 and SerCx, this member is set by the associated serial controller driver. For SerCx2, the driver typically sets this member to zero. For SerCx, the driver typically sets this member to the size of the ring buffer that SerCx uses to buffer received data. This driver can call the [SerCxGetRingBufferUtilization](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetringbufferutilization) method to get the ring buffer size from SerCx.

Serial.sys sets this member to a nonzero value that indicates the input buffer size.

### `ProvSpec1`

Provider-specific data. Applications should ignore this member unless provider-specific data about the data format required by the serial port is available.

### `ProvSpec2`

Provider-specific data. Applications should ignore this member unless provider-specific data about the data format required by the serial port is available.

### `ProvChar`

Provider-specific data. Applications should ignore this member unless provider-specific data about the data format required by the serial port is available. This member is the first element in a wide-character array of one or more elements. Any additional elements immediately follow this member. The **PacketLength** member specifies the size of the **SERIAL_COMMPROP** structure plus any additional **ProvChar** array elements that follow this structure.

## Remarks

This structure is used by the [IOCTL_SERIAL_GET_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_properties) request.

## See also

[IOCTL_SERIAL_GET_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_properties)