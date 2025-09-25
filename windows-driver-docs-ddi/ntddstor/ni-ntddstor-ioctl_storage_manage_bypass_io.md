## Description

The **IOCTL_STORAGE_MANAGE_BYPASS_IO** control code controls BypassIO operations on a given file in all layers of the volume and storage stacks.

## Parameters

### Major code

### Input buffer

The buffer at **Irp->AssociatedIrp.SystemBuffer** contains a [**BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_input) structure with information related to a BypassIO request.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the buffer, which must be at least ```sizeof(BPIO_INPUT)```.

### Output buffer

The driver returns information in a [**BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_output) structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size of the output buffer, in bytes. **OutputBufferLength** must be at least ```sizeof(BPIO_OUTPUT)```.

### Input/output buffer

n/a

### Input/output buffer length

n/a

### Status block

The **Status** field can be set to STATUS_SUCCESS, or an error status such as STATUS_INVALID_PARAMETER, STATUS_INFO_LENGTH_MISMATCH, STATUS_BUFFER_TOO_SMALL, or STATUS_NOT_SUPPORTED.

## Remarks

Only file systems send **IOCTL_STORAGE_MANAGE_BYPASS_IO**. A file system sends this IOCTL as appropriate in response to a [**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io) control code.

See [BypassIO for storage drivers](https://learn.microsoft.com/windows-hardware/drivers/storage/bypassio) for more information.

## See also

[**BPIO_INPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_input)

[**BPIO_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-bpio_output)

[**FSCTL_MANAGE_BYPASS_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_manage_bypass_io)