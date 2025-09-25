# COMMPROP structure

## Description

Contains information about a communications driver.

## Members

### `wPacketLength`

The size of the entire data packet, regardless of the amount of data requested, in bytes.

### `wPacketVersion`

The version of the structure.

### `dwServiceMask`

A bitmask indicating which services are implemented by this provider. The
**SP_SERIALCOMM** value is always specified for communications providers, including modem
providers.

### `dwReserved1`

Reserved; do not use.

### `dwMaxTxQueue`

The maximum size of the driver's internal output buffer, in bytes. A value of zero indicates that no
maximum value is imposed by the serial provider.

### `dwMaxRxQueue`

The maximum size of the driver's internal input buffer, in bytes. A value of zero indicates that no maximum
value is imposed by the serial provider.

### `dwMaxBaud`

The maximum allowable baud rate, in bits per second (bps). This member can be one of the following
values.

| Value | Meaning |
| --- | --- |
| **BAUD_075**<br><br>0x00000001 | 75 bps |
| **BAUD_110**<br><br>0x00000002 | 110 bps |
| **BAUD_134_5**<br><br>0x00000004 | 134.5 bps |
| **BAUD_150**<br><br>0x00000008 | 150 bps |
| **BAUD_300**<br><br>0x00000010 | 300 bps |
| **BAUD_600**<br><br>0x00000020 | 600 bps |
| **BAUD_1200**<br><br>0x00000040 | 1200 bps |
| **BAUD_1800**<br><br>0x00000080 | 1800 bps |
| **BAUD_2400**<br><br>0x00000100 | 2400 bps |
| **BAUD_4800**<br><br>0x00000200 | 4800 bps |
| **BAUD_7200**<br><br>0x00000400 | 7200 bps |
| **BAUD_9600**<br><br>0x00000800 | 9600 bps |
| **BAUD_14400**<br><br>0x00001000 | 14400 bps |
| **BAUD_19200**<br><br>0x00002000 | 19200 bps |
| **BAUD_38400**<br><br>0x00004000 | 38400 bps |
| **BAUD_56K**<br><br>0x00008000 | 56K bps |
| **BAUD_57600**<br><br>0x00040000 | 57600 bps |
| **BAUD_115200**<br><br>0x00020000 | 115200 bps |
| **BAUD_128K**<br><br>0x00010000 | 128K bps |
| **BAUD_USER**<br><br>0x10000000 | Programmable baud rate. |

### `dwProvSubType`

The communications-provider type.

| Value | Meaning |
| --- | --- |
| **PST_FAX**<br><br>0x00000021 | FAX device |
| **PST_LAT**<br><br>0x00000101 | LAT protocol |
| **PST_MODEM**<br><br>0x00000006 | Modem device |
| **PST_NETWORK_BRIDGE**<br><br>0x00000100 | Unspecified network bridge |
| **PST_PARALLELPORT**<br><br>0x00000002 | Parallel port |
| **PST_RS232**<br><br>0x00000001 | RS-232 serial port |
| **PST_RS422**<br><br>0x00000003 | RS-422 port |
| **PST_RS423**<br><br>0x00000004 | RS-423 port |
| **PST_RS449**<br><br>0x00000005 | RS-449 port |
| **PST_SCANNER**<br><br>0x00000022 | Scanner device |
| **PST_TCPIP_TELNET**<br><br>0x00000102 | TCP/IP Telnet protocol |
| **PST_UNSPECIFIED**<br><br>0x00000000 | Unspecified |
| **PST_X25**<br><br>0x00000103 | X.25 standards |

### `dwProvCapabilities`

A bitmask indicating the capabilities offered by the provider. This member can be a combination of the
following values.

