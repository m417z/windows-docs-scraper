# UART_HARDWARE_READ_ULONG64 callback function

## Description

Reads a ULONG64 value from the specified port address.

## Parameters

### `Address`

A pointer to the register address, which must be a mapped range in memory space.

## Return value

Returns ULONG64 that is read from the specified register address.

## Prototype

```cpp
//Declaration

UART_HARDWARE_READ_ULONG64 UartHardwareReadUlong64;

// Definition

ULONG64 UartHardwareReadUlong64
(
	PULONG64 Address
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **ReadRegister64** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)