# VDS_CONTROLLER_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a controller.

## Constants

### `VDS_CS_UNKNOWN:0`

The status of the controller cannot be determined.

### `VDS_CS_ONLINE:1`

The controller is physically present and in use. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value associated with this controller status can be any value except **VDS_H_FAILED**.

### `VDS_CS_NOT_READY:2`

The controller is busy. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value except **VDS_H_FAILED**.

### `VDS_CS_OFFLINE:4`

The controller is physically present but not available for use. For example, the controller has been set to the inactive state. When this controller status is set, a **VDS_NF_CONTROLLER_REMOVED** notification is sent. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value.

### `VDS_CS_FAILED:5`

The controller has failed. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value should be **VDS_H_FAILED** or **VDS_H_FAILING**.

### `VDS_CS_REMOVED:8`

The controller has been physically unplugged from the subsystem. When this status is set, a **VDS_NF_CONTROLLER_DEPART** notification is sent.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The [IVdsController::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-setstatus) method passes a **VDS_CONTROLLER_STATUS** value as an argument to set the status of a controller, and the [VDS_CONTROLLER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_controller_prop) structure includes a **VDS_CONTROLLER_STATUS** value as a member to indicate the current status.

If your application encounters a **VDS_CONTROLLER_STATUS** value that it does not recognize, it should display the controller status as unknown. It should not attempt to map the unrecognized controller status to another controller status.

**Note** Additional constants might be added to the **VDS_CONTROLLER_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_CONTROLLER_STATUS** enumeration constant.

## See also

[IVdsController::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-setstatus)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_CONTROLLER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_controller_prop)