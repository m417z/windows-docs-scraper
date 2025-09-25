# VDS_DRIVE_FLAG enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of valid flags for a [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object).

## Constants

### `VDS_DRF_HOTSPARE:0x1`

The drive is reserved for use only as a hot spare.

### `VDS_DRF_ASSIGNED:0x2`

The drive is assigned to a RAID group or [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_DRF_UNASSIGNED:0x4`

The drive is not assigned to a RAID group or storage pool.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_DRF_HOTSPARE_IN_USE:0x8`

The drive is in use as a hot spare.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

### `VDS_DRF_HOTSPARE_STANDBY:0x10`

The drive is on standby as a hot spare.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

This enumeration provides the values for the *ulFlags* member of the [VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop) structure.

This enumeration provides the values for the *ulFlags* member of the [VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop) structure.

**Note** Additional constants might be added to the **VDS_DRIVE_FLAG** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DRIVE_FLAG** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop)

[VDS_DRIVE_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop2)