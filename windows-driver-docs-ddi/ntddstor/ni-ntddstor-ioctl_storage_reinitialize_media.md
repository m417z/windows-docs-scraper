# IOCTL_STORAGE_REINITIALIZE_MEDIA IOCTL

## Description

A driver can issue a **IOCTL_STORAGE_REINITIALIZE_MEDIA** control code to offload the erasure process to the storage device.

## Parameters

### Major code

### Input buffer

For Windows Server 2022 and later, contains an optional [**STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_reinitialize_media) structure with sanitize options, or NULL. For earlier OS versions, the input buffer is NULL.

### Input buffer length

For Windows 10 release 21H1 and later, **Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= sizeof(STORAGE_REINITIALIZE_MEDIA) if **Parameters.DeviceIoControl.InputBuffer** != NULL; otherwise zero. For earlier OS versions, the input buffer length is zero.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

The **Information** field is set to zero if the call completes successfully; otherwise, it is set to a non-zero value.

## Remarks

 **IOCTL_STORAGE_REINITIALIZE_MEDIA** offloads the erasure to the storage device. There is no guarantee as to the successful deletion or recoverability of the data of the storage device after the command completes.

This IOCTL is limited to data disks on devices in the desktop device family. In Windows Preinstallation Environment (WinPE), this IOCTL is supported for both boot and data disks.

In earlier OS versions, the implementation requires no input and returns no output other than status.

Callers should first call [FSCTL_LOCK_VOLUME](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-fsctl_lock_volume) before calling this IOCTL to flush out cached data in upper layers. No waiting of outstanding request completion is done before issuing the command to the device.

## See also

[IO_STATUS_BLOCK structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_reinitialize_media)

[How to Complete an IRP in a Dispatch Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/how-to-complete-an-irp-in-a-dispatch-routine)