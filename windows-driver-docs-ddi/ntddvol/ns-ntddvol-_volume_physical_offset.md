# _VOLUME_PHYSICAL_OFFSET structure

## Description

The VOLUME_PHYSICAL_OFFSET structure contains a physical offset into a volume and its accompanying physical disk number and is used with [IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical) and [IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical) to request a logical offset equivalent of a physical offset or a physical offset equivalent of a logical offset, respectively.

## Members

### `DiskNumber`

Contains the number of the physical disk.

### `Offset`

Contains the physical offset in bytes of the data on the disk.

## See also

[IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical)

[IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical)