# GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION callback function

## Description

The *CLIENT_QueryControllerBasicInformation* event callback function retrieves the hardware attributes of the general-purpose I/O (GPIO) controller.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `Information` [out]

A pointer to a caller-allocated [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure. The *CLIENT_QueryControllerBasicInformation* function writes the GPIO controller hardware attributes and configuration information into this structure.

## Return value

The *CLIENT_QueryControllerBasicInformation* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function.

The *CLIENT_QueryControllerBasicInformation* callback function should set all members of the [CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information) structure, including the **Version** and **Size** members. GpioClx does not initialize the **Size** member before calling this function, but the buffer that the *Information* parameter points to is guaranteed to be large enough to contain the version of this structure that the GPIO controller driver uses.

To register your driver's *CLIENT_QueryControllerBasicInformation* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_QueryControllerBasicInformation* function pointer.

#### Examples

To define a *CLIENT_QueryControllerBasicInformation* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_QueryControllerBasicInformation* callback function that is named `MyEvtGpioQueryControllerBasicInformation`, use the GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION function type, as shown in this code example:

```
GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION MyEvtGpioQueryDeviceInformation;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioQueryDeviceInformation(
    PVOID Context,
    PCLIENT_CONTROLLER_BASIC_INFORMATION Information
    )
{ ... }
```

The GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_QUERY_CONTROLLER_BASIC_INFORMATION function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_CONTROLLER_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_client_controller_basic_information)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)