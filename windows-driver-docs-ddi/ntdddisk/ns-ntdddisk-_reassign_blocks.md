# _REASSIGN_BLOCKS structure

## Description

The **REASSIGN_BLOCKS** structure is used in conjunction with the [IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_reassign_blocks) request to instruct a disk device to reassign the block numbers of the indicated bad blocks to good blocks.

## Members

### `Reserved`

Reserved for system use.

### `Count`

Contains the number of blocks in the array pointed to by **BlockNumber** to reassign.

### `BlockNumber`

Contains an array of block numbers corresponding to damaged blocks. These numbers will be reassigned to good blocks taken from the device's spare block pool.

## See also

[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_reassign_blocks)