# IOCTL_CDROM_RAW_READ IOCTL

## Description

Reads data from the CD-ROM in raw mode.

## Parameters

### Major code

### Input buffer

If the IOCTL is from user mode, **Irp->AssociatedIrp.SystemBuffer** contains a [RAW_READ_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-__raw_read_info) structure that specifies the starting disk offset, the sector count, and the track mode (XA or CDDA) for the read. **Parameters.DeviceIoControl.InputBufferLength** specifies the size, in bytes, of the structure, which must be >= **sizeof**(RAW_READ_INFO). **Parameters.DeviceIoControl.OutputBufferLength** specifies the size of the buffer to be read, which must be >= **sizeof**(*SectorCount* * RAW_SECTOR_SIZE).

If the IOCTL is from kernel mode, **Parameters.DeviceIoControl.Type3InputBuffer** contains a structure that specifies the starting disk offset, the sector count, and the track mode (XA or CDDA) for the read. **Parameters.DeviceIoControl.OutputBufferLength** specifies the size of the buffer, in bytes, to be read, which must be >= **sizeof**(*SectorCount* * RAW_SECTOR_SIZE).

### Input buffer length

See above.

### Output buffer

The driver writes the requested bytes directly (using DMA or PIO) to the buffer described by the MDL at **Irp->MdlAddress**.

### Output buffer length

Length of an MDL.

### Input/output buffer

### Input/output buffer length

### Status block

If the read is successful, the driver sets **Status** to STATUS_SUCCESS and **Information** to the number of bytes transferred. If the read is not successful, the driver sets **Information** to zero and **Status** to possibly STATUS_INVALID_PARAMETER, STATUS_INSUFFICIENT_RESOURCES, or STATUS_INVALID_DEVICE_REQUEST.

## See also

[RAW_READ_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-__raw_read_info)