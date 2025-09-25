# IoRegisterFsRegistrationChange function

## Description

The **IoRegisterFsRegistrationChange** routine registers a file system filter driver's notification routine to be called whenever a file system registers or unregisters itself as an active file system.

## Parameters

### `DriverObject` [in]

Pointer to the driver object for the FS filter driver.

### `DriverNotificationRoutine` [in]

A pointer to the [**PDRIVER_FS_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-driver_fs_notification) routine, which the file system calls when it registers or unregisters itself.

## Return value

**IoRegisterFsRegistrationChange** returns an NTSTATUS value such as one of the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The notification routine was successfully registered. |
| STATUS_INSUFFICIENT_RESOURCES | A notification packet couldn't be allocated for the notification routine. |
| STATUS_DEVICE_ALREADY_ATTACHED | See Remarks. |
| STATUS_NOT_SUPPORTED | Legacy FS filter drivers are blocked by system policy. See [Blocking legacy file system filter drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/blocking-file-system-filter-drivers) for more information. |

## Remarks

**IoRegisterFsRegistrationChange** registers a FS filter driver to be notified whenever a file system calls [**IoRegisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) or [**IoUnregisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).

To stop receiving such notifications, the filter driver should call [**IoUnregisterFsRegistrationChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange).

When a FS filter driver calls **IoRegisterFsRegistrationChange**, the OS calls its notification routine immediately for all currently registered file systems. (A registered file system is one that has already successfully called [**IoRegisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) but has not yet called [**IoUnregisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).) Because the caller's notification routine can be called even before **IoRegisterFsRegistrationChange** returns, a filter driver shouldn't call this routine until after it has created any data structures that it needs in order to process these notifications.

**IoRegisterFsRegistrationChange** ignores RAW devices. For information about attaching to the RAW file system by name, see [Attaching the Filter Device Object to the Target Device Object](https://learn.microsoft.com/windows-hardware/drivers/ifs/attaching-the-filter-device-object-to-the-target-device-object).

**IoRegisterFsRegistrationChange** increments the reference count on the filter driver's driver object.

**IoRegisterFsRegistrationChange** returns STATUS_DEVICE_ALREADY_ATTACHED if the following conditions are true:

* A FS filter driver has called **IoRegisterFsRegistrationChange** twice in succession without calling [**IoUnregisterFsRegistrationChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange) in between.
* That FS filter driver has passed the same values for the **DriverObject** and **DriverNotificationRoutine** that it registered in the previous call to **IoRegisterFsRegistrationChange**.
* No other filter drivers have registered since the first call.

## See also

[**IoRegisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[**IoRegisterFsRegistrationChangeEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangeex)

[**IoUnregisterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)

[**IoUnregisterFsRegistrationChange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)