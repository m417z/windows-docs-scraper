## Description

The **USN_RANGE_TRACK_OUTPUT** structure contains returned update sequence number (USN) from the [**FSCTL_USN_TRACK_MODIFIED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_usn_track_modified_ranges) control code.

## Members

### `Usn`

Returned update sequence number (USN) that identifies at what point in the USN Journal that range tracking was enabled.

## See also

[**FSCTL_USN_TRACK_MODIFIED_RANGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-fsctl_usn_track_modified_ranges)