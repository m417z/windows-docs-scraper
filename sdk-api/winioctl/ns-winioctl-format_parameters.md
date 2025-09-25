# FORMAT_PARAMETERS structure

## Description

Contains information used in formatting a contiguous set of disk tracks. It is used by the
[IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_format_tracks) control code.

## Members

### `MediaType`

The media type. For a list of values, see
[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type).

### `StartCylinderNumber`

The cylinder number at which to begin the format.

### `EndCylinderNumber`

The cylinder number at which to end the format.

### `StartHeadNumber`

The beginning head location.

### `EndHeadNumber`

The ending head location.

## See also

[IOCTL_DISK_FORMAT_TRACKS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_disk_format_tracks)

[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type)