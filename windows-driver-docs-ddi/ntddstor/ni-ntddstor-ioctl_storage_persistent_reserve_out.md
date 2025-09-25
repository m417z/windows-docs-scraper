# IOCTL_STORAGE_PERSISTENT_RESERVE_OUT IOCTL

## Description

The generic storage class driver (*classpnp.sys*) exposes an I/O control (IOCTL) interface for issuing Persistent Reserve Out commands. The behavior of the storage device when a Persistent Reserve Out command is received is described in the SCSI Primary Commands - 2 (SPC-2) specification. The IOCTL interface requires the caller to have read/write access to the physical device for Persistent Reserve Out commands. User-mode applications, services, and kernel-mode drivers can use this IOCTL to control persistent reservations. If called from a driver, this IOCTL must be called from a thread running at IRQL < DISPATCH_LEVEL. This IOCTL is defined with FILE_READ_ACCESS and FILE_WRITE_ACCESS, requiring a device handle to have both read and write permissions to issue the Persistent Reserve Out command.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) structure. You must allocate the buffer from nonpaged pool and must align it correctly for the target device and adapter.

PR_OUT.ServiceAction can be one of the following:

* RESERVATION_ACTION_REGISTER
* RESERVATION_ACTION_RESERVE
* RESERVATION_ACTION_RELEASE
* RESERVATION_ACTION_CLEAR
* RESERVATION_ACTION_PREEMPT
* RESERVATION_ACTION_PREEMPT_ABORT
* RESERVATION_ACTION_REGISTER_IGNORE_EXISTING

PR_OUT.Scope can be one of the following:

* RESERVATION_SCOPE_LU
* RESERVATION_SCOPE_ELEMENT

PR_OUT.Type can be one of the following:

* RESERVATION_TYPE_WRITE_EXCLUSIVE
* RESERVATION_TYPE_EXCLUSIVE
* RESERVATION_TYPE_WRITE_EXCLUSIVE_REGISTRANTS
* RESERVATION_TYPE_EXCLUSIVE_REGISTRANTS

PR_OUT.ParameterList is used to hold the [**PRO_PARAMETER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-pro_parameter_list) structure. This structure is required and must be contiguous with the rest of the [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) structure.

### Input buffer length

The length of a [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to zero.

The **Status** field is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| STATUS_DEVICE_BUSY (ERROR_BUSY) | The command failed because of a Reservation Conflict (for more information, see the SCSI Primary Commands - 2 (SPC-2) specification). |
| STATUS_INFO_LENGTH_MISMATCH | The input buffer length for the IOCTL is less than sizeof(PERSISTENT_RESERVE_COMMAND) or the size that is specified in the [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) data structure is less than sizeof(PERSISTENT_RESERVE_COMMAND). |
| STATUS_INVALID_DEVICE_REQUEST (ERROR_INVALID_FUNCTION) | The I/O control code (IOCTL_STORAGE_PERSISTENT_RESERVE_OUT) is not supported by the storage drivers. |
| STATUS_INVALID_PARAMETER (ERROR_INVALID_PARAMETER) | The input buffer structure is incorrectly sized or populated. |
| STATUS_INVALID_USER_BUFFER (ERROR_INVALID_USER_BUFFER) | The input buffer is not aligned correctly for the device or adapter. This status can only be returned when a driver sends an IOCTL to the storage stack. This status isn't returned when a user-mode application sends the IOCTL through the **DeviceIoControl** API as the I/O Manager automatically aligns the buffers. |
| STATUS_IO_DEVICE_ERROR (ERROR_IO_DEVICE) | The device does not support the Persistent Reserve Out command. |
| STATUS_SUCCESS | The operation was successful. |