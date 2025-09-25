# GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS callback function

## Description

The *CLIENT_QueryActiveInterrupts* event callback function queries the state of a set of general-purpose I/O (GPIO) pins that are configured as interrupt inputs.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `QueryActiveParameters` [in, out]

A pointer to a [GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_query_active_interrupts_parameters) structure that, on entry, describes the GPIO interrupt pins to query, and, on exit, contains the active and enabled interrupt state of these pins.

## Return value

The *CLIENT_QueryActiveInterrupts* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to query a set of GPIO pins that are configured as interrupt request inputs.

The *QueryActiveParameters* parameter points to a caller-allocated **GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS** structure. The caller sets the values of the **BankId** and **EnabledMask** members of this structure. The *CLIENT_QueryActiveInterrupts* function writes to the **ActiveMask** member of the structure.

On entry, the bits that are set in the **EnabledMask** member should match the set of currently enabled interrupts in the bank. On return, the bits that are set in the **ActiveMask** member should correspond to interrupts that are both enabled and active. Thus, if a bit in **EnabledMask** is zero, the corresponding bit in **ActiveMask** must be zero.

To register your driver's *CLIENT_QueryActiveInterrupts* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a **GPIO_CLIENT_REGISTRATION_PACKET** structure that contains a *CLIENT_QueryActiveInterrupts* function pointer.

GpioClx calls the *CLIENT_QueryActiveInterrupts* callback function either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, GpioClx calls the *CLIENT_QueryActiveInterrupts* function at DIRQL, which is the IRQL at which the ISR in GpioClx runs. Otherwise, this function is called at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

#### Examples

To define a *CLIENT_QueryActiveInterrupts* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_QueryActiveInterrupts* callback function that is named `MyEvtGpioQueryActiveInterrupts`, use the GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS function type, as shown in this code example:

```
GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS MyEvtGpioQueryActiveInterrupts;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioQueryActiveInterrupts(
    PVOID Context,
    PGPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS QueryActiveParameters
    )
{ ... }
```

The GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_QUERY_ACTIVE_INTERRUPTS function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_QUERY_ACTIVE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_query_active_interrupts_parameters)