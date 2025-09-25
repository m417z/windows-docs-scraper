# GPIO_CLIENT_DISABLE_INTERRUPT callback function

## Description

The *CLIENT_DisableInterrupt* event callback function disables interrupts on a general-purpose I/O (GPIO) pin that is configured as an interrupt input.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `DisableParameters` [in]

A pointer to a [GPIO_DISABLE_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_disable_interrupt_parameters) structure that describes the GPIO interrupt pin.

## Return value

The *CLIENT_DisableInterrupt* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. GpioClx calls this function to disable interrupts on a GPIO pin that is configured as an interrupt request input.

To register your driver's *CLIENT_DisableInterrupt* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_DisableInterrupt* function pointer.

GpioClx always calls the [CLIENT_EnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_enable_interrupt) and *CLIENT_DisableInterrupt* callback functions at IRQL = PASSIVE_LEVEL. However, if the GPIO registers are memory-mapped, GpioClx calls the other interrupt-related callback functions from its ISR at DIRQL. In this case, the *CLIENT_EnableInterrupt* and *CLIENT_DisableInterrupt* functions should use the GPIO interrupt lock to synchronize their interrupt-related operations to the ISR. For more information, see [Interrupt Synchronization for GPIO Controller Drivers](https://learn.microsoft.com/windows-hardware/drivers/gpio/interrupt-synchronization-for-gpio-controller-drivers).

#### Examples

To define a *CLIENT_DisableInterrupt* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_DisableInterrupt* callback function that is named `MyEvtGpioDisableInterrupt`, use the GPIO_CLIENT_DISABLE_INTERRUPT function type, as shown in this code example:

```
GPIO_CLIENT_DISABLE_INTERRUPT MyEvtGpioDisableInterrupt;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
VOID
  MyEvtGpioDisableInterrupt(
    PVOID Context,
    PGPIO_DISABLE_INTERRUPT_PARAMETERS DisableParameters
    )
{ ... }
```

The GPIO_CLIENT_DISABLE_INTERRUPT function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_DISABLE_INTERRUPT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_EnableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_enable_interrupt)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_DISABLE_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_disable_interrupt_parameters)