# USN_RANGE_TRACK_OUTPUT structure

## Description

Contains returned update sequence number (USN) from [FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges) control code.

## Members

### `Usn`

Returned update sequence number (USN) that identifies at what point in the USN Journal that range tracking was enabled.

## Remarks

This structure is optional.

## See also

[FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges)