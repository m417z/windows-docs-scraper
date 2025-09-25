# _UART_HARDWARE_DRIVER structure

## Description

Contains function pointers for interacting with a specific type of UART hardware. Generally, there should be one instance of this structure for each supported hardware device. The function pointers are not expected to change at runtime.

## Members

### `InitializePort`

A pointer to a [**UART_INITIALIZE_PORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_initialize_port) callback function to initialize/reset the UART hardware. This function must be called before calling any other driver functions.

### `SetBaud`

A pointer to a [**UART_SET_BAUD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_set_baud) callback function that sets the baud rate of the UART hardware to the specified value.

### `GetByte`

A pointer to a [**UART_GET_BYTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_get_byte) callback function that reads a byte from the UART device.

### `PutByte`

A pointer to a [**UART_PUT_BYTE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_put_byte) callback function that writes a byte to the UART device.

### `RxReady`

A pointer to a [**UART_RX_READY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/nc-uart-uart_rx_ready) callback function that determines whether there is data pending in the UART hardware.

### `SetPowerD0`

For information about Windows power states, see [Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states)

### `SetPowerD3`

For information about Windows power states, see [Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states)

## Remarks

## See also

[**uart.h**](https://learn.microsoft.com/windows-hardware/drivers/ddi/uart/)