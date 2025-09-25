# FltIsFltMgrVolumeDeviceObject function

## Description

The **FltIsFltMgrVolumeDeviceObject** routine determines whether the given device object belongs to filter manager and if the device object is a volume device object.

## Parameters

### `DeviceObject` [in]

A pointer to the device object ([DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)) to test.

## Return value

The **FltIsFltMgrVolumeDeviceObject** routine returns **TRUE** if *DeviceObject* is a filter manager volume device object; otherwise, it returns **FALSE**.

## Remarks

None

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)