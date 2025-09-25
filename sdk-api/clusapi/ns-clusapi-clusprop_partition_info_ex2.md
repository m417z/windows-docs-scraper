# CLUSPROP_PARTITION_INFO_EX2 structure

## Description

A value list entry that contains partition information for a storage class resource. This structure is as a input, and a as a return value for the [CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info-ex2) control code.

## Members

### `CLUSPROP_PARTITION_INFO_EX`

A [CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex) structure that describes the format,
type, and length of the partition information.

### `CLUS_PARTITION_INFO_EX2`

A [CLUS_PARTITION_INFO_EX2](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info_ex2) structure that contains the values of the partition information.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)