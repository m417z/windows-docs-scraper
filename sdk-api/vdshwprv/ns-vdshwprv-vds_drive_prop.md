# VDS_DRIVE_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object).

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

##### - health.VDS_H_FAILED (8)

##### - health.VDS_H_HEALTHY (1)

##### - health.VDS_H_PENDING_FAILURE (10)

##### - health.VDS_H_REPLACED (9)

##### - health.VDS_H_UNKNOWN (0)

## Remarks

The [IVdsDrive::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-getproperties) method
returns this structure to report the properties of a [drive object](https://learn.microsoft.com/windows/desktop/VDS/drive-object).

## See also

[IVdsDrive::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DRIVE_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_flag)

[VDS_DRIVE_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_status)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)