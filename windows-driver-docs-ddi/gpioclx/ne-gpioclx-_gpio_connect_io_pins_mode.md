# _GPIO_CONNECT_IO_PINS_MODE enumeration

## Description

The **GPIO_CONNECT_IO_PINS_MODE** enumeration indicates whether a set of general-purpose I/O (GPIO) pins is configured as inputs or outputs.

## Constants

### `ConnectModeInvalid`

The connection mode (input or output) for this set of GPIO pins is uninitialized.

### `ConnectModeInput`

This set of GPIO pins is configured as data inputs.

### `ConnectModeOutput`

This set of GPIO pins is configured as data outputs.

### `ConnectModeMaximum`

The maximum value in the enumeration.

## Remarks

The **ConnectMode** member of the [GPIO_CONNECT_IO_PINS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_connect_io_pins_parameters) structure contains a **GPIO_CONNECT_IO_PINS_MODE** enumeration constant.

The **ConnectModeInput** enumeration constant labels a set of GPIO pins that can be read by an [IOCTL_GPIO_READ_PINS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_read_pins) request. **ConnectModeOutput** labels a set of GPIO pins that can be written to by an [IOCTL_GPIO_WRITE_PINS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_write_pins) request.

## See also

[GPIO_CONNECT_IO_PINS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_connect_io_pins_parameters)

[IOCTL_GPIO_READ_PINS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_read_pins)

[IOCTL_GPIO_WRITE_PINS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_write_pins)