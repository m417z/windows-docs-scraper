# DEPENDENT_DISK_FLAG enumeration

## Description

Contains virtual hard disk (VHD) dependency information flags.

## Constants

### `DEPENDENT_DISK_FLAG_NONE:0x00000000`

 No flags specified. Use system defaults.

### `DEPENDENT_DISK_FLAG_MULT_BACKING_FILES:0x00000001`

Multiple files backing the virtual disk.

### `DEPENDENT_DISK_FLAG_FULLY_ALLOCATED:0x00000002`

Fully allocated virtual disk.

### `DEPENDENT_DISK_FLAG_READ_ONLY:0x00000004`

Read-only virtual disk.

### `DEPENDENT_DISK_FLAG_REMOTE:0x00000008`

 The backing file of the virtual disk is not on a local physical disk.

### `DEPENDENT_DISK_FLAG_SYSTEM_VOLUME:0x00000010`

 Reserved.

### `DEPENDENT_DISK_FLAG_SYSTEM_VOLUME_PARENT:0x00000020`

The backing file of the virtual disk is on the system volume.

### `DEPENDENT_DISK_FLAG_REMOVABLE:0x00000040`

The backing file of the virtual disk is on a removable physical disk.

### `DEPENDENT_DISK_FLAG_NO_DRIVE_LETTER:0x00000080`

Drive letters are not automatically assigned to the volumes on the virtual disk.

### `DEPENDENT_DISK_FLAG_PARENT:0x00000100`

The virtual disk is a parent of a differencing chain.

### `DEPENDENT_DISK_FLAG_NO_HOST_DISK:0x00000200`

 The virtual disk is not attached to the local host.
For example, it is attached to a guest virtual machine.

### `DEPENDENT_DISK_FLAG_PERMANENT_LIFETIME:0x00000400`

The lifetime of the virtual disk is not tied to any application or process.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))

[Virtual Storage](https://learn.microsoft.com/windows/desktop/VStor/virtual-storage)