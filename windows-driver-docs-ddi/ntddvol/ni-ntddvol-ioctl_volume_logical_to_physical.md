# IOCTL_VOLUME_LOGICAL_TO_PHYSICAL IOCTL

## Description

Returns physical offsets and physical disk numbers for a given volume logical offset.

For example, a logical volume offset inside a mirrored volume with two [plex](https://learn.microsoft.com/windows-hardware/drivers/) corresponds to two physical offsets, one in each of the two disks participating in the mirror. In response to this IOCTL, the volume manager returns two physical offsets and two physical disk numbers for the logical volume offset.

The volume manager supports this IOCTL for all types of basic and dynamic volumes.

## Parameters

### Major code

### Input buffer

Caller inserts the [VOLUME_LOGICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_logical_offset) structure containing the logical offset at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to the value of **sizeof**(VOLUME_LOGICAL_OFFSET).

### Output buffer

The output buffer size must be large enough to hold the structure [VOLUME_PHYSICAL_OFFSETS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offsets), which contains a variable-length array of structures of type [VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset).

The volume manager returns one or more physical offsets and disk numbers in the VOLUME_PHYSICAL_OFFSETS structure at the beginning of the buffer, at **Irp->AssociatedIrp.SystemBuffer**.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

If the operation is successful, the **Status** member is set to STATUS_SUCCESS. Otherwise, the **Status** member is set to the appropriate error code. Possible error codes include the following:

**STATUS_BUFFER_TOO_SMALL**

The output buffer is too small. The volume manager sets the **Irp->IoStatus.Information** member to the size of the output buffer the caller should have provided.

**STATUS_INVALID_PARAMETER**

The input buffer is too small.

## See also

[IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical)

[VOLUME_LOGICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_logical_offset)

[VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset)

[VOLUME_PHYSICAL_OFFSETS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offsets)