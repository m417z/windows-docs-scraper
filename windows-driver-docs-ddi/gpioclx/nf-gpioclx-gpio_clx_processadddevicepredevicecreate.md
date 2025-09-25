# GPIO_CLX_ProcessAddDevicePreDeviceCreate function

## Description

The **GPIO_CLX_ProcessAddDevicePreDeviceCreate** method loads initialization information into two structures that are passed as input parameters to the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method.

## Parameters

### `Driver` [in]

A WDFDRIVER handle to the framework driver object for the GPIO controller driver.

### `DeviceInit` [in, out]

A pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure. This method loads initialization information into this structure. On return, this structure is ready to be used as an input parameter to the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method.

### `FdoAttributes` [out]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. This method loads initialization information into this structure. On return, this structure is ready to be used as an input parameter to the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method.

## Return value

**GPIO_CLX_ProcessAddDevicePreDeviceCreate** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The caller is not a registered client of GpioClx. |
| **STATUS_INSUFFICIENT_RESOURCES** | Out of memory. |

## Remarks

Your GPIO controller driver must call this method in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, before the call to the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method that creates the device object (FDO) that represents the GPIO controller. Otherwise, the GPIO framework extension (GpioClx) cannot handle I/O requests or process interrupts for the new framework device object.

#### Examples

The following code example shows the *EvtDriverDeviceAdd* callback function in the GPIO controller driver for an "XYZ" GPIO controller device.

```
NTSTATUS
  XyzEvtDriverDeviceAdd(
    _In_ WDFDRIVER Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
{
    WDFDEVICE Device;
    WDF_OBJECT_ATTRIBUTES FdoAttributes;
    NTSTATUS Status;

    Status = GPIO_CLX_ProcessAddDevicePreDeviceCreate(Driver,
                                                      DeviceInit,
                                                      &FdoAttributes);
    if (!NT_SUCCESS(Status)) {
        goto ExitDeviceAdd;
    }

    //
    // Call the framework to create the device and attach it to the lower stack.
    //

    Status = WdfDeviceCreate(&DeviceInit, &FdoAttributes, &Device);
    if (!NT_SUCCESS(Status)) {
        goto ExitDeviceAdd;
    }

    Status = GPIO_CLX_ProcessAddDevicePostDeviceCreate(Driver, Device);
    if (!NT_SUCCESS(Status)) {
        goto ExitDeviceAdd;
    }

ExitDeviceAdd:
    return Status;
}
```

In the preceding code example, the **WdfDeviceCreate** call creates the framework device object that represents the GPIO controller device. The two input parameters for this call point to [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) and [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structures. These structures are modified by the **GPIO_CLX_ProcessAddDevicePreDeviceCreate** call, which precedes the **WdfDeviceCreate** call. The output parameter, *Device*, from the **WdfDeviceCreate** call is an input parameter to the [GPIO_CLX_ProcessAddDevicePostDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_processadddevicepostdevicecreate) call, which follows the **WdfDeviceCreate** call.

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[GPIO_CLX_ProcessAddDevicePostDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_processadddevicepostdevicecreate)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)