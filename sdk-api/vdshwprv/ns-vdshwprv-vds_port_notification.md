# VDS_PORT_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the details of controller port events.

## Members

### `ulEvent`

Determines the controller port event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_PORT_ARRIVE**<br><br>121 | A controller port is reported as physically present on the subsystem. The [VDS_PORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_port_status) value associated with this notification should be any value except **VDS_PRS_REMOVED**. |
| **VDS_NF_PORT_DEPART**<br><br>122 | A controller, and therefore its port, were physically unplugged from the subsystem. The [VDS_PORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_port_status) value should be **VDS_PRS_UNKNOWN** or **VDS_PRS_REMOVED**. |
| **VDS_NF_PORT_MODIFY**<br><br>352 | A member of the [VDS_PORT_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_port_prop) structure changed.<br><br>**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported. |
| **VDS_NF_PORT_REMOVED**<br><br>353 | A controller port is physically present but not available for use. For example, either the controller or the port itself is set to inactive. The [VDS_PORT_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_port_status) value should be **VDS_PRS_FAILED** (removed from use because of failure), **VDS_PRS_OFFLINE** (not failed, but not in use either), **VDS_PRS_NOT_READY**, or **VDS_PRS_UNKNOWN**.<br><br>**Windows Server 2008, Windows Vista and Windows Server 2003 R2:** This value is not supported. |

### `portId`

The **VDS_OBJECT_ID** of the controller port that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive disk events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

To get the port object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsControllerPort::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontrollerport-getproperties) method to get the port properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsControllerPort](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdscontrollerport)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)