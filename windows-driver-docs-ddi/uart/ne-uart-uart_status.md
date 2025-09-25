# UART_STATUS enumeration

## Description

Defines values for the status of a UART operation.

## Constants

### `UartSuccess`

The operation was successful, for example if data was available.

### `UartNoData`

No data is available, but not due to an error condition.

### `UartError`

A UART error such as overrun, parity, framing, etc.

### `UartNotReady`

The device is not ready.

## Remarks

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)