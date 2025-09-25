# _FORMAT_PARAMETERS structure

## Description

The FORMAT_PARAMETERS structure is used in conjunction with the [IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks) request to format the specified set of contiguous tracks on the disk.

## Members

### `MediaType`

Indicates format information, such as the disk size and the number of bytes per sector. For a list of the values that can be assigned to this member, see [MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562216(v=vs.85)).

### `StartCylinderNumber`

Indicates the number of the cylinder where the formatting should begin.

### `EndCylinderNumber`

Indicates the number of the cylinder where the formatting should end.

### `StartHeadNumber`

Indicates the number of the head where the formatting should begin.

### `EndHeadNumber`

Indicates the number of the head where the formatting should end.

## See also

[IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks)

[MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562216(v=vs.85))