# OPEN_VIRTUAL_DISK_FLAG enumeration

## Description

Contains virtual hard disk (VHD) or CD or DVD image file (ISO) open request flags.

## Constants

### `OPEN_VIRTUAL_DISK_FLAG_NONE:0x00000000`

No flag specified.

### `OPEN_VIRTUAL_DISK_FLAG_NO_PARENTS:0x00000001`

Open the VHD file (backing store) without opening any differencing-chain parents. Used to correct broken
parent links.

This flag is not supported for ISO virtual disks.

### `OPEN_VIRTUAL_DISK_FLAG_BLANK_FILE:0x00000002`

Reserved.

This flag is not supported for ISO virtual disks.

### `OPEN_VIRTUAL_DISK_FLAG_BOOT_DRIVE:0x00000004`

Reserved.

This flag is not supported for ISO virtual disks.

### `OPEN_VIRTUAL_DISK_FLAG_CACHED_IO:0x00000008`

Indicates that the virtual disk should be opened in cached mode. By default the virtual disks are opened
using **FILE_FLAG_NO_BUFFERING** and
**FILE_FLAG_WRITE_THROUGH**.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `OPEN_VIRTUAL_DISK_FLAG_CUSTOM_DIFF_CHAIN:0x00000010`

Indicates the VHD file is to be opened without opening any differencing-chain parents and the parent chain is
to be created manually using the
[AddVirtualDiskParent](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-addvirtualdiskparent) function.

**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012.

### `OPEN_VIRTUAL_DISK_FLAG_PARENT_CACHED_IO:0x00000020`

### `OPEN_VIRTUAL_DISK_FLAG_VHDSET_FILE_ONLY:0x00000040`

### `OPEN_VIRTUAL_DISK_FLAG_IGNORE_RELATIVE_PARENT_LOCATOR:0x00000080`

### `OPEN_VIRTUAL_DISK_FLAG_NO_WRITE_HARDENING:0x00000100`

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))