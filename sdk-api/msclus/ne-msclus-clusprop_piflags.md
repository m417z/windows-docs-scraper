# CLUSPROP_PIFLAGS enumeration

## Description

Represents disk partition information. The enumeration flags identify certain properties of a disk partition,
which is a
[storage class resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly).

## Constants

### `CLUSPROP_PIFLAG_STICKY:0x1`

The drive letter is sticky.

### `CLUSPROP_PIFLAG_REMOVABLE:0x2`

The storage class resource is removable.

### `CLUSPROP_PIFLAG_USABLE:0x4`

The storage class resource is formatted with a file system that is usable by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service).

### `CLUSPROP_PIFLAG_DEFAULT_QUORUM:0x8`

The partition should be used to store quorum files if no partition is specified in the
[SetClusterQuorumResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterquorumresource) function.

### `CLUSPROP_PIFLAG_USABLE_FOR_CSV:0x10`

The partition can be used in a cluster shared volume (CSV).

**Windows Server 2008 R2 and Windows Server 2008:** This value is supported starting with Windows Server 2012.

### `CLUSPROP_PIFLAG_ENCRYPTION_ENABLED:0x20`

The partition uses BitLocker encryption.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is supported starting with Windows Server 2016.

### `CLUSPROP_PIFLAG_UNKNOWN:0x80000000`

The partition uses an unknown file system type.

**Windows Server 2012 R2, Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is supported starting with Windows Server 2012 R2 with KB 3093899.

## Remarks

For [Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resources, the smallest NTFS partition
larger than 50 MB automatically receives the **CLUSPROP_PIFLAG_DEFAULT_QUORUM** flag.

## See also

[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)

[CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex)

[CLUS_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info)

[CLUS_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info_ex)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[Flags Property of the ClusPartition Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluspartition-flags)