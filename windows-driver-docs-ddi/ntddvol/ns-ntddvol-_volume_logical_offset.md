# _VOLUME_LOGICAL_OFFSET structure

## Description

The VOLUME_LOGICAL_OFFSET structure contains a logical offset into a volume.

## Members

### `LogicalOffset`

Contains a logical offset in bytes into a volume.

## Remarks

The VOLUME_LOGICAL_OFFSET structure is used with [IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical) and [IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical) to request a logical offset equivalent of a physical offset or a physical offset equivalent of a logical offset, respectively.

## See also

[IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical)

[IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical)