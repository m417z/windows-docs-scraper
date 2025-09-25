# GPIO_CLIENT_MASK_INTERRUPTS callback function

## Description

The *CLIENT_MaskInterrupts* event callback function masks interrupts on a set of general-purpose I/O (GPIO) pins that are configured as interrupt inputs.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `MaskParameters` [in, out]

A pointer to a [GPIO_MASK_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_mask_interrupt_parameters) structure that, on entry, describes the GPIO interrupt pins to mask, and, on exit, contains the status of the mask operation.

## Return value

The *CLIENT_MaskInterrupts* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to mask interrupts on GPIO pins that are configured as interrupt request inputs. For more information, see [GPIO Interrupt Masks](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-interrupt-masks).

To register your driver's *CLIENT_MaskInterrupts* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a **GPIO_CLIENT_REGISTRATION_PACKET** structure that contains a *CLIENT_MaskInterrupts* function pointer.

The *CLIENT_MaskInterrupts* function is called from the interrupt service routine (ISR) in GpioClx. This ISR runs either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, the GpioClx ISR runs at DIRQL and calls the *CLIENT_MaskInterrupts* function at DIRQL. Otherwise, the ISR runs at PASSIVE_LEVEL and calls the function at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

A *CLIENT_MaskInterrupts* call that fails to set the interrupt mask to the requested value must set the **FailedMask** member of the **GPIO_MASK_INTERRUPT_PARAMETERS** structure to a nonzero value and return an appropriate error status code. The *CLIENT_MaskInterrupts* function for a memory-mapped GPIO controller is expected to always succeed in setting the interrupt mask to the requested value. However, the *CLIENT_MaskInterrupts* function for a controller that is not memory-mapped must send an I/O request to the controller to set the mask, and this request might fail. If the request fails to set the mask, the function must indicate this failure in the value that it writes to the **FailedMask** member.

#### Examples

To define a *CLIENT_MaskInterrupts* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_MaskInterrupts* callback function that is named `MyEvtGpioMaskInterrupts`, use the GPIO_CLIENT_MASK_INTERRUPTS function type, as shown in this code example:

```
GPIO_CLIENT_MASK_INTERRUPTS MyEvtGpioMaskInterrupts;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioMaskInterrupts(
    PVOID Context,
    PGPIO_MASK_INTERRUPT_PARAMETERS MaskParameters
    )
{ ... }
```

The GPIO_CLIENT_MASK_INTERRUPTS function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_MASK_INTERRUPTS function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_MASK_INTERRUPT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_mask_interrupt_parameters)