# CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_INPUT structure

## Description

Represents an input buffer for the [CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_INT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks-ex2-int) control code.

## Members

### `dwFlags`

A bifmask of flags that specifies settings for the operation.

This member can contain the following values:

#### CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_ADD_VOLUME_INFO (0x00000001)

Retrieve volume information for the storage class devices.

#### CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_FILTER_BY_POOL (0x00000002)

Filter the results by storage pool by using the *guidPoolFilter* parameter.

#### CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_FLAG_INCLUDE_NON_SHARED_DISKS (0x00000004)

TBD.

### `guidPoolFilter`

A storage pool **GUID** that filters the results.

## See also

[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS_EX2_INT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks-ex2-int)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)