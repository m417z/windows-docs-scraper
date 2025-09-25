# _GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS structure

## Description

The **GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS** structure describes a set of general-purpose I/O (GPIO) interrupt pins to query for their enabled and active states.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the interrupts to query. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `EnabledMask`

A ULONG64 variable to which the GPIO controller driver writes a 64-bit mask to indicate which interrupt pins are enabled in the specified bank. A bit in the mask that is set to 1 identifies a pin that is configured as an interrupt and that is enabled. All other bits in the mask are 0. If N is the number of pins in this bank, the pins are numbered 0 to N–1. Bit 0 (the least significant bit) in the mask represents pin 0, bit 1 represents pin 1, and so on.

### `ActiveMask`

A ULONG64 variable to which the GPIO controller driver writes a 64-bit mask to indicate which interrupt pins are active in the specified bank. A bit in the mask that is set to 1 identifies a pin that is configured as an interrupt and that is active. All other bits in the mask are 0.

## Remarks

The *QueryActiveParameters* parameter of the [CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts) event callback function is a pointer to a caller-allocated **GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS** structure. This function queries only GPIO pins that are configured as interrupt inputs. All other GPIO pins in the specified bank are represented as zeros in the **EnabledMask** and **ActiveMask** members of the structure.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryActiveInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_active_interrupts)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)