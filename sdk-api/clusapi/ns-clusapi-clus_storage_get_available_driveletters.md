# CLUS_STORAGE_GET_AVAILABLE_DRIVELETTERS structure

## Description

Contains a bitmask of the driver letters that are available on a node. It is used as the return value of the [CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DRIVELETTERS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-driveletters) control code.

## Members

### `AvailDrivelettersMask`

The least significant bit represents the letter 'A' and is set to zero if any partition on the node has that drive letter in use. This convention continues until bit 26, which represents the letter 'Z'. The value of bits 27 through 32 is not defined.

## See also

[CLUSCTL_RESOURCE_TYPE_STORAGE_GET_DRIVELETTERS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-driveletters)