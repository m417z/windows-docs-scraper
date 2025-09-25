# CLUS_PARTITION_INFO_EX2 structure

## Description

Describes the disk partition information of a
[storage class resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly). This structure is used as the data member of a
[CLUSPROP_PARTITION_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex2) structure.

## Members

### `GptPartitionId`

The globally unique identifier (GUID) of the partition.

### `szPartitionName`

The name of the partition.

### `EncryptionFlags`

A flag that indicates whether BitLocker encryption is enabled on the partition.

#### BitLockerEnabled (0x00000001L)

#### BitLockerDecrypted (0x00000004L)

#### BitLockerEncrypted (0x00000008L)

#### BitLockerDecrypting (0x00000010L)

#### BitLockerEncrypting (0x00000020L)

#### BitLockerPaused (0x00000040L)

#### BitLockerStopped (0x00000080L)

#### BitLockerFlagsAll ((BitLockerEnabled | BitLockerDecrypted | BitlockerEncrypted | BitLockerDecrypting | BitlockerEncrypting | BitLockerPaused | BitLockerStopped)

## See also

[CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info-ex2)

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)