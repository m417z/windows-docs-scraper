# UART_HARDWARE_READ_INDEXED_UCHAR callback function

## Description

Reads a byte from the specified port.

## Parameters

### `Port` [_In_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that was received during port initialization.

### `Index`

A zero-based index for the port.

## Return value

Returns the byte that is read from the specified port address.

## Prototype

```cpp
//Declaration

UART_HARDWARE_READ_INDEXED_UCHAR UartHardwareReadIndexedUchar;

// Definition

UCHAR UartHardwareReadIndexedUchar
(
	PCPPORT Port
	 const UCHAR Index
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of the [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure.

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)