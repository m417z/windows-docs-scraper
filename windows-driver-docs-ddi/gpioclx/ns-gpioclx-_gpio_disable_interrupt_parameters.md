# _GPIO_DISABLE_INTERRUPT_PARAMETERS structure

## Description

The **GPIO_DISABLE_INTERRUPT_PARAMETERS** structure describes a general-purpose I/O (GPIO) interrupt pin to disable.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the GPIO interrupt pin to disable. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinNumber`

The bank-relative pin number. If N is the number pins in this bank, **PinNumber** is an integer in the range 0 to N–1. GpioClx previously obtained the number of pins in each bank from the *CLIENT_QueryControllerBasicInformation* event callback function. For more information, see the description of the **NumberOfPinsPerBank** member in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `Flags`

A set of flags to control the interrupt-disable operation. The **RetryDisableOnFailure** flag bit indicates that a previous [CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt) call to disable the same pin failed. For more information, see Remarks.

## Remarks

The *DisableParameters* parameter of the [CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt) event callback function is a pointer to a caller-allocated **GPIO_DISABLE_INTERRUPT_PARAMETERS** structure.

The *CLIENT_DisableInterrupt* function for a memory-mapped GPIO controller is expected to always succeed in disabling the interrupt. However, the *CLIENT_DisableInterrupt* function for a controller that is not memory-mapped must send an I/O request to the controller to disable the interrupt, and this request might fail. If the request fails to disable the interrupt, the function must return an error status code.

After a *CLIENT_DisableInterrupt* call fails, GpioClx might retry the call one or more times. During each retry, GpioClx sets the **RetryDisableOnFailure** flag to indicate that the previous call failed. The *CLIENT_DisableInterrupt* function might respond to this flag by taking additional steps to increase the likelihood that the next attempt to disable the interrupt succeeds.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)