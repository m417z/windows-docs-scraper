# IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS IOCTL

## Description

Returns the physical location(s) of a volume on one or more disks. Extents are initially stored in the order in which they are created, but remirroring, splitting, or breaking a mirror, or actions taken during disaster recovery, can affect the order of disk extents.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The driver returns a VOLUME_DISK_EXTENTS structure in the buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be at least **sizeof**(VOLUME_DISK_EXTENTS).

### Output buffer length

The length of a VOLUME_DISK_EXTENTS structure.

### Input/output buffer

### Input/output buffer length

### Status block

The driver sets **Irp->IoStatus.Information** and the **Status** field as follows:

* If the buffer at **Irp->AssociatedIrp.SystemBuffer** is < **sizeof**(VOLUME_DISK_EXTENTS), the driver sets **Irp->IoStatus.Information** to zero and returns STATUS_INVALID_PARAMETER.
* If the buffer at **Irp->AssociatedIrp.SystemBuffer** is at least **sizeof**(VOLUME_DISK_EXTENTS) but too small for all data to be returned, the driver sets **Irp->IoStatus.Information** to **sizeof**(VOLUME_DISK_EXTENTS) and sets **Status** to STATUS_BUFFER_OVERFLOW.
* If the buffer at **Irp->AssociatedIrp.SystemBuffer** is large enough for all data to be returned, the driver sets **Irp->IoStatus.Information** to **sizeof**(VOLUME_DISK_EXTENTS) + ((NumberOfDiskExtents - 1) * **sizeof**(DISK_EXTENT)) and sets **Status** to STATUS_SUCCESS.

## See also

[DISK_EXTENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_disk_extent)

[VOLUME_DISK_EXTENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_disk_extents)