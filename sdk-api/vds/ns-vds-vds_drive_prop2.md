# VDS_DRIVE_PROP2 structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object). This structure is identical to the [VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop) structure, except that it includes the enclosure number, bus type, and spindle speed as members.

## Members

### `id`

The GUID of the drive object.

### `ullSize`

The size of the drive, in bytes.

### `pwszFriendlyName`

A **NULL**-terminated wide-character string that contains the name of the drive.

### `pwszIdentification`

A **NULL**-terminated wide-character string that contains the drive identifier.

### `ulFlags`

A bitmask of
[VDS_DRIVE_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_flag) enumeration values.

### `status`

A
[VDS_DRIVE_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_status) enumeration value that specifies the status of the drive.

### `health`

A
[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health status of the drive. The following are the valid values for this member.

**Windows Server 2008, Windows Vista and Windows Server 2003:** **VDS_H_REPLACED** and **VDS_H_PENDING_FAILURE** are not supported.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_FAILED (8)

#### VDS_H_REPLACED (9)

#### VDS_H_PENDING_FAILURE (10)

### `sInternalBusNumber`

The number of the bus to which the drive is connected. This number is an implementer-assigned value that uniquely identifies the bus within the subsystem. It is not constrained by the number of buses that the subsystem contains, and it is not related to the value of the **sNumberOfInternalBuses** member of the [VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) structure.

### `sSlotNumber`

The number of the slot that the drive occupies. This number is an implementer-assigned value that uniquely identifies the slot within the bus. It is not constrained by the number of slots that the bus contains, and it is not related to the value of the **sMaxNumberOfSlotsEachBus** member of the [VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) structure.

### `ulEnclosureNumber`

The number of the enclosure that contains the drive. A value of ULONG_MAX indicates that this number is not defined for the drive. Because some enclosure numbering schemes are zero-based, zero is a valid value for this member. This member corresponds to the *ulEnclosureNumber* parameter of the [IVdsSubSystem2::GetDrive2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem2-getdrive2) method.

### `busType`

A [VDS_STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/vdslun/ne-vdslun-vds_storage_bus_type) value that specifies the bus type of the drive. A value of zero means that the bus type is unknown.

### `ulSpindleSpeed`

The spindle speed of the drive, in RPM. The default value for this member is zero. A value of zero means that the spindle speed is unknown. A value of 1 means that the drive does not have rotating media. (For example, it might be a solid-state drive.)

## Remarks

This structure is used by the [IVdsDrive2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive2-getproperties2) method to return the properties for a [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object).