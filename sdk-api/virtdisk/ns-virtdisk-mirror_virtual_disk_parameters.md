# MIRROR_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains virtual hard disk (VHD) mirror request parameters.

## Members

### `Version`

Indicates the version of this structure to use. Set this to
**MIRROR_VIRTUAL_DISK_VERSION_1** (1).

### `Version1`

This structure is used if the **Version** member is set to
**MIRROR_VIRTUAL_DISK_VERSION_1**.

### `Version1.MirrorVirtualDiskPath`

[Fully qualified](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) path where the mirrored
virtual disk will be located. If the *Flags* parameter to
[MirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk) is
**MIRROR_VIRTUAL_DISK_FLAG_NONE** (0) then this file must not exist. If the
*Flags* parameter to
**MirrorVirtualDisk** is
**MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE** (1) then this file must exist.

## See also

[MirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk)

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))