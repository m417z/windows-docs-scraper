# LOOKUP_STREAM_FROM_CLUSTER_OUTPUT structure

## Description

Received as output from the [FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster) control code.

## Members

### `Offset`

Offset from the beginning of this structure to the first entry returned. If no entries are returned, this value is zero.

### `NumberOfMatches`

Number of matches to the input criteria. Note that more matches may be found than entries returned if the buffer provided is not large enough.

### `BufferSizeRequired`

Minimum size of the buffer, in bytes, which would be needed to contain all matching entries to the input criteria.

## See also

[FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)