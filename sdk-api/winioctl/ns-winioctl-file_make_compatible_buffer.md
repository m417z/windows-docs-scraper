# FILE_MAKE_COMPATIBLE_BUFFER structure

## Description

Specifies the disc to close the current session for. This control code is used for UDF file systems. This structure is used for input when calling [FSCTL_MAKE_MEDIA_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_make_media_compatible).

## Members

### `CloseDisc`

If **TRUE**, indicates the media should be finalized. No new data can be appended to the media.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_MAKE_MEDIA_COMPATIBLE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_make_media_compatible)