# GPIO_CLIENT_PREPARE_CONTROLLER callback function

## Description

The *CLIENT_PrepareController* event callback function performs any operations that are needed to make the general-purpose I/O (GPIO) controller ready to be accessed by the GPIO controller driver.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the GPIO controller.

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts).

### `ResourcesRaw` [in]

A WDFCMRESLIST handle to a collection of framework resource objects. This collection identifies the raw (bus-relative) hardware resources that the Plug and Play (PnP) manager has assigned to the GPIO controller device.

### `ResourcesTranslated` [in]

A WDFCMRESLIST handle to a collection of framework resource objects. This collection identifies the translated (system-physical) hardware resources that the PnP manager has assigned to the GPIO controller device.

## Return value

The *CLIENT_PrepareController* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

This callback function is implemented by the GPIO controller driver. The GPIO framework extension (GpioClx) calls this function to initialize the hardware resources that the GPIO controller driver needs so that it can access the GPIO controller device.

The *ResourcesRaw* and *ResourcesTranslated* parameters are handles to lists of raw and translated resources. These lists describe hardware resources that the PnP manager has assigned to the GPIO controller device that is specified by the *Device* parameter. For more information, see [Raw and Translated Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources).

During the *CLIENT_PrepareController* callback, the GPIO controller driver can acquire the hardware resources that it requires from the *ResourcesRaw* or *ResourcesTranslated* list. If the GPIO controller device is memory-mapped, the driver should map the bus-relative memory address range or ranges that are assigned to the device's hardware registers to system virtual addresses. For more information, see [Mapping Bus-Relative Addresses to Virtual Addresses](https://learn.microsoft.com/windows-hardware/drivers/kernel/mapping-bus-relative-addresses-to-virtual-addresses).

If the GPIO controller is not memory-mapped, the driver's hardware resources contain a connection ID instead of a memory range. The driver uses this ID to open a logical connection to the GPIO controller, and sends I/O requests through this connection to access the controller's registers.

GpioClx connects to (and later disconnects from) any interrupt resource that the PnP manager assigns to the GPIO controller. If GpioClx receives such an interrupt resource, it does not remove this interrupt resource from the resource lists that it passes to the *CLIENT_PrepareController* callback function. However, the GPIO controller driver should not try to connect to (or later disconnect from) any interrupt resource that it finds in these lists.

The [CLIENT_ReleaseController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_release_controller) event callback function performs operations that are needed when the GPIO controller device is no longer accessible. During this callback, the GPIO controller driver should release any hardware resources that it acquired during the previous *CLIENT_PrepareController* callback.

To register your driver's *CLIENT_PrepareController* callback function, call the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method. This method accepts, as an input parameter, a pointer to a [GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet) structure that contains a *CLIENT_PrepareController* function pointer.

Although the *CLIENT_PrepareController* callback function is called at IRQL = PASSIVE_LEVEL, you should not make this function pageable. The *CLIENT_PrepareController* callback is in the critical timing path for restoring power to the devices in the hardware platform and, for performance reasons, it should not be delayed by page faults.

#### Examples

To define a *CLIENT_PrepareController* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *CLIENT_PrepareController* callback function that is named `MyEvtGpioPrepareController`, use the GPIO_CLIENT_PREPARE_CONTROLLER function type, as shown in this code example:

```
GPIO_CLIENT_PREPARE_CONTROLLER MyEvtGpioPrepareController;
```

Then, implement your callback function as follows:

```
_Use_decl_annotations_
NTSTATUS
  MyEvtGpioPrepareController(
    WDFDEVICE Device,
    PVOID Context,
    WDFCMRESLIST ResourcesRaw,
    WDFCMRESLIST ResourcesTranslated
)
{ ... }
```

The GPIO_CLIENT_PREPARE_CONTROLLER function type is defined in the Gpioclx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the GPIO_CLIENT_PREPARE_CONTROLLER function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CLIENT_ReleaseController](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nc-gpioclx-gpio_client_release_controller)

[GPIO_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/ns-gpioclx-_gpio_client_registration_packet)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)