# UART_RX_READY callback function

## Description

Determines whether there is data pending in the UART hardware.

## Parameters

### `Port` [_Inout_]

A pointer to a [**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport) structure that contains the address of the port object that describes the UART hardware.

## Return value

Returns TRUE if data is available, FALSE otherwise.

## Prototype

```cpp
//Declaration

UART_RX_READY UartRxReady;

// Definition

BOOLEAN UartRxReady
(
	PCPPORT Port
)
{...}

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver).

## See also

[**UART_HARDWARE_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_uart_hardware_driver)

[**_CPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ns-uart-_cpport)

[**UART_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/ne-uart-uart_status)

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)