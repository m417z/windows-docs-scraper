# UART_PUT_BYTE callback function

## Description

Writes a data byte to the UART device.

## Parameters

### `Port` [_Inout_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that contains the address of the port object that describes the UART hardware.

### `Byte`

The byte to write to the UART hardware.

### `BusyWait`

A flag to control whether this routine will busy-wait (spin) for the UART hardware to be ready to transmit.

## Return value

Returns [**UART_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ne-uart-uart_status)-type value that indicates success or failure of the operation.

## Prototype

```cpp
//Declaration

UART_PUT_BYTE UartPutByte;

// Definition

UART_STATUS UartPutByte
(
	PCPPORT Port
	UCHAR Byte
	BOOLEAN BusyWait
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver).

## See also

[**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver)

[**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport)

[**UART_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ne-uart-uart_status)

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)