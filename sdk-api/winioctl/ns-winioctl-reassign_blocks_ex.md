# REASSIGN_BLOCKS_EX structure

## Description

Contains
disk block reassignment data. This is a variable length structure where the last member is an array of block
numbers to be reassigned. It is used by the
[IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex) control
code.

## Members

### `Reserved`

This member is reserved. Do not use it. Set it to 0 (zero).

### `Count`

The number of blocks to be reassigned.

This is the number of elements that are in the
**BlockNumber** member array.

### `BlockNumber`

An array of **Count** block numbers, one for each block to be reassigned.

## Remarks

The **REASSIGN_BLOCKS_EX** structure supports drives
that have an 8-byte Logical Block Address (LBA), which is typically required for storage devices larger than 2 TB.
The [REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-reassign_blocks) structure used with the
[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks) control code
supports devices with up to a 4-byte LBA should be used where possible.

## See also

[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks)

[IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex)

[REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-reassign_blocks)