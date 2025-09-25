# GPIO_CLIENT_WRITE_PINS_MASK callback function

## Description

The *CLIENT_WriteGpioPinsUsingMask* event callback function writes to a set of general-purpose I/O (GPIO) pins that are configured as data outputs.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `WriteParameters` [in]

A pointer to a [GPIO_WRITE_PINS_MASK_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_write_pins_mask_parameters) structure that describes a bank of GPIO pins and that contains the data to write to these pins.

## Return value

The *CLIENT_WriteGpioPinsUsingMask* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. GpioClx calls this function to write to a designated set of GPIO pins.

The GPIO pins that are to be written to by this function are designated by two 64-bit masks. The first mask specifies a group of GPIO pins that are to be set to 1; a bit in this mask is 1 if the corresponding GPIO pin is to be set to 1. The second mask specifies a group of GPIO pins that are to be set to 0; a bit in this mask is 1 if the corresponding GPIO pin is to be set to 0.

To register your driver's *CLIENT_WriteGpioPinsUsingMask* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_WriteGpioPinsUsingMask* function pointer.

The *CLIENT_WriteGpioPinsUsingMask* function can be called from the interrupt service routine (ISR) in GpioClx. This ISR runs either at PASSIVE_LEVEL or DIRQL, depending on the device information that the [CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information) callback function supplies to GpioClx. The *CLIENT_QueryControllerBasicInformation* function provides device information in the form of a [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. If the **MemoryMappedController** flag bit is set in the **Flags** member of this structure, the GpioClx ISR runs at DIRQL and calls the *CLIENT_WriteGpioPinsUsingMask* function at DIRQL. Otherwise, the ISR runs at PASSIVE_LEVEL and calls the function at PASSIVE_LEVEL. For more information about this flag bit, see [Optional and Required GPIO Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/gpio/optional-and-required-gpio-callback-functions).

#### Examples

To define a *CLIENT_WriteGpioPinsUsingMask* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_WriteGpioPinsUsingMask* callback function that is named `MyEvtGpioWriteGpioPinsUsingMask`, use the GPIO_CLIENT_WRITE_PINS_MASK function type, as shown in this code example:

```
GPIO_CLIENT_WRITE_PINS_MASK  MyEvtGpioWritePinsUsingMask;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
VOID
  MyEvtGpioWritePinsUsingMask(
    PVOID Context,
    PGPIO_WRITE_PINS_MASK_PARAMETERS WriteParameters
    )
{ ... }
```

The GPIO_CLIENT_WRITE_PINS_MASK function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_WRITE_PINS_MASK function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[CLIENT_QueryControllerBasicInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_query_controller_basic_information)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)

[GPIO_WRITE_PINS_MASK_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_write_pins_mask_parameters)