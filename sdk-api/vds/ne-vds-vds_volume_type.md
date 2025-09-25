# VDS_VOLUME_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid types for a volume object.

## Constants

### `VDS_VT_UNKNOWN:0`

The volume type is unknown.

### `VDS_VT_SIMPLE:10`

The volume type is simple—it is composed of extents from exactly one disk.

### `VDS_VT_SPAN:11`

The volume type is spanned—it is composed of extents from more than one disk.

### `VDS_VT_STRIPE:12`

The volume type is striped, which is equivalent to RAID 0.

### `VDS_VT_MIRROR:13`

The volume type is mirrored, which is equivalent to RAID 1.

### `VDS_VT_PARITY:14`

The volume type is striped with parity, which accounts for RAID levels 3, 4, 5, and 6.

## Remarks

The [IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume) method passes a **VDS_VOLUME_TYPE** value as an argument to set a new volume type, and the [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure includes a **VDS_VOLUME_TYPE** value as a member to indicate the existing volume type.

**Note** Additional constants might be added to the **VDS_VOLUME_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VOLUME_TYPE** enumeration constant.

## See also

[IVdsPack::CreateVolume](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-createvolume)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)