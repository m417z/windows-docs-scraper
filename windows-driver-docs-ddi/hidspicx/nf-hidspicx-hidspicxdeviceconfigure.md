## Description

After calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), and still in its [**EVT_WDF_DRIVER_DEVICE_ADD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback, the client driver calls this function with a pointer to a [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config) structure, specifying interfaces the class extension will use to communicate with the device. The class extension initializes its internal state, returning whether or not this is successful.

## Parameters

### `Device` [in]

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `DeviceConfiguration` [in]

Pointer to an initialized [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config) structure, specifying the details of the callbacks and queues to be used for communication between the class extension and client driver.

## Return value

[**NTSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) indicating whether the class extension was able to successfully configure the device.

## Remarks

The class extension initializes the internal state, returning whether or not this is successful.

The client driver may create a default queue before or after making this callback, in order to handle IOCTLs not handled by the class extension.

Client drivers should not attempt to acquire power policy ownership to configure power policy settings. [**HidClass**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidclass/) and [**HidSpiCx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/) are responsible for managing the power policy of the device.

## See also

- [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)
- [**EVT_WDF_DRIVER_DEVICE_ADD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)
- [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config)
- [**HIDSPICX_REPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_report)