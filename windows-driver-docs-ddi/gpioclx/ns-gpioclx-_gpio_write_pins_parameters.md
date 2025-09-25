# _GPIO_WRITE_PINS_PARAMETERS structure

## Description

The **GPIO_WRITE_PINS_PARAMETERS** structure describes a write operation on a group of general-purpose I/O (GPIO) pins.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the pins to write to. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinNumberTable`

A pointer to an array of bank-relative PIN_NUMBER values. Each array element specifies the number of a GPIO pin to write to. If this bank has N pins, the pins are numbered 0 to N–1. The number of elements in this array is specified by the **PinCount** member.

### `PinCount`

The number of elements in the **PinNumberTable** array.

### `Buffer`

A pointer to a buffer that contains the bit values that this callback function is to write to the GPIO pins that are identified in the **PinNumberTable** array. The function writes bit 0 (the least significant bit) from the buffer to the GPIO pin that is identified by array element 0, writes bit 1 from the buffer to the pin identified by array element 1, and so on.

### `Flags`

A set of flags to control the GPIO pin write operation. No flags are currently defined for this operation.

### `Reserved`

Reserved for system use.

## Remarks

The *WriteParameters* parameter of the [CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins) event callback function is a pointer to a caller-allocated **GPIO_WRITE_PINS_PARAMETERS** structure. All of the pins that this function writes to are part of the same bank of GPIO pins.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_WriteGpioPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_write_pins)