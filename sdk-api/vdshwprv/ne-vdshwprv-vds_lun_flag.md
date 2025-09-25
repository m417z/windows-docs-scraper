# VDS_LUN_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a LUN object.

## Constants

### `VDS_LF_LBN_REMAP_ENABLED:0x1`

The provider remaps LUN extents to drive extents automatically.

### `VDS_LF_READ_BACK_VERIFY_ENABLED:0x2`

The provider verifies writes by readback.

### `VDS_LF_WRITE_THROUGH_CACHING_ENABLED:0x4`

The provider enables write-through caching on the LUN.

### `VDS_LF_HARDWARE_CHECKSUM_ENABLED:0x8`

The provider verifies the integrity of the read and write data using a checksum.

### `VDS_LF_READ_CACHE_ENABLED:0x10`

Read caching is enabled on the LUN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LF_WRITE_CACHE_ENABLED:0x20`

Write caching is enabled on the LUN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LF_MEDIA_SCAN_ENABLED:0x40`

Media scanning is enabled on the LUN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LF_CONSISTENCY_CHECK_ENABLED:0x80`

Consistency checking is enabled on the LUN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LF_SNAPSHOT:0x100`

The LUN is a volume shadow copy LUN.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

This enumeration provides the values for the *ulFlags* member of the [VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop) structure and provides the value for the **VDS_LPF_LBN_REMAP_ENABLED** enumerator in the [VDS_LUN_PLEX_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_flag) enumeration.

**Note** Additional constants might be added to the **VDS_LUN_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PLEX_FLAG](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_lun_plex_flag)

[VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop)