# WdfDeviceAddDependentUsageDeviceObject function

## Description

[Applies to KMDF only]

The **WdfDeviceAddDependentUsageDeviceObject** method indicates that a specified device depends on another device when the specified device is used to store [special files](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DependentDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that identifies a device that *Device* depends on.

## Return value

If the operation succeeds, **WdfDeviceAddDependentUsageDeviceObject** method returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *DependentDevice* is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | A memory allocation failed. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver can call **WdfDeviceAddDependentUsageDeviceObject** to indicate that the device identified by *Device* depends on the device identified by *DependentDevice*, when *Device* supports special files. If your driver calls **WdfDeviceAddDependentUsageDeviceObject**, the framework calls the [EvtDeviceUsageNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification) callback functions in *DependentDevice*'s drivers before it calls the *EvtDeviceUsageNotification* callback functions in *Device*'s drivers.

Your driver can call **WdfDeviceAddDependentUsageDeviceObject** multiple times to identify multiple devices that *Device* depends on to support special files.

After a driver has called **WdfDeviceAddDependentUsageDeviceObject**, it can call [WdfDeviceRemoveDependentUsageDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceremovedependentusagedeviceobject) to remove the device identified by *DependentDevice* from the list of devices that *Device* depends on.

For more information about special files, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).

#### Examples

The following code example adds a device (**pDeviceObject**) to the list of devices that another device (**Device**) depends on.

```cpp
status = WdfDeviceAddDependentUsageDeviceObject(
                                                device,
                                                pDeviceObject
                                                );
```

## See also

[EvtDeviceUsageNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification)

[WdfDeviceRemoveDependentUsageDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceremovedependentusagedeviceobject)