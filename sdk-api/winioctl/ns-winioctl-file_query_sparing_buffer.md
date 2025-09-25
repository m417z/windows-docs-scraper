# FILE_QUERY_SPARING_BUFFER structure

## Description

Contains defect management properties.

## Members

### `SparingUnitBytes`

The size of a sparing packet and the underlying error check and correction (ECC) block size of the volume.

### `SoftwareSparing`

If **TRUE**, indicates that sparing behavior is software-based; if **FALSE**, it is hardware-based.

### `TotalSpareBlocks`

The total number of blocks allocated for sparing.

### `FreeSpareBlocks`

The number of blocks available for sparing.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_QUERY_SPARING_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_query_sparing_info)