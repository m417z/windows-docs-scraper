# UART_HARDWARE_WRITE_ULONG64 callback function

## Description

Writes a ULONG64 value to the specified register address.

## Parameters

### `Address`

A pointer to the register, which must be a mapped range in memory space.

### `Value`

A ULONG64 value to be written to the register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_WRITE_ULONG64 UartHardwareWriteUlong64;

// Definition

VOID UartHardwareWriteUlong64
(
	PULONG64 Address
	ULONG64 Value
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **WriteRegister64** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)