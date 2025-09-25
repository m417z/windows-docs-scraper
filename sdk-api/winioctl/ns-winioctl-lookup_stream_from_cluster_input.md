# LOOKUP_STREAM_FROM_CLUSTER_INPUT structure

## Description

Passed as input to the
[FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster) control
code.

## Members

### `Flags`

Flags for the operation. Currently no flags are defined.

### `NumberOfClusters`

Number of clusters in the following array of clusters. The input buffer must be large enough to contain
this number or the operation will fail.

### `Cluster`

An array of one or more clusters to look up.

## See also

[FSCTL_LOOKUP_STREAM_FROM_CLUSTER](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_lookup_stream_from_cluster)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)