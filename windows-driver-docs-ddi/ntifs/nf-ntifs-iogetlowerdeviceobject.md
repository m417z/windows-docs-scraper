# IoGetLowerDeviceObject function

## Description

The **IoGetLowerDeviceObject** routine returns a pointer to the next-lower-level device object on the driver stack.

## Parameters

### `DeviceObject` [in]

A pointer to the device object in the stack for which the next-lower-level device object is to be returned.

## Return value

**IoGetLowerDeviceObject** returns a pointer to the next-lower-level device object on the driver stack.

## Remarks

Given a pointer to a device object in a file system or device driver stack, **IoGetLowerDeviceObject** returns a pointer to the next-lower-level device object on the stack.

**IoGetLowerDeviceObject** returns NULL if:

* The next-lower-level driver is not loaded.

* The next-lower-level driver is currently being unloaded, removed, or deleted.

* The device object pointed to by **DeviceObject** is the lowest device object in the driver stack.

A file system filter driver typically uses **IoGetLowerDeviceObject** to determine whether it is already attached to the filter driver stack that is chained above a given file system device object. First, the filter calls [**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference) to get a pointer to the topmost device object in the stack. Then it calls **IoGetLowerDeviceObject** repeatedly to walk the driver stack, checking each device object to see whether the object belongs to the filter driver.

**IoGetLowerDeviceObject** increments the reference count on the next-lower-level device object if there is one. Thus every call to **IoGetLowerDeviceObject** that doesn't return NULL must be matched by a subsequent call [**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

## See also

[**IoGetAttachedDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevice)

[**IoGetAttachedDeviceReference**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetattacheddevicereference)

[**ObDereferenceObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)