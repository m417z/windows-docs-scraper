# UART_HARDWARE_WRITE_UCHAR callback function

## Description

Writes a byte to the port specified by address.

## Parameters

### `Address`

A pointer to a variable that contains the port or register address.

### `Value`

Specifies a byte to be written to the port or register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_WRITE_UCHAR UartHardwareWriteUchar;

// Definition

VOID UartHardwareWriteUchar
(
	PUCHAR Address
	UCHAR Value
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the **WritePort8** or **WriteRegister8** member of the [**_UART_HARDWARE_ACCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_access) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)