# _GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS structure

## Description

The **GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS** structure describes a bank of general-purpose I/O (GPIO) pins whose hardware state is to be saved or restored.

## Members

### `BankId`

The identifier for this bank of GPIO pins. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1. The GPIO framework extension (GpioClx) previously obtained the number of banks in the controller from the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) event callback function. For more information, see Remarks in [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information).

### `State`

The target component power state. A save operation occurs before the specified bank of GPIO pins makes the transition from the F0 (fully on) state to the target component power state, Fx. A restore operation occurs after the bank makes the transition from Fx to F0.

### `Flags`

A set of flags to control bank hardware save and restore operations. If the **CriticalTransition** flag bit is set, this idle state transition is being done as part of a critical transition in which the power engine plug-in (PEP) puts the system into a low-power state.

## Remarks

The *Parameters* parameter of the [CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context) and [CLIENT_RestoreBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_restore_bank_hardware_context) event callback functions is a pointer to a caller-allocated **GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS** structure.

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_RestoreBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_restore_bank_hardware_context)

[CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context)