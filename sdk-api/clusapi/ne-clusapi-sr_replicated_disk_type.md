# SR_REPLICATED_DISK_TYPE enumeration

## Description

Specifies the replicated disk types for the [SR_RESOURCE_TYPE_REPLICATED_DISK](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-sr_resource_type_replicated_disk) structure.

## Constants

### `SrReplicatedDiskTypeNone:0`

None.

### `SrReplicatedDiskTypeSource:1`

The source of replication.

### `SrReplicatedDiskTypeLogSource:2`

A log disk that is the source of replication.

### `SrReplicatedDiskTypeDestination:3`

The destination of replication.

### `SrReplicatedDiskTypeLogDestination:4`

A log disk that is the destination of replication.

### `SrReplicatedDiskTypeNotInParthership:5`

The disk is not in a replication partnership.

### `SrReplicatedDiskTypeLogNotInParthership:6`

A log disk that is not in a replication partnership.

### `SrReplicatedDiskTypeOther`

Other.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)