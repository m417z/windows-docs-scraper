# GPIO_CLIENT_STOP_CONTROLLER callback function

## Description

The *CLIENT_StopController* event callback function performs operations that are needed to prepare the general-purpose I/O (GPIO) controller device to exit the D0 power state.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `SaveContext` [in]

Whether the client driver should save the current hardware context of the GPIO controller device. If TRUE, the hardware context should be saved. If FALSE, the hardware context should not be saved. For more information, see Remarks.

### `TargetState` [in]

The target device power state. This parameter is a [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state) enumeration value that specifies the low-power state that the device is to enter when it exits the D0 power state. The GPIO controller driver can use this information to determine how to configure the controller device before it leaves D0.

## Return value

The *CLIENT_StopController* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to prepare the GPIO controller device to be turned off or to transition to a low-power state. This callback function must perform any operations that are necessary before the device enters a low-power state, such as saving any information that the driver will need later after the device is restored to the D0 power state.

Typically, the *CLIENT_StopController* callback function configures the GPIO pins to a platform-specific initial state. For example, this function might configure all of the GPIO pins as inputs to prevent output transients from occurring when the GPIO controller device is turned off.

To register your driver's *CLIENT_StopController* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_StopController* function pointer.

Although the *CLIENT_StopController* callback function is called at IRQL = PASSIVE_LEVEL, you should not make this function pageable. The *CLIENT_StopController* callback is in the critical timing path for restoring power to the devices in the hardware platform and, for performance reasons, it should not be delayed by page faults.

#### Examples

To define a *CLIENT_StopController* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_StopController* callback function that is named `MyEvtGpioStopController`, use the GPIO_CLIENT_STOP_CONTROLLER function type, as shown in this code example:

```
GPIO_CLIENT_STOP_CONTROLLER  MyEvtGpioStopController;

```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
VOID
  MyEvtGpioStopController(
    PVOID Context,
    BOOLEAN RestoreContext,
    WDF_POWER_DEVICE_STATE TargetState
    )
{ ... }
```

The GPIO_CLIENT_STOP_CONTROLLER function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_STOP_CONTROLLER function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)