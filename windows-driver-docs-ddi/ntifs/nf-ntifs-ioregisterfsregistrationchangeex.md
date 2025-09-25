# IoRegisterFsRegistrationChangeEx function

## Description

The **IoRegisterFsRegistrationChangeEx** routine registers a file system filter driver's notification routine to be called whenever a file system registers or unregisters itself as an active file system.

## Parameters

### `DriverObject` [in]

Pointer to the driver object for the file system filter driver.

### `DriverNotificationRoutine` [in]

A pointer to the [PDRIVER_FS_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-driver_fs_notification) routine, which the file system calls when it registers or unregisters itself.

## Return value

**IoRegisterFsRegistrationChangeEx** returns one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The notification routine was successfully registered. |
| **STATUS_INSUFFICIENT_RESOURCES** | A notification packet could not be allocated for the notification routine. |

## Remarks

The effect of **IoRegisterFsRegistrationChangeEx** is identical to that of [IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange) on Windows XP and later.

**IoRegisterFsRegistrationChangeEx** registers a file system filter driver to be notified whenever a file system calls [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) or [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).

To stop receiving such notifications, the filter driver should call [IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange).

When a file system filter driver calls **IoRegisterFsRegistrationChangeEx**, its notification routine is also called immediately for all currently registered file systems (that is, file systems that have already called [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) but have not yet called [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)).

Because the caller's notification routine can be called even before **IoRegisterFsRegistrationChangeEx** returns, a filter driver should not call this routine until after it has created any data structures that it needs to process these notifications.

**IoRegisterFsRegistrationChangeEx** ignores RAW devices. For information about attaching to the RAW file system by name, see [Attaching the Filter Device Object to the Target Device Object](https://learn.microsoft.com/windows-hardware/drivers/ifs/attaching-the-filter-device-object-to-the-target-device-object).

**IoRegisterFsRegistrationChangeEx** increments the reference count on the filter driver's driver object.

If a file system filter driver calls **IoRegisterFsRegistrationChangeEx** twice in succession (without calling [IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange) in between), passing the same values for the *DriverObject* and *DriverNotificationRoutine* parameters that it registered in the previous call to **IoRegisterFsRegistrationChangeEx**, and no other filter drivers have registered since the first call, **IoRegisterFsRegistrationChangeEx** returns STATUS_DEVICE_ALREADY_ATTACHED.

## See also

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)