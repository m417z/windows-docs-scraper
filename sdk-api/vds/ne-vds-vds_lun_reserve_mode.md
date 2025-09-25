# VDS_LUN_RESERVE_MODE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Not supported.

This enumeration is reserved for future use.

## Constants

### `VDS_LRM_NONE:0`

This value is reserved.

### `VDS_LRM_EXCLUSIVE_RW:1`

This value is reserved.

### `VDS_LRM_EXCLUSIVE_RO:2`

This value is reserved.

### `VDS_LRM_SHARED_RO:3`

This value is reserved.

### `VDS_LRM_SHARED_RW:4`

This value is reserved.

## Remarks

**Note** Additional constants might be added to the **VDS_LUN_RESERVE_MODE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_RESERVE_MODE** enumeration constant.