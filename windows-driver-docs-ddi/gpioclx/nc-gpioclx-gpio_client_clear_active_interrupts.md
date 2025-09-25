# GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS callback function

## Description

The *CLIENT_ClearActiveInterrupts* event callback function clears active interrupts on a set of general-purpose I/O (GPIO) pins that are configured as interrupt inputs.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `ClearParameters` [in, out]

A pointer to a [GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_clear_active_interrupts_parameters) structure that, on entry, describes the GPIO interrupt pins to clear, and, on exit, contains the status of the clear operation.

## Return value

The *CLIENT_ClearActiveInterrupts* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the general-purpose I/O (GPIO) controller driver. The GPIO framework extension (GpioClx) calls this function to clear active interrupts on GPIO pins that are configured as interrupt request inputs.

This callback function is optional. If the GPIO controller hardware automatically clears active interrupt status bits when they are read, the driver should not register a *CLIENT_ClearActiveInterrupts* callback function. For more information, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

To register your driver's *CLIENT_ClearActiveInterrupts* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a **GPIO_CLIENT_REGISTRATION_PACKET** structure that contains a *CLIENT_ClearActiveInterrupts* function pointer.

GpioClx calls the *CLIENT_ClearActiveInterrupts* callback function at either PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, GpioClx calls the *CLIENT_ClearActiveInterrupts* function at DIRQL, which is the IRQL at which the ISR in GpioClx runs. Otherwise, this function is called at PASSIVE_LEVEL. For more information about this flag bit, see [Interrupt-Related Callbacks](https://learn.microsoft.com/windows-hardware/drivers/gpio/interrupt-related-callbacks).

#### Examples

To define a *CLIENT_ClearActiveInterrupts* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_ClearActiveInterrupts* callback function that is named `MyEvtGpioClearActiveInterrupts`, use the GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS function type, as shown in this code example:

```
GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS MyEvtGpioClearActiveInterrupts;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioClearActiveInterrupts(
    PVOID Context,
    PGPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS ClearParameters
    )
{ ... }
```

The GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_CLEAR_ACTIVE_INTERRUPTS function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CLEAR_ACTIVE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_clear_active_interrupts_parameters)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)