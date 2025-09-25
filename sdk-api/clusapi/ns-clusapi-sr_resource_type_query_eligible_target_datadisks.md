# SR_RESOURCE_TYPE_QUERY_ELIGIBLE_TARGET_DATADISKS structure

## Description

Describes a set of retrieved data disks that can be used as target sites for replication.

## Members

### `SourceDataDiskGuid`

The cluster resource identifier of the data disk.

### `TargetReplicationGroupGuid`

The identifier of the replication group that contains the retrieved data disks.

### `SkipConnectivityCheck`

**true** if the disks that are connected to the same nodes as the source disk are included in result set.

### `IncludeOfflineDisks`

**true** if the result set includes all offline disks in the available storage group.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)