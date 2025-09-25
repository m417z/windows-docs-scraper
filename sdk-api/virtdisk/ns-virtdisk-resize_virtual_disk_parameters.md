# RESIZE_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains the parameters for a
[ResizeVirtualDisk](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-resizevirtualdisk) function.

## Members

### `Version`

Discriminant for the union containing a value enumerated from the
[RESIZE_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/desktop/api/virtdisk/ne-virtdisk-resize_virtual_disk_version)
enumeration.

### `Version1`

If the **Version** member is
**RESIZE_VIRTUAL_DISK_VERSION_1** (1), this structure is used.

### `Version1.NewSize`

Contains the new size of the virtual disk.

## See also

[RESIZE_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/desktop/api/virtdisk/ne-virtdisk-resize_virtual_disk_version)

[ResizeVirtualDisk](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-resizevirtualdisk)

[VHD Functions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323699(v=vs.85))