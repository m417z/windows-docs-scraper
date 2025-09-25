# _CPPORT structure

## Description

Contains the mutable runtime state of a specific instance of a UART device.

## Members

### `Address`

The base address of the UART registers.

### `BaudRate`

The UART hardware's baud rate in bits per second.

### `Flags`

A bitmask of the port's internal flags.

### `ByteWidth`

The width of each of the UART hardware's registers as a number of bytes.

### `Read`

A pointer to a [**UART_HARDWARE_READ_INDEXED_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_indexed_uchar) callback function used to read from a register on the UART hardware.

### `Write`

A pointer to a [**UART_HARDWARE_WRITE_INDEXED_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_indexed_uchar) callback function used to write to a register on the UART hardware.

## Remarks

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)