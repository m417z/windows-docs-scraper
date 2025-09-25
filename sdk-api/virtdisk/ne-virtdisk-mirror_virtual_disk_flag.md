# MIRROR_VIRTUAL_DISK_FLAG enumeration

## Description

Contains virtual hard disk (VHD) mirror request flags.

## Constants

### `MIRROR_VIRTUAL_DISK_FLAG_NONE:0x00000000`

The mirror virtual disk file does not exist, and needs to be created.

### `MIRROR_VIRTUAL_DISK_FLAG_EXISTING_FILE:0x00000001`

Create the mirror using an existing file.

### `MIRROR_VIRTUAL_DISK_FLAG_SKIP_MIRROR_ACTIVATION:0x00000002`

## See also

[MIRROR_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-mirror_virtual_disk_parameters)

[MirrorVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-breakmirrorvirtualdisk)

[VHD Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323698(v=vs.85))