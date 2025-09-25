# SR_RESOURCE_TYPE_QUERY_ELIGIBLE_LOGDISKS structure

## Description

Describes a set of retrieved disks that can be used as log disks for the specified data disk.This is a data structure for a value list that is returned by the [CLUSCTL_RESOURCE_TYPE_REPLICATION_GET_ELIGIBLE_LOGDISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-replication-get-eligible-logdisks) control code.

## Members

### `DataDiskGuid`

The cluster resource identifier of the data disk.

### `IncludeOfflineDisks`

When **TRUE**, the result set includes all the offline disks in the available storage group.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)