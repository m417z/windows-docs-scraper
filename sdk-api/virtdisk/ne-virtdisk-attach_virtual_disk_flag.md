# ATTACH_VIRTUAL_DISK_FLAG enumeration

## Description

Contains virtual disk attach request flags.

## Constants

### `ATTACH_VIRTUAL_DISK_FLAG_NONE:0x00000000`

No flags. Use system defaults.

This enumeration value is not supported for ISO virtual disks.
**ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY** must be specified.

### `ATTACH_VIRTUAL_DISK_FLAG_READ_ONLY:0x00000001`

Attach the virtual disk as read-only.

**Windows 7 and Windows Server 2008 R2:** This flag is not supported for opening ISO virtual disks until Windows 8 and
Windows Server 2012.

### `ATTACH_VIRTUAL_DISK_FLAG_NO_DRIVE_LETTER:0x00000002`

No drive letters are assigned to the disk's volumes.

**Windows 7 and Windows Server 2008 R2:** This flag is not supported for opening ISO virtual disks until Windows 8 and
Windows Server 2012.

### `ATTACH_VIRTUAL_DISK_FLAG_PERMANENT_LIFETIME:0x00000004`

Will decouple the virtual disk lifetime from that of the *VirtualDiskHandle*. The
virtual disk will be attached until the
[DetachVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-detachvirtualdisk) function is called, even if all
open handles to the virtual disk are closed.

**Windows 7 and Windows Server 2008 R2:** This flag is not supported for opening ISO virtual disks until Windows 8 and
Windows Server 2012.

### `ATTACH_VIRTUAL_DISK_FLAG_NO_LOCAL_HOST:0x00000008`

Reserved.

This flag is not supported for ISO virtual disks.

### `ATTACH_VIRTUAL_DISK_FLAG_NO_SECURITY_DESCRIPTOR:0x00000010`

### `ATTACH_VIRTUAL_DISK_FLAG_BYPASS_DEFAULT_ENCRYPTION_POLICY:0x00000020`

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))