# GPIO_CLIENT_ENABLE_INTERRUPT callback function

## Description

The *CLIENT_EnableInterrupt* event callback function enables interrupts on a general-purpose I/O (GPIO) pin that is configured as an interrupt input.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `EnableParameters` [in]

A pointer to a [GPIO_ENABLE_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_enable_interrupt_parameters) structure that specifies a GPIO pin and describes the interrupt attributes of this pin.

## Return value

The *CLIENT_EnableInterrupt* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to enable interrupts on a GPIO pin that is configured as an interrupt request input.

To register your driver's *CLIENT_EnableInterrupt* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_EnableInterrupt* function pointer.

GpioClx always calls the *CLIENT_EnableInterrupt* and [CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt) callback functions at IRQL = PASSIVE_LEVEL. However, if the GPIO registers are memory-mapped, GpioClx calls the other interrupt-related callback functions from its ISR at DIRQL. In this case, the *CLIENT_EnableInterrupt* and *CLIENT_DisableInterrupt* functions should use the GPIO interrupt lock to synchronize their interrupt-related operations to the ISR. For more information, see [Interrupt Synchronization for GPIO Controller Drivers](https://learn.microsoft.com/windows-hardware/drivers/gpio/interrupt-synchronization-for-gpio-controller-drivers).

### Examples

To define a *CLIENT_EnableInterrupt* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_EnableInterrupt* callback function that is named `MyEvtGpioEnableInterrupt`, use the GPIO_CLIENT_ENABLE_INTERRUPT function type, as shown in this code example:

```cpp
GPIO_CLIENT_ENABLE_INTERRUPT MyEvtGpioEnableInterrupt;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioEnableInterrupt(
    PVOID Context,
    PGPIO_ENABLE_INTERRUPT_PARAMETERS InterruptParameters
    )
{ ... }
```

The GPIO_CLIENT_ENABLE_INTERRUPT function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_ENABLE_INTERRUPT function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

- [CLIENT_DisableInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_disable_interrupt)
- [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)
- [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)
- [GPIO_ENABLE_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_enable_interrupt_parameters)