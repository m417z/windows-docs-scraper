# GPIO_CLX_ProcessAddDevicePostDeviceCreate function

## Description

The **GPIO_CLX_ProcessAddDevicePostDeviceCreate** method passes a framework device object to the GPIO framework extension (GpioClx).

## Parameters

### `Driver` [in]

A WDFDRIVER handle to the framework driver object for the GPIO controller driver.

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the GPIO controller. The caller obtained this handle from the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) call that created the device object.

## Return value

**GPIO_CLX_ProcessAddDevicePostDeviceCreate** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The caller is not a registered client of GpioClx. |
| **STATUS_UNSUCCESSFUL** | The framework failed to find the device name of the GPIO controller. |
| **STATUS_INSUFFICIENT_RESOURCES** | Out of memory. |

## Remarks

Your GPIO controller driver must call this method in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, after the call to the [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) method that creates the device object (FDO) that represents the GPIO controller. Otherwise, GpioClx cannot handle I/O requests or process interrupts for the new device object.

For a code example that contains a call to **GPIO_CLX_ProcessAddDevicePostDeviceCreate**, see [GPIO_CLX_ProcessAddDevicePreDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_processadddevicepredevicecreate).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[GPIO_CLX_ProcessAddDevicePreDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_processadddevicepredevicecreate)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)