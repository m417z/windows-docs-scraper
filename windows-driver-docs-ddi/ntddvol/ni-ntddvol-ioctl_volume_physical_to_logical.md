# IOCTL_VOLUME_PHYSICAL_TO_LOGICAL IOCTL

## Description

Returns the logical offset corresponding to a physical disk number and a physical offset.

The volume manager supports this IOCTL as described for all types of basic and dynamic volumes.

## Parameters

### Major code

### Input buffer

Caller inserts the [VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset) structure, containing the physical offset and physical disk number, at the beginning of the buffer, at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to the value of **sizeof**(VOLUME_PHYSICAL_OFFSET).

### Output buffer

The volume manager returns the logical offset in the [VOLUME_LOGICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_logical_offset) structure at the beginning of the buffer, at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer, which must be greater than or equal to the value of **sizeof**(VOLUME_LOGICAL_OFFSET).

### Input/output buffer

### Input/output buffer length

### Status block

If the operation is successful, the **Status** member is set to STATUS_SUCCESS.

If either the input or output buffer is too small, the volume manager sets the **Status** member to STATUS_BUFFER_TOO_SMALL. If data is returned in the output buffer but the buffer is too small to receive all of it, the volume manager sets the **Status** member to STATUS_BUFFER_OVERFLOW. The **Information** member is set to the size of the output buffer provided by the caller.

If the given physical disk number and physical offset do not belong to the volume or if they are taken from RAID parity data, this call will fail with STATUS_INVALID_PARAMETER.

## See also

[IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical)

[VOLUME_LOGICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_logical_offset)

[VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset)

[VOLUME_PHYSICAL_OFFSETS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offsets)