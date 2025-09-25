# CLUS_PARTITION_INFO structure

## Description

Contains data describing a
[storage class resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) volume and file
system. It is used as the data member of a
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info) structure and as the
return value of some [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) operations.

## Members

### `dwFlags`

Flags that describes the storage class resource, enumerated by the
[CLUSPROP_PIFLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusprop_piflags) enumeration.

#### CLUSPROP_PIFLAG_STICKY (0x00000001)

The drive letter is sticky.

#### CLUSPROP_PIFLAG_REMOVABLE (0x00000002)

The storage class resource is removable.

#### CLUSPROP_PIFLAG_USABLE (0x00000004)

The storage class resource is formatted with a file system that is usable by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service).

#### CLUSPROP_PIFLAG_DEFAULT_QUORUM (0x00000008)

The partition should be used to store quorum files if no partition is specified in the
[SetClusterQuorumResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterquorumresource) function. For
[Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resources, the smallest NTFS partition
larger than 50MB automatically receives this flag.

### `szDeviceName`

Device name for the storage class resource, such as "C:". No backslash is included.

### `szVolumeLabel`

Volume label for the storage class resource.

### `dwSerialNumber`

Serial number of the storage class resource volume.

### `rgdwMaximumComponentLength`

Value of the maximum length, in characters, of a file name component supported by the specified file
system. A file name component is the portion of a file name between backslashes.

### `dwFileSystemFlags`

Value that describes the file system. One or more of the following flags are valid.

#### FS_CASE_IS_PRESERVED (0x00000002)

The file system preserves the case of file names when it places a name on the storage class
resource.

#### FS_CASE_SENSITIVE (0x00000001)

The file system supports case-sensitive file names.

#### FS_UNICODE_STORED_ON_DISK (0x00000004)

The file system supports Unicode in file names as they appear on storage class resource.

#### FS_PERSISTENT_ACLS (0x00000008)

The file system preserves and enforces access control lists (ACLs).

### `szFileSystem`

Name of the file system, such as "FAT" or "NTFS".

## Remarks

A **CLUS_PARTITION_INFO** structure can be returned by
[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) when the
*dwControlCode* parameter is set to
[CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info)
and can be returned by
[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol) when
*dwControlCode* is set to
[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks).

#### Examples

See
[Creating Physical Disk Resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-physical-disk-resources).

## See also

[CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info)

[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks)

[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)

[ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol)

[ClusterResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecontrol)