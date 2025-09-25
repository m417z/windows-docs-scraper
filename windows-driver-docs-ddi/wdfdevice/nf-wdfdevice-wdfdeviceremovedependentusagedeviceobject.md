# WdfDeviceRemoveDependentUsageDeviceObject function

## Description

[Applies to KMDF only]

The **WdfDeviceRemoveDependentUsageDeviceObject** method indicates that a specified device no longer depends on another device when the specified device is used to store [special files](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DependentDevice` [in]

A pointer to a caller-supplied [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that identifies a device that *Device* depends on.

## Remarks

Your driver can call **WdfDeviceRemoveDependentUsageDeviceObject** to remove a device dependency that a previous call to [WdfDeviceAddDependentUsageDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceadddependentusagedeviceobject) created.

For more information about **WdfDeviceRemoveDependentUsageDeviceObject** and **WdfDeviceRemoveDependentUsageDeviceObject**, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).

#### Examples

The following code example removes a device (**pDeviceObject**) from the list of devices that another device (**device**) depends on.

```cpp
status = WdfDeviceRemoveDependentUsageDeviceObject(
                                                device,
                                                pDeviceObject
                                                );
```

## See also

[WdfDeviceAddDependentUsageDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceadddependentusagedeviceobject)