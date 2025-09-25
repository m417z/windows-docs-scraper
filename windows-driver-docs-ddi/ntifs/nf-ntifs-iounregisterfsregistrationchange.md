# IoUnregisterFsRegistrationChange function

## Description

The **IoUnregisterFsRegistrationChange** routine unregisters file system filter driver's file system registration change notification routine.

## Parameters

### `DriverObject` [in]

Pointer to the driver object for the filter driver.

### `DriverNotificationRoutine` [in]

A pointer to the [PDRIVER_FS_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-driver_fs_notification) routine, which the file system calls when it registers or unregisters itself.

## Remarks

**IoUnregisterFsRegistrationChange** unregisters a file system filter driver's notification routine so that it is no longer called whenever a file system calls [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) or [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem). **IoUnregisterFsRegistrationChange** also decrements the reference count on the filter driver's driver object.

## See also

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)