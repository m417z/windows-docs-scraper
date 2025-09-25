# UART_HARDWARE_WRITE_USHORT callback function

## Description

Writes a USHORT value to the specified port or register.

## Parameters

### `Address`

A pointer to a variable that contains the port or register address.

### `Value`

A USHORT value to be written to the port or register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_WRITE_USHORT UartHardwareWriteUshort;

// Definition

VOID UartHardwareWriteUshort
(
	PUSHORT Address
	USHORT Value
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)