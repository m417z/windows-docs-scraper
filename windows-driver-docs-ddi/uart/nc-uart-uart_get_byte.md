# UART_GET_BYTE callback function

## Description

Reads a data byte from the UART device.

## Parameters

### `Port` [_Inout_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that contains the address of the port object that describes the UART hardware.

### `Byte:` [_Out_]

A pointer to a variable that contains received byte.

## Return value

Returns [**UART_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ne-uart-uart_status)-type value that indicates success or failure of the operation.

## Prototype

```cpp
//Declaration

UART_GET_BYTE UartGetByte;

// Definition

UART_STATUS UartGetByte
(
	PCPPORT Port
	PUCHAR Byte
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