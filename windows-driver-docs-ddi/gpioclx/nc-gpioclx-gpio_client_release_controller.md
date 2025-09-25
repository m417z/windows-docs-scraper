# GPIO_CLIENT_RELEASE_CONTROLLER callback function

## Description

The *CLIENT_ReleaseController* event callback function performs operations that are needed when the general-purpose I/O (GPIO) controller device is no longer accessible.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the GPIO controller.

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

## Return value

The *CLIENT_ReleaseController* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function after the GPIO controller device is no longer accessible.

During the *CLIENT_ReleaseController* callback, the GPIO controller driver should release any hardware resources that it acquired as a result of the preceding call to the [CLIENT_PrepareController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_prepare_controller) callback function. In the case of a memory-mapped GPIO controller device, the driver should unmap the memory address range or ranges that are assigned to the hardware registers. For a controller that is not memory-mapped, the driver should close the previously opened logical connection to the controller.

To register your driver's *CLIENT_ReleaseController* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_ReleaseController* function pointer.

Although the *CLIENT_ReleaseController* callback function is called at IRQL = PASSIVE_LEVEL, you should not make this function pageable. The *CLIENT_ReleaseController* callback is in the critical timing path for restoring power to the devices in the hardware platform and, for performance reasons, it should not be delayed by page faults.

#### Examples

To define a *CLIENT_ReleaseController* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_ReleaseController* callback function that is named `MyEvtGpioReleaseController`, use the GPIO_CLIENT_RELEASE_CONTROLLER function type, as shown in this code example:

```
GPIO_CLIENT_RELEASE_CONTROLLER  MyEvtGpioReleaseController;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioReleaseController(
    WDFDEVICE Device,
    PVOID Context
)
{ ... }
```

The GPIO_CLIENT_RELEASE_CONTROLLER function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_RELEASE_CONTROLLER function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)