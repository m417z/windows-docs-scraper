# GPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT callback function

## Description

The *CLIENT_RestoreBankHardwareContext* event callback function restores the hardware context of a bank of general-purpose I/O (GPIO) pins.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `Parameters` [in]

A pointer to a [GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_save_restore_bank_hardware_context_parameters) structure that describes the bank of GPIO pins to restore.

## Remarks

The *CLIENT_RestoreBankHardwareContext* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

If a bank of GPIO pins supports component-level power management, GpioClx can switch the bank to a low-power Fx state if the bank is idle. If the GPIO controller bank loses its hardware context in the Fx state, the GPIO controller driver must save this context before the F0-to-Fx transition, and, later, restore the context after the Fx-to-F0 transition. Currently, F1 is the only low-power state that is defined for GPIO controllers that use GpioClx.

GpioClx calls the *CLIENT_RestoreBankHardwareContext* function to restore the bank's previously saved hardware context. The hardware context was previously saved by the [CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context) event callback function.

Some GPIO controller devices enable selected banks of pins to be turned on and off independently of other banks in the same device. Thus, power can be saved by turning off a bank that is idle.

To register your driver's *CLIENT_RestoreBankHardwareContext* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_RestoreBankHardwareContext* function pointer.

GpioClx calls the *CLIENT_RestoreBankHardwareContext* callback function either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, GpioClx calls the *CLIENT_RestoreBankHardwareContext* function at DIRQL, which is the IRQL at which the ISR in GpioClx runs. Otherwise, this function is called at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

#### Examples

To define a *CLIENT_RestoreBankHardwareContext* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_RestoreBankHardwareContext* callback function that is named `MyEvtGpioRestoreBankHardwareContext`, use the GPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT function type, as shown in this code example:

```cpp
GPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT MyEvtGpioRestoreBankHardwareContext;</pre>
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioRestoreBankHardwareContext(
    PVOID Context,
    PGPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS Parameters
    )
{ ... }
```

The GPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_RESTORE_BANK_HARDWARE_CONTEXT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CLIENT_SaveBankHardwareContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_save_bank_hardware_context)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_SAVE_RESTORE_BANK_HARDWARE_CONTEXT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_save_restore_bank_hardware_context_parameters)