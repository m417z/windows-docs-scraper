# USN_TRACK_MODIFIED_RANGES structure

## Description

Contains information on range tracking parameters for an update sequence number (USN) change journal using the [FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges) control code.

## Members

### `Flags`

Indicates enabling range tracking.

|  |  |
| --- | --- |
| Value | Description |
| FLAG_USN_TRACK_MODIFIED_RANGES_ENABLE 0x00000001 | This flag is mandatory with [FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges) and is used to enable range tracking on the volume. |

### `Unused`

Reserved.

### `ChunkSize`

Chunk size for tracking ranges. A single byte modification will be reflected as the whole chunk being modified.

### `FileSizeThreshold`

File size threshold to start outputting [USN_RECORD_V4 structure](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-usn_record_v4) record(s) for modified file, i.e. if the modified file size is less than this threshold, then no **USN_RECORD_V4** record will be output.

## Remarks

Once range tracking is enabled for a given volume it cannot be disabled except by deleting the USN Journal and recreating it.

## See also

[FSCTL_USN_TRACK_MODIFIED_RANGES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_usn_track_modified_ranges)