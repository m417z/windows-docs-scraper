# IoUnregisterFileSystem function

## Description

The **IoUnregisterFileSystem** routine removes a file system's control device object from the global file system queue.

## Parameters

### `DeviceObject` [in]

Pointer to the control device object for the file system.

## Remarks

**IoUnregisterFileSystem** unregisters the file system as an active file system by removing the file system's control device object from the global file system queue, and decrements the reference count on the file system's control device object.

**IoUnregisterFileSystem** calls the notification routines of file system filter drivers that have registered for this notification by calling [IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange).

## See also

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)