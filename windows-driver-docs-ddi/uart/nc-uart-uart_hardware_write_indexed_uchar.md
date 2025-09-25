# UART_HARDWARE_WRITE_INDEXED_UCHAR callback function

## Description

Implemented by the client driver to ...

## Parameters

### `Port` [_In_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that was received during port initialization.

### `Index`

A zero-based index for the port.

### `Value`

Specifies a byte to be written to the register.

## Prototype

```cpp
//Declaration

UART_HARDWARE_WRITE_INDEXED_UCHAR UartHardwareWriteIndexedUchar;

// Definition

VOID UartHardwareWriteIndexedUchar
(
	PCPPORT Port
	 const UCHAR Index
	 const UCHAR Value
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)