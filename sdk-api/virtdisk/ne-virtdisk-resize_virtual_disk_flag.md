# RESIZE_VIRTUAL_DISK_FLAG enumeration

## Description

Enumerates the available flags for the
[ResizeVirtualDisk](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-resizevirtualdisk) function.

## Constants

### `RESIZE_VIRTUAL_DISK_FLAG_NONE:0x0`

No flags are specified.

### `RESIZE_VIRTUAL_DISK_FLAG_ALLOW_UNSAFE_VIRTUAL_SIZE:0x1`

If this flag is set, skip checking the virtual disk's partition table to ensure that this truncation is
safe. Setting this flag can cause unrecoverable data loss; use with care.

### `RESIZE_VIRTUAL_DISK_FLAG_RESIZE_TO_SMALLEST_SAFE_VIRTUAL_SIZE:0x2`

If this flag is set, resize the disk to the smallest virtual size possible without truncating past any
existing partitions. If this is set, the **NewSize** member in the
[RESIZE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/virtdisk/ns-virtdisk-resize_virtual_disk_parameters)
structure must be zero.

## See also

[RESIZE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/virtdisk/ns-virtdisk-resize_virtual_disk_parameters)

[ResizeVirtualDisk](https://learn.microsoft.com/windows/desktop/api/virtdisk/nf-virtdisk-resizevirtualdisk)

[VHD Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323698(v=vs.85))