# _GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS structure

## Description

The **GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS** structure describes the general-purpose I/O (GPIO) interrupt pin to reconfigure.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the interrupt pin to reconfigure. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinNumber`

The bank-relative pin number. If N is the number of pins in this bank, **PinNumber** is an integer in the range 0 to N–1. GpioClx previously obtained the number of pins in each bank from the *CLIENT_QueryControllerBasicInformation* event callback function. For more information, see the description of the **NumberOfPinsPerBank** member in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `InterruptMode`

Indicates whether to configure the GPIO interrupt pin to be level-sensitive or edge-triggered (latched). This member is set to one of the following values:

* **LevelSensitive**
* **Latched**

For more information, see [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode).

### `Polarity`

Indicates the polarity of the reconfigured GPIO interrupt pin. For a level-sensitive interrupt, this member indicates whether the interrupt is active-high or active-low. For an edge-triggered interrupt, this member indicates whether the interrupt is triggered on the rising edge, on the falling edge, or on both edges. This member is set to one of the following values:

* **InterruptActiveHigh**
* **InterruptRisingEdge**
* **InterruptActiveLow**
* **InterruptFallingEdge**
* **InterruptActiveBoth**

For more information, see [KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity).

### `Flags`

A set of flags to control the interrupt-reconfiguration operation. No flags are currently defined for this operation.

## Remarks

The *ReconfigureParameters* parameter of the [CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt) event callback function is a pointer to a caller-allocated **GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS** structure.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_ReconfigureInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_reconfigure_interrupt)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[KINTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_polarity)