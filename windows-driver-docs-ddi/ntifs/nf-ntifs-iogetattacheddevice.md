# IoGetAttachedDevice function

## Description

The **IoGetAttachedDevice** routine returns a pointer to the highest-level device object associated with the specified device.

## Parameters

### `DeviceObject` [in]

A pointer to the device object for which the topmost attached device is to be returned.

## Return value

**IoGetAttachedDevice** returns the highest-level device attached to the specified device.

## Remarks

If the device object specified by **DeviceObject** has no other device objects attached to it, **DeviceObject** and the returned pointer are equal.

**IoGetAttachedDevice** differs from [**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference) in the following respects:

* **IoGetAttachedDevice** does not increment the reference count on the device object. (Thus no matching call to [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) is required.)

* Callers of **IoGetAttachedDevice** must ensure that no device objects are added to or removed from the stack while **IoGetAttachedDevice** is executing. Callers that cannot do this must use [**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference) instead.

## See also

[**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)