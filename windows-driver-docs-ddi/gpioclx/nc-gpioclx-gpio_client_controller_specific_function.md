# GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION callback function

## Description

The *CLIENT_ControllerSpecificFunction* event callback function performs an operation that is specific to a particular general-purpose I/O (GPIO) controller.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `Parameters` [in, out]

A pointer to a [GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_controller_specific_function_parameters) structure that contains the input and output buffers for the controller-specific operation.

## Return value

The *CLIENT_ControllerSpecificFunction* function returns **STATUS_SUCCESS** if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The GPIO controller does not support the operation specified by the input parameters. |
| **STATUS_BUFFER_TOO_SMALL** | The size of the input buffer or output buffer is too small. |

## Remarks

As an option, a GPIO controller driver can support [IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_controller_specific_function) requests. This type of I/O control request (IOCTL) performs controller-specific operations for the benefit of peripheral device drivers that require these operations. To support this IOCTL, a GPIO controller driver implements a *CLIENT_ControllerSpecificFunction* function.

The GPIO framework extension (GpioClx) supports the *CLIENT_ControllerSpecificFunction* function to address the specific needs of certain hardware platforms. Typical GPIO controller drivers do not implement this function. A peripheral device driver that uses **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** requests to perform a hardware-specific operation on one platform risks the loss of compatibility with other platforms that do not support this operation.

Typically, the *CLIENT_ControllerSpecificFunction* function programs the GPIO controller to perform a hardware-specific operation on a set of GPIO pins. The input and output parameters for this operation are defined by the developer for the GPIO controller driver. Only a peripheral device driver that is aware of the particular operations implemented by a GPIO controller driver can request these operations.

When GpioClx receives an **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** request, it checks to see whether the GPIO controller driver has implemented a *CLIENT_ControllerSpecificFunction* function. If so, GpioClx copies the descriptions of the input and output buffers from the IOCTL to a **GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS** structure and passes a pointer to this structure as a parameter to the *CLIENT_ControllerSpecificFunction* function. If the parameter values in the **GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS** structure are valid, the function performs the requested operation and returns STATUS_SUCCESS.

If GpioClx receives an **IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION** request, and the GPIO controller driver does not implement a *CLIENT_ControllerSpecificFunction* function, GpioClx completes the IOCTL with error code STATUS_NOT_IMPLEMENTED.

#### Examples

To define a *CLIENT_ControllerSpecificFunction* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_ControllerSpecificFunction* callback function that is named `MyEvtGpioControllerSpecificFunction`, use the GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION function type, as shown in this code example:

```
GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION MyEvtGpioControllerSpecificFunction;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioControllerSpecificFunction(
    PVOID Context,
    PGPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS Parameters
    )
{ ... }
```

The GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[GPIO_CLIENT_CONTROLLER_SPECIFIC_FUNCTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_controller_specific_function_parameters)

[IOCTL_GPIO_CONTROLLER_SPECIFIC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpio/ni-gpio-ioctl_gpio_controller_specific_function)