# DRIVER_FS_NOTIFICATION callback function

## Description

A PDRIVER_FS_NOTIFICATION-typed routine is called by the operating system when a file system registers or unregisters itself by using [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem) or [IoUnregisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfilesystem).

## Parameters

### `DeviceObject` [in]

A pointer to a file system device object for which the notification was called.

### `FsActive` [in]

A Boolean value that indicates whether the file system has registered (TRUE) or unregistered (FALSE) itself as an active file system.

## Remarks

You must declare the callback function by using the *DRIVER_FS_NOTIFICATION* type. For more information, see the following Example section.

#### Examples

To define a **DriverFSNotificationRoutine** callback routine that is named **MyDriverNotification**, you must first provide a function declaration that the Static Driver Verify (SDV) and other verification tools require, as follows:

```
DRIVER_FS_NOTIFICATION MyDriverFSNotification;
```

And then implement your callback routine as follows:

```
VOID
MyDriverFSNotification (
    __in struct _DEVICE_OBJECT *DeviceObject,
    __in BOOLEAN FsActive
)
{ . . . }
```

Note that the callback type is declared in *Ntifs.h* as follows:

```
typedef
VOID
DRIVER_FS_NOTIFICATION (
  __in struct _DEVICE_OBJECT *DeviceObject,
  __in BOOLEAN FsActive
  );
typedef DRIVER_FS_NOTIFICATION *PDRIVER_FS_NOTIFICATION;
```

## See also

[IoRegisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchange)

[IoRegisterFsRegistrationChangeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangeex)

[IoRegisterFsRegistrationChangeMountAware](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfsregistrationchangemountaware)

[IoUnregisterFsRegistrationChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iounregisterfsregistrationchange)