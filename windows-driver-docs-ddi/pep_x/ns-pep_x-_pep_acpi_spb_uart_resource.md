# _PEP_ACPI_SPB_UART_RESOURCE structure (pep_x.h)

## Description

The **PEP_ACPI_SPB_UART_RESOURCE** structure describes an ACPI UART serial bus resource.

## Members

### `SpbCommon`

A [PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource) structure describing this resource.

### `BaudRate`

The baud rate of the connection.

### `RxBufferSize`

The maximum receive buffer size, in bytes, that is supported by this connection.

### `TxBufferSize`

The maximum transmit buffer size, in bytes, that is supported by this connection.

### `Parity`

Indicates the parity of the connection.

| Value | Meaning |
| --- | --- |
| 0x00 | None |
| 0x01 | Even |
| 0x02 | Odd |
| 0x03 | Mark |
| 0x04 | Space |

### `LinesInUse`

Flag indicating the serial lines that are enabled. A value of 1 in the bit positions indicates that the line is enabled.

| Bit | Meaning |
| --- | --- |
| **0** | This bit is reserved and must be set to zero. |
| **1** | This bit is reserved and must be set to zero. |
| **2** | Data Carrier Detect (DTD) |
| **3** | Ring Indicator (RI) |
| **4** | Data Set Ready (DSR) |
| **5** | Data Terminal Ready (DTR) |
| **6** | Clear to Send (CTS) |
| **7** | Request to Send (RTS) |

## See also

[PEP_ACPI_SPB_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_resource)