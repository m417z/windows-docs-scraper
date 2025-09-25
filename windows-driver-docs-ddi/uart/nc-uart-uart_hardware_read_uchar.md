# UART_HARDWARE_READ_UCHAR callback function

## Description

Reads a byte from the specified port or register.

## Parameters

### `Address`

A pointer to a variable that contains the port or register address.

## Return value

Returns the byte that is read from the specified port or register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_READ_UCHAR UartHardwareReadUchar;

// Definition

UCHAR UartHardwareReadUchar
(
	PUCHAR Address
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **ReadPort8** or **ReadRegister8** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)