# _STORAGE_READ_CAPACITY structure

## Description

The **STORAGE_READ_CAPACITY** contains the disk read capacity information returned from a [IOCTL_STORAGE_READ_CAPACITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_read_capacity) request.

## Members

### `Version`

The version of this structure. Set to **sizeof**(STORAGE_READ_CAPACITY).

### `Size`

The size of this structure. Set to **sizeof**(STORAGE_READ_CAPACITY).

### `BlockLength`

The number of bytes per block on disk.

### `NumberOfBlocks`

The total number of blocks on the disk.

### `DiskLength`

The total disk size in bytes.

## See also

[IOCTL_STORAGE_READ_CAPACITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_read_capacity)