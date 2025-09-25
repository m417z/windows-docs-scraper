# _GPIO_DISCONNECT_IO_PINS_PARAMETERS structure

## Description

The **GPIO_DISCONNECT_IO_PINS_PARAMETERS** structure describes a set of general-purpose I/O (GPIO) pins that are to be disconnected.

## Members

### `BankId`

The identifier for the bank that contains the GPIO pins. If M is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to M–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinNumberTable`

A pointer to an array of PIN_NUMBER values. Each array element specifies the number of a GPIO pin to disconnect from. If the GPIO controller has N pins, the pins are numbered 0 to N–1. The number of elements in this array is specified by the **PinCount** member.

### `PinCount`

The number of elements in the **PinNumberTable** array.

### `DisconnectMode`

Whether the GPIO pins in the connection that is being closed are configured as inputs or as outputs. The value of this member is **ConnectModeInput** for a read-only connection, **ConnectModeOutput** for a write-only connection, or (**ConnectModeInput** | **ConnectModeOutput**) for a read/write connection. For more information, see [GPIO_CONNECT_IO_PINS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ne-gpioclx-_gpio_connect_io_pins_mode).

### `DisconnectFlags`

A set of flags that control how the GPIO pins are to be configured after they are closed. If the **PreserveConfiguration** flag bit is set, the GPIO controller driver preserves the configuration of the pins after they are disconnected. For more information, see Remarks.

## Remarks

The *DisconnectParameters* parameter to the [CLIENT_DisconnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disconnect_io_pins) event callback routine is a pointer to a **GPIO_CONNECT_IO_PINS_PARAMETERS** structure.

By default, when a GPIO I/O pin is disconnected, the GPIO controller driver configures the pin in a platform-specific initial state. The pin is typically configured in a low-power state to reduce the load on the battery. However, the **PreserveConfiguration** flag can be used to override this default behavior. The flag tells the GPIO controller driver to preserve the configuration of the I/O pins that are being disconnected.

For example, a peripheral device driver might open a logical connection to a GPIO I/O pin that is configured as an output, and then write a bit value of 1 to the pin. The **PreserveConfiguration** flag enables the driver to close the connection without altering the pin's output level. Later, if the driver needs to change the output level of the pin from 1 to 0, the driver opens a new connection to the pin.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_DisconnectIoPins](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disconnect_io_pins)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CONNECT_IO_PINS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ne-gpioclx-_gpio_connect_io_pins_mode)