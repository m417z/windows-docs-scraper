# VDS_LUN_PLEX_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a LUN plex.

## Constants

### `VDS_LPT_UNKNOWN:0`

This value is reserved.

### `VDS_LPT_SIMPLE`

The plex type is simple—it is composed of extents from exactly one drive.

### `VDS_LPT_SPAN`

The plex type is spanned—it is composed of extents from more than one drive.

### `VDS_LPT_STRIPE`

The plex type is striped, which is equivalent to RAID 0.

### `VDS_LPT_PARITY`

The plex type is striped with parity, which accounts for RAID levels 3, 4, 5, and 6.

### `VDS_LPT_RAID2`

The plex type is RAID level 2.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID3`

The plex type is RAID level 3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID4`

The plex type is RAID level 4.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID5`

The plex type is RAID level 5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID6`

The plex type is RAID level 6.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID03`

The plex type is RAID level 0+3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID05`

The plex type is RAID level 0+5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID10`

The plex type is RAID level 1+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID15`

The plex type is RAID level 1+5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID30`

The plex type is RAID level 3+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID50`

The plex type is RAID level 5+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID53`

The plex type is RAID level 5+3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LPT_RAID60`

The plex type is RAID level 6+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The [VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop) structure includes a **VDS_LUN_PLEX_TYPE** value as a member to indicate the existing plex type.

If your application encounters a [VDS_HWPROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_hwprovider_type) value that it does not recognize, it should display the provider type as unknown. It should not attempt to map the unrecognized provider type to another provider type.

**Note** Additional constants might be added to the **VDS_LUN_PLEX_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_PLEX_TYPE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop)

[VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type)