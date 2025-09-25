# VDS_STORAGE_BUS_TYPE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the set of valid bus types of a storage device.

## Constants

### `VDSBusTypeUnknown:0`

This value is reserved.

### `VDSBusTypeScsi:0x1`

The storage bus type is SCSI.

### `VDSBusTypeAtapi:0x2`

The storage bus type is ATAPI.

### `VDSBusTypeAta:0x3`

The storage bus type is ATA.

### `VDSBusType1394:0x4`

The storage bus type is IEEE 1394.

### `VDSBusTypeSsa:0x5`

The storage bus type is SSA.

### `VDSBusTypeFibre:0x6`

The storage bus type is Fibre Channel.

### `VDSBusTypeUsb:0x7`

The storage bus type is USB.

### `VDSBusTypeRAID:0x8`

The storage bus type is RAID.

### `VDSBusTypeiScsi:0x9`

The storage bus type is iSCSI.

### `VDSBusTypeSas:0xa`

The storage bus type is Serial Attached SCSI (SAS).

### `VDSBusTypeSata:0xb`

The storage bus type is SATA.

### `VDSBusTypeSd:0xc`

The storage bus type is Secure Digital (SD).

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDSBusTypeMmc:0xd`

The storage bus type is MultiMedia Card (MMC).

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDSBusTypeMax:0xe`

This value is reserved for system use.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDSBusTypeVirtual:0xe`

### `VDSBusTypeFileBackedVirtual:0xf`

The storage bus type is file-backed virtual.

**Windows Server 2008, Windows Vista and Windows Server 2003:** Not supported.

### `VDSBusTypeSpaces:0x10`

### `VDSBusTypeNVMe:0x11`

### `VDSBusTypeScm:0x12`

### `VDSBusTypeUfs:0x13`

### `VDSBusTypeMaxReserved:0x7f`

The maximum value of the storage bus type range.

## Remarks

The [VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information), [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop), [VDS_DISK_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop2), and [VDS_DRIVE_PROP2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop2) structures include a **VDS_STORAGE_BUS_TYPE** value as a member to specify the bus type of a LUN, disk, or drive.

**Note** The type specified in these structures matches the type that the driver or drivers reported and may not exactly match the hardware.

**Note** Additional constants might be added to the **VDS_STORAGE_BUS_TYPE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_STORAGE_BUS_TYPE** enumeration constant.

## See also

[STORAGE_BUS_TYPE](https://msdn.microsoft.com/library/aa510102.aspx)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_LUN_INFORMATION](https://learn.microsoft.com/windows/desktop/api/vdslun/ns-vdslun-vds_lun_information)