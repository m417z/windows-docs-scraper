# IOCTL_CDROM_READ_TOC_EX IOCTL

## Description

Queries the target device for the table of contents (TOC), the program memory area (PMA), and the absolute time in pregroove (ATIP). If the media is not a CD-ROM and does not support a TOC, this IOCTL returns information similar to that of a CD-ROM TOC. This is required for compatibility with some legacy initiator environments.

## Parameters

### Major code

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** points to a buffer of type [CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex) whose contents indicate what information should be retrieved from the target device.

**Parameters.Read.Length** in the I/O stack location indicates the size, in bytes, of the information to be retrieved from the target device.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location indicates the size, in bytes, of the input buffer, which must be >= **sizeof**(CDROM_READ_TOC_EX).

### Output buffer

The driver returns the query data in the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location indicates the size, in bytes, of the output buffer, which must be >= MINIMUM_CDROM_READ_TOC_EX_SIZE.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_BUFFER_TOO_SMALL or STATUS_INSUFFICIENT_RESOURCES.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)