# WdfFdoInitSetFilter function

## Description

[Applies to KMDF and UMDF]

The **WdfFdoInitSetFilter** method identifies the calling driver as an upper-level or lower-level [filter driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/filter-drivers), for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

## Remarks

Filter drivers typically process some I/O requests, but they simply pass most requests to the next driver in the driver stack. If the framework receives a request for one of your driver's devices, and if the driver has not created an I/O queue to receive requests that match the request type, the way the framework processes the request depends on whether the driver has called **WdfFdoInitSetFilter**:

* If a driver calls **WdfFdoInitSetFilter**, the driver framework forwards the request to the next driver.
* If a driver does not call **WdfFdoInitSetFilter**, the framework completes the request with a status value of STATUS_INVALID_DEVICE_REQUEST.

If a driver calls **WdfFdoInitSetFilter**, it should not call [WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype), [WdfDeviceInitSetPowerInrush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerinrush), or [WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable) because the framework ignores the information provided by these calls. Instead, the framework obtains this information from the next-lower device object in the driver's [device stack](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdm-concepts-for-kmdf-drivers).

The driver must call **WdfFdoInitSetFilter** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object). In addition, the driver must call **WdfFdoInitSetFilter** before returning from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

For more information about **WdfFdoInitSetFilter**, see [Creating Device Objects in a Filter Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-filter-driver), [Creating I/O Queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues) and [Forwarding I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests).

#### Examples

The following code example identifies the calling driver as a filter driver for the specified device.

```cpp
WdfFdoInitSetFilter(DeviceInit);
```

## See also

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)