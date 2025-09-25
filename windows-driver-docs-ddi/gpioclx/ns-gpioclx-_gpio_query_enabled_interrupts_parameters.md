# _GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS structure

## Description

The **GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS** structure indicates which interrupt pins in a bank of general-purpose I/O (GPIO) pins are enabled.

## Members

### `BankId`

The identifier for the bank of GPIO pins to query for enabled interrupts. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `EnabledMask`

A 64-bit mask that indicates which interrupts are enabled in the specified bank. A bit in the mask that is set to 1 identifies an interrupt pin that is enabled for interrupts. All other bits in the mask are 0. If N is the number of pins in this bank, the pins are numbered 0 to N–1. Bit 0 (the least significant bit) in the mask represents pin 0, bit 1 represents pin 1, and so on.

## Remarks

The *QueryEnabledParameters* parameter of the [CLIENT_QueryEnabledInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_enabled_interrupts) event callback function is a pointer to a caller-allocated **GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS** structure. Before calling this function, the caller writes a bank ID to the **BankId** member of this structure to specify which bank of GPIO pins to query. The function writes a mask value to the **EnabledMask** member of this structure to indicate which interrupts are enabled in the specified bank.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_QueryEnabledInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_enabled_interrupts)