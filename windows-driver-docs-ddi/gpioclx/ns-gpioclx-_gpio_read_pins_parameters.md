# _GPIO_READ_PINS_PARAMETERS structure

## Description

The **GPIO_READ_PINS_PARAMETERS** structure describes a read operation on a group of general-purpose I/O (GPIO) pins.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the pins to read. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinNumberTable`

A pointer to an array of bank-relative PIN_NUMBER values. Each array element specifies the number of a GPIO pin to read from. If this bank has N pins, the pins are numbered 0 to N–1. The number of elements in this array is specified by the **PinCount** member.

### `PinCount`

The number of elements in the **PinNumberTable** array.

### `Buffer`

A pointer to a buffer to hold the values that the GPIO controller driver reads from the GPIO pins that are specified by the **PinNumberTable** array. Array element 0 specifies the GPIO pin whose value is saved to bit 0 (the least significant bit) in the buffer, array element 1 specifies the GPIO pin whose value is saved to bit 1 in the buffer, and so on.

### `Flags`

A set of flags to control the GPIO pin read operation. If the **WriteConfiguredPins** flag bit is set, the GPIO controller driver can read from a GPIO pin that is configured for write operations.

### `Reserved`

Reserved for system use.

## Remarks

The *ReadParameters* parameter of the [CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins) event callback function is a pointer to a caller-allocated **GPIO_READ_PINS_PARAMETERS** structure. All of the pins that this function reads are part of the same bank of GPIO pins.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_ReadGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_read_pins)