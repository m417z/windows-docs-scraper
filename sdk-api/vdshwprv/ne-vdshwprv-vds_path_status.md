# VDS_PATH_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the set of valid status values for a port.

## Constants

### `VDS_MPS_UNKNOWN:0`

The path status is unknown.

### `VDS_MPS_ONLINE:1`

The path is active.

### `VDS_MPS_FAILED:5`

The path is failed.

### `VDS_MPS_STANDBY:7`

The path is in standby mode.

## Remarks

**Note** Additional constants might be added to the **VDS_PATH_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PATH_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)