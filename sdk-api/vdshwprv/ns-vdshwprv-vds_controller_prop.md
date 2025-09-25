# VDS_CONTROLLER_PROP structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
properties of a [controller object](https://learn.microsoft.com/windows/desktop/VDS/controller-object).

## Members

### `id`

The GUID of the controller object.

### `pwszFriendlyName`

The name of the controller; a zero-terminated, human-readable string.

### `pwszIdentification`

The subsystem identifier, typically a serial number; a zero-terminated, human-readable string.

### `status`

A
[VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status) enumeration value that specifies the status of the controller.

### `health`

A
[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) enumeration value that specifies the health state of the controller. The following are the valid values for this member.

**Windows Server 2008, Windows Vista and Windows Server 2003:** **VDS_H_REPLACED** and **VDS_H_DEGRADED** are not supported.

#### VDS_H_UNKNOWN (0)

#### VDS_H_HEALTHY (1)

#### VDS_H_FAILED (8)

#### VDS_H_REPLACED (9)

#### VDS_H_DEGRADED (11)

### `sNumberOfPorts`

The number of ports that the controller contains. Ports are numbered from zero. Hardware providers should set this member to zero for PCI RAID cards.

##### - health.VDS_H_DEGRADED (11)

##### - health.VDS_H_FAILED (8)

##### - health.VDS_H_HEALTHY (1)

##### - health.VDS_H_REPLACED (9)

##### - health.VDS_H_UNKNOWN (0)

## Remarks

The [IVdsController::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getproperties)
method returns this structure to report the properties of a [controller object](https://learn.microsoft.com/windows/desktop/VDS/controller-object).

## See also

[IVdsController::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getproperties)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status)

[VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health)