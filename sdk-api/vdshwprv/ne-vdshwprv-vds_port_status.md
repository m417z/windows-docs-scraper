# VDS_PORT_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a port.

## Constants

### `VDS_PRS_UNKNOWN:0`

The status of the port cannot be determined.

### `VDS_PRS_ONLINE:1`

The port is physically present and in use. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value associated with this port status can be any value except **VDS_H_FAILED**.

### `VDS_PRS_NOT_READY:2`

The port is busy. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value except **VDS_H_FAILED**.

### `VDS_PRS_OFFLINE:4`

Either the port or its controller is physically present but not available for use. For example, the port or its controller has been set to the inactive state. When this status is set, a **VDS_NF_PORT_REMOVED** notification is sent. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value.

### `VDS_PRS_FAILED:5`

The port has failed. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value should be **VDS_H_FAILED** or **VDS_H_FAILING**.

### `VDS_PRS_REMOVED:8`

The port's controller has been physically removed from the subsystem. When this status is set, a **VDS_NF_PORT_DEPART** notification is sent.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The [VDS_PORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_port_prop) structure includes a **VDS_PORT_STATUS** value as a member to indicate the current status of a port.

If your application encounters a **VDS_PORT_STATUS** value that it does not recognize, it should display the port status as unknown. It should not attempt to map the unrecognized port status to another port status.

**Note** Additional constants might be added to the **VDS_PORT_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_PORT_STATUS** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_PORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_port_prop)