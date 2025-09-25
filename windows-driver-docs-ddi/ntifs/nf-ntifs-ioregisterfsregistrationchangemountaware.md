# IoRegisterFsRegistrationChangeMountAware function

## Description

The **IoRegisterFsRegistrationChangeMountAware** routine registers a file system filter driver's notification routine. This notification routine is called whenever a file system registers or unregisters itself as an active file system.

## Parameters

### `DriverObject` [in]

A pointer to the driver object for the file system filter driver.

### `DriverNotificationRoutine` [in]

A pointer to the [PDRIVER_FS_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-driver_fs_notification) routine, which the file system calls when it registers or unregisters itself.

### `SynchronizeWithMounts` [in]

If set to **TRUE**, this routine ensures no mount operations are in progress when making notification callbacks. If set to **FALSE**, the routine does not attempt to avoid conflicts with mount operations.

## Return value

Returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The notification routine was successfully registered. |
| **STATUS_INSUFFICIENT_RESOURCES** | A notification packet could not be allocated for the notification routine. |
| **STATUS_DEVICE_ALREADY_ATTACHED** | This driver object has already been registered with this notification. |

## Remarks

**IoRegisterFsRegistrationChangeMountAware** registers a file system filter driver to be notified whenever a file system calls [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) or [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).

To stop receiving such notifications, the filter driver should call [IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange).

When *SynchronizeWithMounts* is specified as **TRUE**, **IoRegisterFsRegistrationChangeMountAware** waits for any current mount operations to complete and does not allow new mount operations to begin until **IoRegisterFsRegistrationChangeMountAware** is finished.

**Note** When a file system filter driver calls **IoRegisterFsRegistrationChangeMountAware**, its notification routine is also called immediately for all file systems that are currently registered, That is, file systems that have already called [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem), but have not yet called [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).

Because the caller's notification routine can be called even before **IoRegisterFsRegistrationChangeMountAware** returns, a filter driver should not call this routine until after it has created data structures it needs to process these notifications.

Additionally, **IoRegisterFsRegistrationChangeMountAware** ignores RAW devices. For information about how to attach to the RAW file system by name, see [Attaching the Filter Device Object to the Target Device Object](https://learn.microsoft.com/windows-hardware/drivers/ifs/attaching-the-filter-device-object-to-the-target-device-object).

**IoRegisterFsRegistrationChangeMountAware** increments the reference count on the filter driver's driver object.

## See also

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoRegisterFsRegistrationChangeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangeex)

[IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)