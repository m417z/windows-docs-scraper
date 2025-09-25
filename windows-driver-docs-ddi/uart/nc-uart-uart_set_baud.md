# UART_SET_BAUD callback function

## Description

Changes the baud rate of the UART hardware.

## Parameters

### `Port` [_Inout_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that contains the address of the port object that describes the UART hardware.

### `Rate:`

The baud rate to set in bits per second.

## Return value

Returns TRUE if the baud rate was programmed, FALSE otherwise.

## Prototype

```cpp
//Declaration

UART_SET_BAUD UartSetBaud;

// Definition

BOOLEAN UartSetBaud
(
	PCPPORT Port
	ULONG Rate
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver).

## See also

[**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver)

[**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport)

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)