# _GPIO_WRITE_PINS_MASK_PARAMETERS structure

## Description

The **GPIO_WRITE_PINS_MASK_PARAMETERS** structure describes a write operation on a bank of general-purpose I/O (GPIO) pins.

## Members

### `BankId`

The identifier for this bank of GPIO pins. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `SetMask`

A mask that specifies the GPIO pins to set in this bank. If a bit in this mask is set to 1, the GPIO controller driver sets the corresponding GPIO pin to the value 1. If N is the number of pins in this bank, the pins are numbered 0 to N–1. If bit 0 (the least significant bit) of the mask is 1, the function sets pin number 0; if bit 1 of the mask is 1, the function sets pin number 1; and so on.

### `ClearMask`

A mask that specifies the GPIO pins to clear in this bank. If a bit in this mask is set to 1, the GPIO controller driver sets the corresponding GPIO pin to the value 0. If bit 0 of the mask is 1, the function clears pin 0; if bit 1 of the mask is 1, the function clears pin 1; and so on.

### `Flags`

A set of flags to control the GPIO pin write operation. No flags are currently defined for this operation.

### `Reserved`

Reserved for system use.

## Remarks

The *WriteParameters* parameter of the [CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask) event callback function is a pointer to a caller-allocated **GPIO_WRITE_PINS_MASK_PARAMETERS** structure.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_WriteGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins_mask)