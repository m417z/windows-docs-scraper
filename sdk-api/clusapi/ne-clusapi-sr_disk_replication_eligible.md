# SR_DISK_REPLICATION_ELIGIBLE enumeration

## Description

Specifies the various reasons a disk on a cluster node can be eligible or ineligible for replication.

## Constants

### `SrDiskReplicationEligibleNone:0`

None of the disks on the node are eligible for replication.

### `SrDiskReplicationEligibleYes:1`

The disk is eligible for replication.

### `SrDiskReplicationEligibleOffline:2`

The disk is offline.

### `SrDiskReplicationEligibleNotGpt:3`

The disk is not formatted with a GUID partition table (GPT).

### `SrDiskReplicationEligiblePartitionLayoutMismatch:4`

There are a different number of target and source partitions.

### `SrDiskReplicationEligibleInsufficientFreeSpace:5`

There is not enough free space on the disk.

### `SrDiskReplicationEligibleNotInSameSite:6`

The disk is not on the same site at the target disk.

### `SrDiskReplicationEligibleInSameSite:7`

The disk is on the same site as the target disk.

### `SrDiskReplicationEligibleFileSystemNotSupported:8`

The file system on the disk is not supported.

### `SrDiskReplicationEligibleAlreadyInReplication:9`

The disk is already being replicated.

### `SrDiskReplicationEligibleSameAsSpecifiedDisk:10`

The disk is the target disk.

### `SrDiskReplicationEligibleOther:9999`

Other.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[SR_RESOURCE_TYPE_DISK_INFO](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-sr_resource_type_disk_info)