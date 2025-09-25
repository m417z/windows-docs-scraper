# REASSIGN_BLOCKS structure

## Description

Contains
disk block reassignment data. This is a variable length structure where the last member is an array of block
numbers to be reassigned. It is used by the
[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks) control code.

## Members

### `Reserved`

This member is reserved. Do not use it. Set it to zero.

### `Count`

The number of blocks to be reassigned.

This is the number of elements that are in the
**BlockNumber** member array.

### `BlockNumber`

An array of **Count** block numbers, one for each block to be reassigned.

## Remarks

The **REASSIGN_BLOCKS** structure only supports
drives where the Logical Block Address (LBA) is a 4-byte value (typically up to 2 TB).

For larger drives the
[REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-reassign_blocks_ex) structure that is used with the
[IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex) control code
supports 8-byte LBAs.

For device compatibility, the
[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks) control code and
**REASSIGN_BLOCKS** structure should be used where
possible.

## See also

[IOCTL_DISK_REASSIGN_BLOCKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks)

[IOCTL_DISK_REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_reassign_blocks_ex)

[REASSIGN_BLOCKS_EX](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-reassign_blocks_ex)