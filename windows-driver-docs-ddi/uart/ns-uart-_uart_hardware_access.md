# _UART_HARDWARE_ACCESS structure

## Description

I/O functions and the function pointers used by the serial drivers to access the device hardware.

## Members

### `ReadPort8`

A pointer to a [**UART_HARDWARE_READ_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_uchar) callback function that reads from a port.

### `WritePort8`

A pointer to a [**UART_HARDWARE_WRITE_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_uchar) callback function that writes to a port.

### `ReadPort16`

A pointer to a [**UART_HARDWARE_READ_USHORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_ushort) callback function that reads from a port.

### `WritePort16`

A pointer to a [**UART_HARDWARE_WRITE_USHORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_ushort) callback function that writes to a port.

### `ReadPort32`

A pointer to a [**UART_HARDWARE_READ_ULONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_ulong) callback function that reads from a port.

### `WritePort32`

A pointer to a [**UART_HARDWARE_WRITE_ULONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_ulong) callback function that writers to a port.

### `ReadRegister8`

A pointer to a [**UART_HARDWARE_READ_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_uchar) callback function that reads from a register.

### `WriteRegister8`

A pointer to a [**UART_HARDWARE_READ_UCHAR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_uchar) callback function that writes to a register.

### `ReadRegister16`

A pointer to a [**UART_HARDWARE_READ_USHORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_ushort) callback function that reads from a register.

### `WriteRegister16`

A pointer to a [**UART_HARDWARE_WRITE_USHORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_ushort) callback function that writes to a register.

### `ReadRegister32`

A pointer to a [**UART_HARDWARE_READ_ULONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_ulong) callback function that reads from a register.

### `WriteRegister32`

A pointer to a [**UART_HARDWARE_WRITE_ULONG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_ulong) callback function that writes to a register.

### `ReadRegister64`

A pointer to a [**UART_HARDWARE_READ_ULONG64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_read_ulong64) callback function that reads from the specified register.

### `WriteRegister64`

A pointer to a [**UART_HARDWARE_WRITE_ULONG64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_hardware_write_ulong64) callback function that writes to the specified register.

## Remarks

## See also

[**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver)

[**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport)

[**UART_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ne-uart-uart_status)

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)