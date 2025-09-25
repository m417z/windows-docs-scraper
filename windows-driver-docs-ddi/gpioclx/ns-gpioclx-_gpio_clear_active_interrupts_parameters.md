# _GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS structure

## Description

The **GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS** structure describes a set of general-purpose I/O (GPIO) interrupt pins to clear.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the pins to be cleared. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `ClearActiveMask`

A 64-bit mask that indicates which interrupts to clear in the specified bank. A bit in the mask that is set to 1 identifies a pin that is configured as an interrupt and that is to be cleared. All other bits in the mask are 0. If N is the number of pins in this bank, the pins are numbered 0 to N–1. Bit 0 (the least significant bit) in the mask represents pin 0, bit 1 represents pin 1, and so on.

### `FailedClearMask`

A 64-bit mask that identifies the GPIO pins that could not be cleared. If the GPIO controller driver fails to clear a bit that is indicated in the **ClearActiveMask** member, the driver sets the corresponding bit in the **FailedClearMask** member to mark the failure. If all the bits specified in **ClearActiveMask** are successfully cleared, the driver sets **FailedClearMask** to zero.

## Remarks

The *ClearParameters* parameter of the [CLIENT_ClearActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_clear_active_interrupts) event callback function is a pointer to a caller-allocated **GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS** structure. This function affects only GPIO pins that are configured as interrupt inputs and that are part of the specified bank of GPIO pins.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_ClearActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_clear_active_interrupts)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)