# NdisGetDeviceReservedExtension function

## Description

The
**NdisGetDeviceReservedExtension** function gets a pointer to the device extension that is associated
with a device object.

## Parameters

### `DeviceObject` [in]

A pointer to a
[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

## Return value

**NdisGetDeviceReservedExtension** returns a pointer to the device extension. If an error occurs, it
returns **NULL**.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)