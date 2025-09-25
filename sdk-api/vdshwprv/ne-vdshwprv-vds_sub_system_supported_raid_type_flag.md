# VDS_SUB_SYSTEM_SUPPORTED_RAID_TYPE_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of RAID levels that can be supported by subsystems.

## Constants

### `VDS_SF_SUPPORTS_RAID2_LUNS:0x1`

Supports RAID level 2.

### `VDS_SF_SUPPORTS_RAID3_LUNS:0x2`

Supports RAID level 3.

### `VDS_SF_SUPPORTS_RAID4_LUNS:0x4`

Supports RAID level 4.

### `VDS_SF_SUPPORTS_RAID5_LUNS:0x8`

Supports RAID level 5.

### `VDS_SF_SUPPORTS_RAID6_LUNS:0x10`

Supports RAID level 6.

### `VDS_SF_SUPPORTS_RAID01_LUNS:0x20`

Supports RAID level 0+1.

### `VDS_SF_SUPPORTS_RAID03_LUNS:0x40`

Supports RAID level 0+3.

### `VDS_SF_SUPPORTS_RAID05_LUNS:0x80`

Supports RAID level 0+5.

### `VDS_SF_SUPPORTS_RAID10_LUNS:0x100`

Supports RAID level 1+0.

### `VDS_SF_SUPPORTS_RAID15_LUNS:0x200`

Supports RAID level 1+5.

### `VDS_SF_SUPPORTS_RAID30_LUNS:0x400`

Supports RAID level 3+0.

### `VDS_SF_SUPPORTS_RAID50_LUNS:0x800`

Supports RAID level 5+0.

### `VDS_SF_SUPPORTS_RAID51_LUNS:0x1000`

Supports RAID level 5+1.

### `VDS_SF_SUPPORTS_RAID53_LUNS:0x2000`

Supports RAID level 5+3.

### `VDS_SF_SUPPORTS_RAID60_LUNS:0x4000`

Supports RAID level 6+0.

### `VDS_SF_SUPPORTS_RAID61_LUNS:0x8000`

Supports RAID level 6+1.

## Remarks

The values of this enumeration are used in the **ulSupportedRaidTypeFlags** member of the [VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2) structure.

**Note** Additional constants might be added to the **VDS_SUB_SYSTEM_SUPPORTED_RAID_TYPE_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_SUB_SYSTEM_SUPPORTED_RAID_TYPE_FLAG** enumeration constant.

## See also

[IVdsSubSystem2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystem2)

[IVdsSubSystem2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem2-getproperties2)

[VDS_RAID_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_raid_type)

[VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2)