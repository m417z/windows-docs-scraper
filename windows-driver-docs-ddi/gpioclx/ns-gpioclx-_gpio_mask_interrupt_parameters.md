# _GPIO_MASK_INTERRUPT_PARAMETERS structure

## Description

The **GPIO_MASK_INTERRUPT_PARAMETERS** structure describes a set of general-purpose I/O (GPIO) interrupt pins to mask.

## Members

### `BankId`

The identifier for the bank of GPIO pins that contains the interrupts to mask. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `PinMask`

A 64-bit mask to indicate which interrupt pins to mask in the specified bank. This mask affects only GPIO pins that are configured as interrupt request inputs. A bit in the mask that is set to 1 identifies a pin that is to be masked. All other bits in the mask are 0. If N is the number of pins in this bank, the pins are numbered 0 to N–1. Bit 0 (the least significant bit) in the mask represents pin 0, bit 1 represents pin 1, and so on.

### `FailedMask`

A 64-bit mask that identifies the GPIO pins that could not be masked. If the GPIO controller driver fails to mask a bit that is indicated in the **PinMask** member, the driver sets the corresponding bit in the **FailedMask** member to mark this failure. If all pins specified in **PinMask** are successfully masked, the driver sets **FailedMask** to zero. For more information, see Remarks.

## Remarks

The *MaskParameters* parameter of the [CLIENT_MaskInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_mask_interrupts) event callback function is a pointer to a caller-allocated **GPIO_MASK_INTERRUPT_PARAMETERS** structure. This function affects only GPIO pins that are configured as interrupt inputs and that are part of the specified bank of GPIO pins.

GPIO controllers that have memory-mapped registers are expected to always succeed in setting the interrupt mask to the requested value. The **FailedMask** member is primarily intended for use by GPIO controllers that are not memory-mapped.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_MaskInterrupts](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_mask_interrupts)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)