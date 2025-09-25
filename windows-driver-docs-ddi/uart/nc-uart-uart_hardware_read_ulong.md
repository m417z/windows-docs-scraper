# UART_HARDWARE_READ_ULONG callback function

## Description

Reads a ULONG value from the specified port or register.

## Parameters

### `Address`

A pointer to a variable that contains the port or register address.

## Return value

Returns the ULONG value that is read from the specified port or register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_READ_ULONG UartHardwareReadUlong;

// Definition

ULONG UartHardwareReadUlong
(
	PULONG Address
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **ReadPort32** or **ReadRegister32** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)