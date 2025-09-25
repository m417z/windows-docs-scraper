# GPIO_CLIENT_QUERY_ENABLED_INTERRUPTS callback function

## Description

The *CLIENT_QueryEnabledInterrupts* event callback function queries the state of a set of general-purpose I/O (GPIO) pins to determine which pins are both configured as interrupt inputs and enabled for interrupts.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `QueryEnabledParameters` [in]

A pointer to a caller-allocated [GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_query_enabled_interrupts_parameters) structure. Before calling this function, the caller writes a bank ID to the **BankId** member of this structure to specify which bank of GPIO pins to query. If successful, the function writes a mask value to the **EnabledMask** member of this structure to indicate which interrupts are enabled in the specified bank.

## Return value

The *CLIENT_QueryEnabledInterrupts* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

Starting with Windows 8.1, the GPIO controller driver can, as an option, implement a *CLIENT_QueryEnabledInterrupts* callback function. If implemented, this function is called by the GPIO framework extension (GpioClx) to determine which interrupts are enabled in a bank of GPIO pins.

The *QueryEnabledParameters* parameter points to a caller-allocated [GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_query_enabled_interrupts_parameters) structure. The caller sets the value of the **BankId** member of this structure. The *CLIENT_QueryEnabledInterrupts* function writes to the **EnabledMask** member of the structure.

To register your driver's *CLIENT_QueryEnabledInterrupts* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_QueryEnabledInterrupts* function pointer.

The *CLIENT_QueryEnabledInterrupts* function is optional. If your driver does not implement this function, set the **CLIENT_QueryEnabledInterrupts** member of the **GPIO_CLIENT_REGISTRATION_PACKET** structure to **NULL**.

If the *CLIENT_QueryEnabledInterrupts* function is implemented, GpioClx uses this function to improve driver reliability and diagnostics. GpioClx calls this function to verify that the set of interrupts enabled at the GPIO controller matches what GpioClx expects. Typically, a mismatch indicates a driver bug that can potentially cause an interrupt storm. GpioClx uses this function to do more extensive state validation in checked (debug) builds, and reduces the number of calls to this function in free (retail) builds to avoid impacting performance. If implemented, this function must directly read the hardware state instead of reading a cached or software-maintained version of the state.

GpioClx calls the *CLIENT_QueryEnabledInterrupts* callback function either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, GpioClx calls the *CLIENT_QueryEnabledInterrupts* function at DIRQL, which is the IRQL at which the ISR in GpioClx runs. Otherwise, this function is called at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

#### Examples

To define a *CLIENT_QueryEnabledInterrupts* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_QueryEnabledInterrupts* callback function that is named `MyEvtGpioQueryEnabledInterrupts`, use the GPIO_CLIENT_QUERY_ENABLED_INTERRUPTS function type, as shown in this code example:

```
GPIO_CLIENT_QUERY_ENABLED_INTERRUPTS MyEvtGpioQueryEnabledInterrupts;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioQueryEnabledInterrupts(
    PVOID Context,
    PGPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS QueryEnabledParameters
    )
{ ... }
```

The GPIO_CLIENT_QUERY_ENABLED_INTERRUPTS function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_QUERY_ENABLED_INTERRUPTS function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_QUERY_ENABLED_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_query_enabled_interrupts_parameters)