| Value | Meaning |
| --- | --- |
| **PCF_16BITMODE**<br><br>0x0200 | Special 16-bit mode supported |
| **PCF_DTRDSR**<br><br>0x0001 | DTR (data-terminal-ready)/DSR (data-set-ready) supported |
| **PCF_INTTIMEOUTS**<br><br>0x0080 | Interval time-outs supported |
| **PCF_PARITY_CHECK**<br><br>0x0008 | Parity checking supported |
| **PCF_RLSD**<br><br>0x0004 | RLSD (receive-line-signal-detect) supported |
| **PCF_RTSCTS**<br><br>0x0002 | RTS (request-to-send)/CTS (clear-to-send) supported |
| **PCF_SETXCHAR**<br><br>0x0020 | Settable XON/XOFF supported |
| **PCF_SPECIALCHARS**<br><br>0x0100 | Special character support provided |
| **PCF_TOTALTIMEOUTS**<br><br>0x0040 | The total (elapsed) time-outs supported |
| **PCF_XONXOFF**<br><br>0x0010 | XON/XOFF flow control supported |

### `dwSettableParams`

A bitmask indicating the communications parameters that can be changed. This member can be a combination of
the following values.

| Value | Meaning |
| --- | --- |
| **SP_BAUD**<br><br>0x0002 | Baud rate |
| **SP_DATABITS**<br><br>0x0004 | Data bits |
| **SP_HANDSHAKING**<br><br>0x0010 | Handshaking (flow control) |
| **SP_PARITY**<br><br>0x0001 | Parity |
| **SP_PARITY_CHECK**<br><br>0x0020 | Parity checking |
| **SP_RLSD**<br><br>0x0040 | RLSD (receive-line-signal-detect) |
| **SP_STOPBITS**<br><br>0x0008 | Stop bits |

### `dwSettableBaud`

The baud rates that can be used. For values, see the **dwMaxBaud** member.

### `wSettableData`

A bitmask indicating the number of data bits that can be set. This member can be a combination of the
following values.

| Value | Meaning |
| --- | --- |
| **DATABITS_5**<br><br>0x0001 | 5 data bits |
| **DATABITS_6**<br><br>0x0002 | 6 data bits |
| **DATABITS_7**<br><br>0x0004 | 7 data bits |
| **DATABITS_8**<br><br>0x0008 | 8 data bits |
| **DATABITS_16**<br><br>0x0010 | 16 data bits |
| **DATABITS_16X**<br><br>0x0020 | Special wide path through serial hardware lines |

### `wSettableStopParity`

A bitmask indicating the stop bit and parity settings that can be selected. This member can be a
combination of the following values.

| Value | Meaning |
| --- | --- |
| **STOPBITS_10**<br><br>0x0001 | 1 stop bit |
| **STOPBITS_15**<br><br>0x0002 | 1.5 stop bits |
| **STOPBITS_20**<br><br>0x0004 | 2 stop bits |
| **PARITY_NONE**<br><br>0x0100 | No parity |
| **PARITY_ODD**<br><br>0x0200 | Odd parity |
| **PARITY_EVEN**<br><br>0x0400 | Even parity |
| **PARITY_MARK**<br><br>0x0800 | Mark parity |
| **PARITY_SPACE**<br><br>0x1000 | Space parity |

### `dwCurrentTxQueue`

The size of the driver's internal output buffer, in bytes. A value of zero indicates that the value is
unavailable.

### `dwCurrentRxQueue`

The size of the driver's internal input buffer, in bytes. A value of zero indicates that the value is
unavailable.

### `dwProvSpec1`

Any provider-specific data. Applications should ignore this member unless they have detailed information
about the format of the data required by the provider.

Set this member to **COMMPROP_INITIALIZED** before calling the
[GetCommProperties](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommproperties) function to indicate that the
**wPacketLength** member is already valid.

### `dwProvSpec2`

Any provider-specific data. Applications should ignore this member unless they have detailed information
about the format of the data required by the provider.

### `wcProvChar`

Any provider-specific data. Applications should ignore this member unless they have detailed information
about the format of the data required by the provider.

## Remarks

The contents of the **dwProvSpec1**, **dwProvSpec2**, and
**wcProvChar** members depend on the provider subtype (specified by the
**dwProvSubType** member).

If the provider subtype is **PST_MODEM**, these members are used as follows.

| Value | Meaning |
| --- | --- |
| **dwProvSpec1** | Not used. |
| **dwProvSpec2** | Not used. |
| **wcProvChar** | Contains a [MODEMDEVCAPS](https://learn.microsoft.com/windows/desktop/api/mcx/ns-mcx-modemdevcaps) structure. |

## See also

[GetCommProperties](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcommproperties)