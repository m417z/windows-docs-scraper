# VDS_VOLUME_PLEX_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a volume plex.

## Constants

### `VDS_VPT_UNKNOWN:0`

This value is reserved.

### `VDS_VPT_SIMPLE`

The plex type is simple—it is composed of extents from exactly one disk. This value corresponds to the **VDS_VT_SIMPLE** value of the [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration.

### `VDS_VPT_SPAN`

The plex type is spanned—it is composed of extents from more than one disk. This value corresponds to the **VDS_VT_SPAN** value of the [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration.

### `VDS_VPT_STRIPE`

The plex type is striped, which is equivalent to RAID 0. This value corresponds to the **VDS_VT_STRIPE** value of the [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration.

### `VDS_VPT_PARITY`

The plex type is striped with parity, which accounts for RAID levels 3, 4, 5, and 6. This value corresponds to the **VDS_VT_PARITY** value of the [VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type) enumeration.

## Remarks

The [VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop) structure includes a **VDS_VOLUME_PLEX_TYPE** value as a member to indicate the existing plex type.

**Note** Additional constants might be added to the **VDS_VOLUME_PLEX_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VOLUME_PLEX_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_VOLUME_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_plex_prop)

[VDS_VOLUME_TYPE](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_volume_type)