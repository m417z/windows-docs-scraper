# IoGetRelatedDeviceObject function

## Description

Given a file object, the **IoGetRelatedDeviceObject** routine returns a pointer to the corresponding device object.

## Parameters

### `FileObject` [in]

Pointer to the file object.

## Return value

**IoGetRelatedDeviceObject** returns a pointer to the device object.

## Remarks

When called on a file object that represents the underlying storage device, **IoGetRelatedDeviceObject** returns the highest-level device object in the storage device stack. To obtain the highest-level device object in the file system driver stack, drivers must call **IoGetRelatedDeviceObject** on a file object that represents the file system's driver stack, and the file system must currently be mounted. (Otherwise, the storage device stack is traversed instead of the file system stack.)

To ensure that the file system is mounted on the storage device, the driver must have specified an appropriate access mask, such as FILE_READ_DATA or FILE_WRITE_ATTRIBUTES, when opening the file or device represented by the file object. Specifying FILE_READ_ATTRIBUTES does not cause the file system to be mounted.

The caller must be running at IRQL <= DISPATCH_LEVEL. Usually, callers of this routine are running at IRQL = PASSIVE_LEVEL.

## See also

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)