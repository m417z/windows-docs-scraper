# PEP_ACPI_INITIALIZE_SPB_UART_RESOURCE function (pepfx.h)

## Description

The **PEP_ACPI_INITIALIZE_SPB_UART_RESOURCE** function initializes a platform extension plug-in's (PEP) [PEP_ACPI_SPB_UART_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_uart_resource) structure.

## Parameters

### `BaudRate` [in]

Specifies the baud rate of the connection.

### `BitsPerByte` [in]

Specifies the number of bits per byte of data.

### `StopBits` [in]

Specifies the stop bits used in the connection.

### `LinesInUse` [in]

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

### `IsBigEndian` [in]

Indicates if the most significant bits of data are in the lowest address.

### `Parity` [in]

Specifies the parity of the connection.

| Value | Meaning |
| --- | --- |
| 0x00 | None |
| 0x01 | Even |
| 0x02 | Odd |
| 0x03 | Mark |
| 0x04 | Space |

### `FlowControl` [in]

Specifies the type of flow control used by the connection.

### `RxSize` [in]

Specifies the maximum receive buffer size, in bytes, that is supported by this connection.

### `TxSize` [in]

Specifies the maximum transmit buffer size, in bytes, that is supported by this connection.

### `ResourceSource` [in]

The name of the serial bus controller device to which this
connection descriptor applies. The name can be a fully
qualified path, a relative path, or a simple name segment
that utilizes the namespace search rules.

### `ResourceSourceIndex` [in]

This parameter should always be zero.

### `ResourceUsage` [in]

Indicates if this resource is in use.

### `SharedMode` [in]

Indicates if this resource is shared.

### `VendorData` [in]

A pointer to optional data that is specific to the serial bus connection type.

### `VendorDataLength` [in]

The length of the buffer pointed to by the *VendorData* parameter.

### `Resource` [out]

A pointer to the resource. The structure behind the pointer is of type [PEP_ACPI_SPB_UART_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_uart_resource).

## See also

[PEP_ACPI_SPB_UART_RESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_acpi_spb_uart_resource)