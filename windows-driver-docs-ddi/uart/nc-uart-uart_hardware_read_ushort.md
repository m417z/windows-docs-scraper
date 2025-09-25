# UART_HARDWARE_READ_USHORT callback function

## Description

Reads a USHORT value from the specified port or register.

## Parameters

### `Address`

A pointer to a variable that contains the port or register address.

## Return value

Returns USHORT that is read from the specified port or register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_READ_USHORT UartHardwareReadUshort;

// Definition

USHORT UartHardwareReadUshort
(
	PUSHORT Address
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **ReadPort16** or **ReadRegister16** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)