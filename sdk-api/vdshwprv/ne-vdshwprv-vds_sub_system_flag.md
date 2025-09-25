# VDS_SUB_SYSTEM_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the set of valid flags for a subsystem object.

## Constants

### `VDS_SF_LUN_MASKING_CAPABLE:0x1`

The subsystem supports LUN masking. This flag applies only to external hardware
providers—internal hardware providers do not support LUN masking.

### `VDS_SF_LUN_PLEXING_CAPABLE:0x2`

The provider supports LUNs with more than one plex.

### `VDS_SF_LUN_REMAPPING_CAPABLE:0x4`

The provider supports automatic remapping of LUN extents to drive extents.

### `VDS_SF_DRIVE_EXTENT_CAPABLE:0x8`

The provider supports the use of drive extents in LUN creation. If this flag is not set, the
provider uses only whole drives to create LUNs.

### `VDS_SF_HARDWARE_CHECKSUM_CAPABLE:0x10`

The provider supports verifying the integrity of the read and write data using a checksum. If this
flag is not set, the provider does not support using a checksum.

### `VDS_SF_RADIUS_CAPABLE:0x20`

The subsystem supports RADIUS.

### `VDS_SF_READ_BACK_VERIFY_CAPABLE:0x40`

The subsystem supports read verification of data that has been written.

### `VDS_SF_WRITE_THROUGH_CACHING_CAPABLE:0x80`

The subsystem supports write-through caching.

### `VDS_SF_SUPPORTS_FAULT_TOLERANT_LUNS:0x200`

The subsystem supports creation of automagic fault tolerant LUNs.

### `VDS_SF_SUPPORTS_NON_FAULT_TOLERANT_LUNS:0x400`

The subsystem supports creation of automagic non-fault tolerant LUNs.

### `VDS_SF_SUPPORTS_SIMPLE_LUNS:0x800`

The subsystem supports creation of simple LUNs.

### `VDS_SF_SUPPORTS_SPAN_LUNS:0x1000`

The subsystem supports creation of spanned LUNs.

### `VDS_SF_SUPPORTS_STRIPE_LUNS:0x2000`

The subsystem supports creation of striped LUNs.

### `VDS_SF_SUPPORTS_MIRROR_LUNS:0x4000`

The subsystem supports creation of mirrored LUNs.

### `VDS_SF_SUPPORTS_PARITY_LUNS:0x8000`

The subsystem supports creation of striped with parity LUNs.

### `VDS_SF_SUPPORTS_AUTH_CHAP:0x10000`

The subsystem supports one-way CHAP authentication.

### `VDS_SF_SUPPORTS_AUTH_MUTUAL_CHAP:0x20000`

The subsystem supports mutual CHAP authentication.

### `VDS_SF_SUPPORTS_SIMPLE_TARGET_CONFIG:0x40000`

The subsystem supports only simple target configurations and automatically assigns LUNs to targets during LUN
creation. Such a target must be configured with at least one associated portal in the target's portal group. The provider is responsible for correctly associating portals with the target. A VDS application should not assume that the subsystem has the ability to create or delete simple targets.

### `VDS_SF_SUPPORTS_LUN_NUMBER:0x80000`

The subsystem supports LUN numbering. See the [IVdsLunNumber::GetLunNumber](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunnumber-getlunnumber) method.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_SF_SUPPORTS_MIRRORED_CACHE:0x100000`

The subsystem supports LUNs that use a mirrored cache. See the **bUseMirroredCache** member of the [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_SF_READ_CACHING_CAPABLE:0x200000`

The subsystem supports read caching on LUNs. See the **VDS_LF_READ_CACHE_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **bReadCachingEnabled** member of the [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_SF_WRITE_CACHING_CAPABLE:0x400000`

The subsystem supports write caching on LUNs. See the **VDS_LF_WRITE_CACHE_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **bWriteCachingEnabled** member of the [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_SF_MEDIA_SCAN_CAPABLE:0x800000`

The subsystem supports media scanning on LUNs. See the **VDS_LF_MEDIA_SCAN_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **bMediaScanEnabled** member of the [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

### `VDS_SF_CONSISTENCY_CHECK_CAPABLE:0x1000000`

The subsystem supports consistency checking on LUNs. See the **VDS_LF_CONSISTENCY_CHECK_ENABLED** value of the [VDS_LUN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_flag) enumeration and the **bConsistencyCheckEnabled** member of the [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This flag is not supported.

## Remarks

This enumeration provides the values for the **ulFlags** member of the
[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) and [VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2) structures.

**Note** Additional constants might be added to the **VDS_SUB_SYSTEM_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_SUB_SYSTEM_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop)

[VDS_SUB_SYSTEM_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop2)