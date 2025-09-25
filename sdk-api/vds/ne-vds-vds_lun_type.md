# VDS_LUN_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a LUN.

## Constants

### `VDS_LT_UNKNOWN:0`

This value is reserved.

### `VDS_LT_DEFAULT:1`

The LUN type is default automagic—the provider configures the LUN automatically based on hints. This value is used as an input parameter only; it is not returned by queries.

### `VDS_LT_FAULT_TOLERANT:2`

The LUN type is fault tolerant automagic—the provider configures the LUN automatically based on hints, but with the requirement that the resulting LUN is fault tolerant. This value is used as an input parameter only; it is not returned by queries.

### `VDS_LT_NON_FAULT_TOLERANT:3`

The LUN type is non-fault tolerant automagic—the provider configures the LUN automatically based on hints, but with the requirement that the resulting LUN is non-fault tolerant. This value is used as an input parameter only; it is not returned by queries.

### `VDS_LT_SIMPLE:10`

The LUN type is simple—it is composed of extents from exactly one drive.

### `VDS_LT_SPAN:11`

The LUN's type is spanned—it is composed of extents from more than one drive.

### `VDS_LT_STRIPE:12`

The LUN type is striped, which is equivalent to RAID 0.

### `VDS_LT_MIRROR:13`

The LUN type is mirrored, which is equivalent to RAID 1.

### `VDS_LT_PARITY:14`

The LUN type is striped with parity, which accounts for RAID levels 3, 4, 5, and 6.

### `VDS_LT_RAID2:15`

The LUN type is RAID level 2.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID3:16`

The LUN type is RAID level 3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID4:17`

The LUN type is RAID level 4.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID5:18`

The LUN type is RAID level 5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID6:19`

The LUN type is RAID level 6.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID01:20`

The LUN type is RAID level 0+1.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID03:21`

The LUN type is RAID level 0+3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID05:22`

The LUN type is RAID level 0+5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID10:23`

The LUN type is RAID level 1+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID15:24`

The LUN type is RAID level 1+5.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID30:25`

The LUN type is RAID level 3+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID50:26`

The LUN type is RAID level 5+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID51:27`

The LUN type is RAID level 5+1.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID53:28`

The LUN type is RAID level 5+3.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID60:29`

The LUN type is RAID level 6+0.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_LT_RAID61:30`

The LUN type is RAID level 6+1.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The
[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method passes a **VDS_LUN_TYPE** value as a parameter to set a new LUN type, and the [VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop) structure includes a **VDS_LUN_TYPE** value as a member to indicate an existing LUN type.

If the [IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method returns a **VDS_LUN_TYPE** value that the caller does not recognize, the caller should display the LUN type as unknown. The caller should not attempt to map the unrecognized LUN type to another LUN type.

**Note** Additional constants might be added to the **VDS_LUN_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_TYPE** enumeration constant.

## See also

[IVdsHwProviderStoragePools::CreateLunInStoragePool](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem2-createlun2)

**IVdsSubSystem2::CreateLun2**

[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop)