# IOCTL_VOLUME_READ_PLEX IOCTL

## Description

Performs a read on a specific [plex](https://learn.microsoft.com/windows-hardware/drivers/) of a volume. Because all plexes are identical, the volume manager can retrieve data from any of a volume's plexes during a normal read operation. The volume manager spreads reads among a volume's plexes, to balance the I/O load on the physical media and to maximize read performance.

If, however, an application or kernel-mode component must read data from a particular plex instead of letting the volume manager pick one, it can use this IOCTL to do so.

## Parameters

### Major code

### Input buffer

Caller inserts the [VOLUME_READ_PLEX_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_read_plex_input) structure, containing the logical offset, at the beginning of the buffer at **Irp->AssociatedIrp.SystemBuffer**.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** in the I/O stack location of the IRP indicates the size, in bytes, of the input buffer, which must be greater than or equal to the value of **sizeof**(VOLUME_READ_PLEX_INPUT).

### Output buffer

Like [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read), this IOCTL stores the read data in the memory buffer passed as a memory descriptor list (MDL) in the **Irp->MdlAddress** field.

### Output buffer length

The length of the buffer.

### Input/output buffer

### Input/output buffer length

### Status block

If the operation is successful, the volume manager sets the **Status** field to STATUS_SUCCESS.

The VOLUME_READ_PLEX_INPUT structure at **Irp->AssociatedIrp.SystemBuffer** has a **Length** member that must be aligned on a 512-byte boundary. If **Length** does not have the proper alignment, the operation fails and the volume manager sets the **Status** field to VKE_EINVAL.

## See also

[VOLUME_READ_PLEX_INPUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_read_plex_input)