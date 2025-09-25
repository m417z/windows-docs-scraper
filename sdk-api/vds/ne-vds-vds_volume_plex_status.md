# VDS_VOLUME_PLEX_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a volume plex.

## Constants

### `VDS_VPS_UNKNOWN:0`

This value is reserved.

### `VDS_VPS_ONLINE:1`

The volume plex is available.

### `VDS_VPS_NO_MEDIA:3`

The volume plex has no media.

### `VDS_VPS_FAILED:5`

The volume plex is unavailable.

## Remarks

The [VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop) structure includes a **VDS_VOLUME_PLEX_STATUS** value as a member to indicate the status of a volume plex.

**Note** Additional constants might be added to the **VDS_VOLUME_PLEX_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VOLUME_PLEX_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop)