# IOCTL_CDROM_EXCLUSIVE_ACCESS IOCTL

## Description

The IOCTL_CDROM_EXCLUSIVE_ACCESS request instructs the CD-ROM class driver to:

* Report the access state of a CD-ROM device.
* Lock a CD-ROM device for exclusive access.
* Unlock a CD-ROM device for exclusive access.

A valid FileObject handle must exist in order for this IOCTL to succeed. The FileObject handle protects the system from unexpected application termination or accidental acquisition of an exclusive access lock without subsequent release of the exclusive access lock. A valid FileObject handle is necessary because when an application closes, the CD-ROM class driver will receive CLEANUP and CLOSE I/O Request Packets (IRPs), which it can use to automatically release an exclusive access lock obtained by that handle. This simple method protects against the majority of accidental releases of exclusive access. Any methods used to avoid this functionality may reduce the safety and effectiveness of the exclusive access locking method.

## Parameters

### Major code

### Input buffer

Depending on the operation that the caller requests, the caller must provide one of the following structures as input at **Irp->AssociatedIrp.SystemBuffer**:

* [CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access) (to report the access state of a CD-ROM device)
* [CDROM_EXCLUSIVE_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_lock) (to lock a CD-ROM device for exclusive access)
* [CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access) (to unlock a CD-ROM device that the application locked for exclusive access)

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member in the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure indicates the size, in bytes, of the user-allocated input buffer.

### Output buffer

If the caller requests the exclusive access state of the CD-ROM device (**RequestType** = **ExclusiveAccessQueryState**), the CD-ROM class driver returns a [CDROM_EXCLUSIVE_LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_lock_state)-type structure in the buffer at **Irp->AssociatedIrp.SystemBuffer** whose **LockState** member indicates the access state of the device.

### Output buffer length

The **Parameters.DeviceIoControl.OutputBufferLength** member in the I/O stack location (IO_STACK_LOCATION) indicates the size, in bytes, of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes that are returned. The **Status** field is set to STATUS_SUCCESS if the request succeeds.

If the request fails, the **Status** field might be set to one of the following error messages:

**STATUS_ACCESS_DENIED (Windows error code: ERROR_ACCESS_DENIED)**

The device is already locked for exclusive access.

**STATUS_BUFFER_TOO_SMALL (Windows error code: ERROR_INSUFFICIENT_BUFFER)**

The output buffer was too small for a **ExclusiveAccessQueryState** request.

**STATUS_INFO_LENGTH_MISMATCH (Windows error code: ERROR_BAD_LENGTH)**

The input buffer was too small.

**STATUS_INVALID_DEVICE_REQUEST (Windows error code: ERROR_INVALID_FUNCTION)**

The CD-ROM class driver returns this status code when one of the following two errors occurs:

* The caller made the request at an IRQL level other than PASSIVE_LEVEL.
* The caller sent a request with **RequestType** = **ExclusiveAccessUnlockDevice** to unlock a device that is not in exclusive mode.

**STATUS_INVALID_DEVICE_STATE (Windows error code: ERROR_BAD_COMMAND)**

The caller attempted to lock a device while the file system driver was mounted on this device, without specifying that the class driver should suspend the check for a mounted file system driver. To suspend the check for a mounted file system driver, the caller must set the **Flags** member of [CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access) to 1.

**STATUS_INVALID_HANDLE (Windows error code: ERROR_INVALID_HANDLE)**

The CD-ROM class driver returns this status code when one of the following two errors occurs:

* The file object that is required to keep track of the request was not available. The CD-ROM class driver did not receive a request to create a file object from this caller.
* The caller sent a request with **RequestType** = **ExclusiveAccessUnlockDevice** to unlock a device, even though the caller does not have exclusive access to the device.

**STATUS_INVALID_PARAMETER (Windows error code: ERROR_INVALID_PARAMETER)**

The CD-ROM class driver returns this status code when one of the following two errors occurs:

* The **RequestType** that was specified is not a valid member of [EXCLUSIVE_ACCESS_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_exclusive_access_request_type).
* The caller name string in the **CallerName** member of [CDROM_EXCLUSIVE_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_lock) violates the naming convention. **CallerName** must be a **NULL**-terminated string that contains the following characters: alphanumerics (A - Z, a - z, 0 - 9), spaces, periods, commas, colons (:), semi-colons (;), hyphens (-), and underscores (_). The length of the string must be less than CDROM_EXCLUSIVE_CALLER_LENGTH bytes, including the **NULL** at the end of the string.

## See also

[CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_access)

[CDROM_EXCLUSIVE_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_lock)

[CDROM_EXCLUSIVE_LOCK_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exclusive_lock_state)

[EXCLUSIVE_ACCESS_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_exclusive_access_request_type)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)