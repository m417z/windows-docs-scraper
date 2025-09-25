# IoGetAttachedDeviceReference function (wdm.h)

## Description

The **IoGetAttachedDeviceReference** routine returns a pointer to the highest level device object in a driver stack and increments the reference count on that object.

## Parameters

### `DeviceObject` [in]

Pointer to the device object for which the topmost attached device object is retrieved.

## Return value

**IoGetAttachedDeviceReference** returns a pointer to the highest level device object in a stack of attached device objects after incrementing the reference count on the object.

## Remarks

If the device object at *DeviceObject* has no device objects attached to it, *DeviceObject* and the returned pointer are equal.

Device driver writers must ensure that when they have completed all operations that required them to make this call, that they call [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) with the device object pointer returned by this routine. Failure to do so will prevent the system from freeing or deleting the device object because of an outstanding reference count.

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)