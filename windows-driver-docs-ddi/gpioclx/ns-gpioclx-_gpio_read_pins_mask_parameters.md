# _GPIO_READ_PINS_MASK_PARAMETERS structure

## Description

The **GPIO_READ_PINS_MASK_PARAMETERS** structure describes a read operation on a bank of general-purpose I/O (GPIO) pins.

## Members

### `BankId`

The identifier for this bank of GPIO pins. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinValues`

A 64-bit variable to which the GPIO controller driver stores the values that it reads from the GPIO pins in the bank. If N is the number of GPIO pins in this bank, the pins are numbered 0 to N–1. The value from pin number 0 is saved in bit 0 (the least significant bit) of this variable, the value from pin number 1 is saved in bit 1 of this variable, and so on.

### `Flags`

A set of flags to control the GPIO pin read operation. If the **WriteConfiguredPins** flag bit is set, the GPIO controller driver can read from a GPIO pin that is configured for write operations.

### `Reserved`

Reserved for system use.

## Remarks

The *ReadParameters* parameter of the [CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask) event callback function is a pointer to a caller-allocated **GPIO_READ_PINS_MASK_PARAMETERS** structure.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_ReadGpioPinsUsingMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins_mask)