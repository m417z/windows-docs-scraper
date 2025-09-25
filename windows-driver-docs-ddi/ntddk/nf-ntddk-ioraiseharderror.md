## Description

The **IoRaiseHardError** routine causes a dialog box to appears that warns the user that a device I/O error has occurred, which might indicate that a physical device is failing.

## Parameters

### `Irp` [in]

Pointer to the IRP that failed because of a device I/O error.

### `Vpb` [in, optional]

Pointer to the volume parameter block (VPB), if any, for the mounted file object. This parameter is **NULL** if no VPB is associated with the device object.

### `RealDeviceObject` [in]

Pointer to the device object that represents the physical device on which the I/O operation failed.

## Remarks

Highest-level drivers, particularly file system drivers, call **IoRaiseHardError**.

> [!WARNING]
> Because **IoRaiseHardError** uses a normal kernel APC to create a user dialog box, a deadlock can occur if normal kernel APCs are disabled when a device error occurs. For example:
>
> 1. An upper-level filter driver calls [KeEnterCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) (which disables normal kernel APCs) and sends an I/O request to a file system driver. The filter driver waits on the completion of the request by the file system driver before the filter driver calls [KeLeaveCriticalRegion](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion) (which reenables normal kernel APCs).
>
> 1. An error occurs on the file system, and the file system driver calls **IoRaiseHardError** to report the error to the user. The file system driver waits on the dialog box.
>
> 1. Deadlock now exists: The normal kernel APC created by **IoRaiseHardError** to create the dialog box waits for normal kernel APCs to be enabled. The file system waits on the dialog box before it completes the I/O request. The filter driver waits on completion of the I/O request before it calls **KeLeaveCriticalRegion** (which reenables normal kernel APCs).

The behavior of this routine is dependent of the current state of hard errors for the running thread. If hard errors have been disabled by calling [IoSetThreadHardErrorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetthreadharderrormode), this routine completes the IRP specified by *Irp* without transferring any data into user buffers. In addition, no message is sent to notify the user of this failure.

## See also

[IoGetRelatedDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetrelateddeviceobject)

[IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice)

[IoSetThreadHardErrorMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetthreadharderrormode)