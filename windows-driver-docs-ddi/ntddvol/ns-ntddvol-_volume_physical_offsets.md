# _VOLUME_PHYSICAL_OFFSETS structure

## Description

The VOLUME_PHYSICAL_OFFSETS structure contains an array of physical offsets and accompanying physical disk numbers and is used with [IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical) to request a series of pairs of physical offsets and disk numbers that correspond to a single logical offset.

## Members

### `NumberOfPhysicalOffsets`

Contains the number of physical offsets returned by the call to [IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical).

### `PhysicalOffset`

Contains an array of structures of type [VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset). Each element of the array contains a pair consisting of a physical disk number and an accompanying physical offset .

## See also

[IOCTL_VOLUME_LOGICAL_TO_PHYSICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_logical_to_physical)

[IOCTL_VOLUME_PHYSICAL_TO_LOGICAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ni-ntddvol-ioctl_volume_physical_to_logical)

[VOLUME_PHYSICAL_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvol/ns-ntddvol-_volume_physical_offset)