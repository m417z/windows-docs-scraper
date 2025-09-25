# IoGetDeviceAttachmentBaseRef function

## Description

The **IoGetDeviceAttachmentBaseRef** routine returns a pointer to the lowest-level device object in a file system or device driver stack.

## Parameters

### `DeviceObject` [in]

A pointer to a device object in the stack.

## Return value

**IoGetDeviceAttachmentBaseRef** returns a pointer to the device object at the bottom of the file system or device driver stack. If the given device object is not attached to a driver stack, **IoGetDeviceAttachmentBaseRef** returns the device object pointer in *DeviceObject*.

## Remarks

A file system filter driver typically calls **IoGetDeviceAttachmentBaseRef** to get the lowest-level device object in a file system driver stack. Often this is done when the filter driver receives notification that a file system has registered or unregistered itself as an active file system. The filter driver's notification callback routine calls **IoGetDeviceAttachmentBaseRef** to get a pointer to the file system's control device object, and then calls [ObQueryNameString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obquerynamestring) to retrieve this object's name for debugging purposes.

**IoGetDeviceAttachmentBaseRef** increments the reference count on the device object at the bottom of the stack. Thus every successful call to **IoGetDeviceAttachmentBaseRef** must be matched by a subsequent call to [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

## See also

[IoEnumerateDeviceObjectList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioenumeratedeviceobjectlist)

[IoGetLowerDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetlowerdeviceobject)

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObQueryNameString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obquerynamestring)