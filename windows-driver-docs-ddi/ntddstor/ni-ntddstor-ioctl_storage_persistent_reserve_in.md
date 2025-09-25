# IOCTL_STORAGE_PERSISTENT_RESERVE_IN IOCTL

## Description

The generic storage class driver (*classpnp.sys*) exposes an I/O control (IOCTL) interface for issuing Persistent Reserve In commands. The behavior of the storage device when a Persistent Reserve In command is received is described in the SCSI Primary Commands - 2 (SPC-2) specification. The IOCTL interface requires the caller to have read access to the physical device for Persistent Reserve In commands. User-mode applications, services, and kernel-mode drivers can use this IOCTL to control persistent reservations. If called from a driver, this IOCTL must be called from a thread running at IRQL < DISPATCH_LEVEL. This IOCTL is defined with FILE_READ_ACCESS, requiring a device handle to have read permissions to issue the Persistent Reserve In command.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) structure. You must allocate the buffer from nonpaged pool and must align it correctly for the target device and adapter.

PR_IN.ServiceAction can be one of the following:

* RESERVATION_ACTION_READ_KEYS
* RESERVATION_ACTION_READ_RESERVATIONS

PR_IN.Allocation length is the size (in bytes) of the buffer allocated for the returned parameter list.

### Input buffer length

The length of input buffer, in bytes.

### Output buffer

For PR_IN.ServiceAction = RESERVATION_ACTION_READ_KEYS, the output buffer contains a [**PRI_REGISTRATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-pri_registration_list) structure and must be at least sizeof(PRI_REGISTRATION_LIST).

For PR_IN.ServiceAction = RESERVATION_ACTION_READ_RESERVATIONS, the output buffer contains a [**PRI_RESERVATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/ns-minitape-pri_reservation_list) structure and must be at least sizeof(PRI_RESERVATION_LIST).

If the allocated buffer is too small to return all the Persistent Reserve In data, success will be returned and the required size will be returned in the parameter list **AdditionalLength** field.

### Output buffer length

The length of the output buffer, in bytes.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the size of the output buffer. For ServiceAction = RESERVATION_ACTION_READ_KEYS, the output buffer is a [**PRI_REGISTRATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-pri_registration_list) structure. For ServiceAction = RESERVATION_ACTION_READ_RESERVATIONS, the output buffer is a [**PRI_REGISTRATION_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-pri_registration_list) structure.

The **Status** field is set to one of the following:

| Value | Meaning |
| ----- | ------- |
| STATUS_BUFFER_OVERFLOW (ERROR_MORE_DATA) | The output buffer is too small to hold the Persistent Reserve In data. The output buffer's **AdditionalLength** field will contain the size of the data to be returned. |
| STATUS_DEVICE_BUSY (ERROR_BUSY) | The command failed because of a Reservation Conflict (for more information, see the SCSI Primary Commands - 2 (SPC-2)** specification). |
| STATUS_INFO_LENGTH_MISMATCH | The input buffer length for the IOCTL is less than sizeof(PERSISTENT_RESERVE_COMMAND) or the size that is specified in the [**PERSISTENT_RESERVE_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_persistent_reserve_command) data structure is less than sizeof(PERSISTENT_RESERVE_COMMAND). |
| STATUS_INVALID_DEVICE_REQUEST (ERROR_INVALID_FUNCTION) | The I/O control code (IOCTL_STORAGE_PERSISTENT_RESERVE_IN) is not supported by the storage drivers. |
| STATUS_INVALID_PARAMETER (ERROR_INVALID_PARAMETER) | The input buffer structure is incorrectly sized or populated. |
| STATUS_INVALID_USER_BUFFER (ERROR_INVALID_USER_BUFFER) | The input or output buffer is not aligned correctly for the device or adapter. This status could only be returned when a driver sends an IOCTL to the storage stack. This status will not be returned when a user-mode application sends the IOCTL through the DeviceIoControl API as the I/O Manager automatically aligns the buffers. |
| STATUS_IO_DEVICE_ERROR (ERROR_IO_DEVICE) | The device does not support the Persistent Reserve In command. |
| STATUS_SUCCESS | The operation was successful. |