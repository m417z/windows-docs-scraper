# IoRegisterFileSystem function

## Description

The **IoRegisterFileSystem** routine adds a file system's control device object to the global file system queue.

## Parameters

### `DeviceObject` [in]

Pointer to the control device object for the file system.

## Remarks

**IoRegisterFileSystem** registers a file system as an active file system by inserting the file system's control device object into the global file system queue, and increments the reference count on the file system's control device object.

The file system control device object's device type must be one of the following:

FILE_DEVICE_NETWORK_FILE_SYSTEM

FILE_DEVICE_CD_ROM_FILE_SYSTEM

FILE_DEVICE_DISK_FILE_SYSTEM

If the device type is not one of these values, the file system is not registered.

In addition, the file system control device object must be named. If it is not named, this does not cause the call to **IoRegisterFileSystem** to fail. However, file system filter drivers, as well as many system components and support routines, use this name to distinguish the file system's control device objects, which are always named, from its volume device objects, which are never named.

If the DO_LOW_PRIORITY_FILESYSTEM flag is set on the file system's control device object, the device object is inserted into the next-to-last position in the queue. (The RAW file system occupies the last position in the queue.) If this flag is not set, the device object is inserted at the head of the queue.

**IoRegisterFileSystem** calls the notification routines of file system filter drivers that have registered for this notification by calling [IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange) or [IoRegisterFsRegistrationChangeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangeex).

**Note** In Microsoft Windows XP and later, when a file system filter driver calls [IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange), its notification routine is also called immediately for any file systems that have already called **IoRegisterFileSystem**.

## See also

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoRegisterFsRegistrationChangeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangeex)

[IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)