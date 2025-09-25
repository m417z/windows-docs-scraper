## Description

The **USN_TRACK_MODIFIED_RANGES** structure contains returned update sequence number (USN) from [**FSCTL_USN_TRACK_MODIFIED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_usn_track_modified_ranges) control code.

## Members

### `Flags`

Indicates enabling range tracking.

| Value | Description |
| ----- | ----------- |
| FLAG_USN_TRACK_MODIFIED_RANGES_ENABLE 0x00000001 | This flag is mandatory with FSCTL_USN_TR**ACK_MODIFIED_RANGES and is used to enable range tracking on the volume. |

### `Unused`

Reserved.

### `ChunkSize`

Chunk size for tracking ranges. A single byte modification will be reflected as the whole chunk being modified.

### `FileSizeThreshold`

File size threshold to start outputting [**USN_RECORD_V4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-usn_record_v4) structure record(s) for modified file, i.e. if the modified file size is less than this threshold, then no **USN_RECORD_V4** record will be output.

## See also

[**FSCTL_USN_TRACK_MODIFIED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_usn_track_modified_ranges)