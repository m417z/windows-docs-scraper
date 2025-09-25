# VDS_LUN_PLEX_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a LUN plex object.

## Constants

### `VDS_LPF_LBN_REMAP_ENABLED`

If set, the provider remaps LUN extents to drive extents automatically. This flag corresponds to the **VDS_LF_LBN_REMAP_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration.

## Remarks

This enumeration provides the value for the **ulFlags** member of the [VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop) structure.

**Note** Additional constants might be added to the **VDS_LUN_PLEX_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_PLEX_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag)

[VDS_LUN_PLEX_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_plex_prop)