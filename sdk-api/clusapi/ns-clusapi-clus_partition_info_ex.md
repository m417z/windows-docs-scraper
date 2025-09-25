# CLUS_PARTITION_INFO_EX structure

## Description

Describes a
[storage class resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly) volume and file
system. It is used as the data member of a
[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info) structure and as the
return value of some [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) operations.

## Members

### `dwFlags`

Flags that describes the storage class resource, enumerated by the
[CLUSPROP_PIFLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusprop_piflags) enumeration.

#### CLUSPROP_PIFLAG_STICKY (1)

The drive letter is sticky.

#### CLUSPROP_PIFLAG_REMOVABLE (2)

The storage class resource is removable.

#### CLUSPROP_PIFLAG_USABLE (4)

The storage class resource is formatted with a file system that is usable by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service).

#### CLUSPROP_PIFLAG_DEFAULT_QUORUM (8)

The partition should be used to store quorum files if no partition is specified in the
[SetClusterQuorumResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterquorumresource) function. For
[Physical Disk](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/physical-disk) resources, the smallest NTFS partition
larger than 50MB automatically receives this flag.

### `szDeviceName`

Device name for the storage class resource, such as "C:". No backslashes are included.

### `szVolumeLabel`

Volume label for the storage class resource.

### `dwSerialNumber`

Serial number of the storage class resource volume.

### `rgdwMaximumComponentLength`

Maximum length, in characters, of a file name component supported by the specified file system. A file name
component is that portion of a file name between backslashes.

### `dwFileSystemFlags`

Flags that describes the file system. One or more of the following flags are valid.

#### FS_CASE_SENSITIVE (1)

The file system supports case-sensitive file names.

#### FS_CASE_IS_PRESERVED (2)

The file system preserves the case of file names when it places a name on the storage class
resource.

#### FS_UNICODE_STORED_ON_DISK (4)

The file system supports Unicode in file names as they appear on storage class resource.

#### FS_PERSISTENT_ACLS (8)

The file system preserves and enforces access control lists (ACLs).

### `szFileSystem`

Name of the file system, such as "FAT" or "NTFS".

### `TotalSizeInBytes`

Specifies the total size, in bytes, of the volume. This value may not be properly aligned and should be accessed using
**UNALIGNED** pointers.

### `FreeSizeInBytes`

Specifies the size, in bytes, of the unallocated space on the volume. This value may not be properly aligned and should be accessed using
**UNALIGNED** pointers.

### `DeviceNumber`

The device number

### `PartitionNumber`

The partition number.

### `VolumeGuid`

The globally unique identifier associated with the volume.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)