# VDS_LUN_PLEX_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a LUN plex.

## Constants

### `VDS_LPS_UNKNOWN:0`

This value is reserved.

### `VDS_LPS_ONLINE:1`

The plex is available.

### `VDS_LPS_NOT_READY:2`

The plex is busy.

### `VDS_LPS_OFFLINE:4`

The plex is unavailable.

### `VDS_LPS_FAILED:5`

The plex has failed.

## Remarks

The [VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop) structure includes a **VDS_LUN_PLEX_STATUS** value as a member to indicate the current status of the LUN plex.

**Note** Additional constants might be added to the **VDS_LUN_PLEX_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_PLEX_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop)