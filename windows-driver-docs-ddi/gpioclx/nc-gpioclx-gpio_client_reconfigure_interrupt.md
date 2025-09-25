# GPIO_CLIENT_RECONFIGURE_INTERRUPT callback function

## Description

The *CLIENT_ReconfigureInterrupt* event callback function reconfigures a general-purpose I/O (GPIO) pin that is used as an interrupt input.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `ReconfigureParameters` [in]

A pointer to a [GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_reconfigure_interrupts_parameters) structure that specifies how to reconfigure the GPIO interrupt pin.

## Return value

The *CLIENT_ReconfigureInterrupt* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

The GPIO framework extension (GpioClx) might call the *CLIENT_ReconfigureInterrupt* function to change the interrupt mode or interrupt polarity of a GPIO pin that is used as an interrupt input.

For example, if the GPIO controller hardware does not directly support active-both interrupts, but can be configured to support active-high and active-low level-mode interrupts, GpioClx can emulate an active-both interrupt pin by calling the *CLIENT_ReconfigureInterrupt* function to alternately configure a GPIO pin for active-high and active-low level-mode interrupts. For more information about active-both interrupts, see the description of the **EmulateActiveBoth** flag in [CONTROLLER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_controller_attribute_flags).

GpioClx calls the *CLIENT_ReconfigureInterrupt* callback function either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, GpioClx calls the *CLIENT_ReconfigureInterrupt* function at DIRQL, which is the IRQL at which the ISR in GpioClx runs. Otherwise, this function is called at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

#### Examples

To define a *CLIENT_ReconfigureInterrupt* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_ReconfigureInterrupt* callback function that is named `MyEvtGpioReconfigureInterrupt`, use the GPIO_CLIENT_RECONFIGURE_INTERRUPT function type, as shown in this code example:

```
GPIO_CLIENT_RECONFIGURE_INTERRUPT MyEvtGpioReconfigureInterrupt;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioReconfigureInterrupt(
    PVOID Context,
    PGPIO_RECONFIGURE_INTERRUPTS_PARAMETERS ReconfigureParameters
    )
{ ... }
```

The GPIO_CLIENT_RECONFIGURE_INTERRUPT function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_RECONFIGURE_INTERRUPT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[CONTROLLER_ATTRIBUTE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_controller_attribute_flags)

[GPIO_RECONFIGURE_INTERRUPTS_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_reconfigure_interrupts_parameters)