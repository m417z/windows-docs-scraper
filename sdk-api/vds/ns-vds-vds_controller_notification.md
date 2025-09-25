# VDS_CONTROLLER_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of controller events.

## Members

### `ulEvent`

Determines the controller event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_CONTROLLER_ARRIVE**<br><br>103 | A controller is reported as physically present on the subsystem. The [VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status) value associated with this notification should be any value except **VDS_CS_REMOVED**. |
| **VDS_NF_CONTROLLER_DEPART**<br><br>104 | A controller was physically removed from the subsystem. The [VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status) value should be **VDS_CS_UNKNOWN** or **VDS_CS_REMOVED**. |
| **VDS_NF_CONTROLLER_MODIFY**<br><br>350 | A member of the [VDS_CONTROLLER_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_controller_prop) structure changed.<br><br>**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported. |
| **VDS_NF_CONTROLLER_REMOVED**<br><br>351 | A controller is physically present but not available for use. The [VDS_CONTROLLER_STATUS](https://learn.microsoft.com/windows/desktop/api/vds/ne-vds-vds_controller_status) value should be **VDS_CS_FAILED** (removed from use because of failure), **VDS_CS_ONLINE** (not failed, but not in use either), **VDS_CS_NOT_READY**, or **VDS_CS_UNKNOWN**.<br><br>**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported. |

### `controllerId`

The GUID of the controller that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this structure as a member.

An application can receive controller events by implementing the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

To get the controller object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsController::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdscontroller-getproperties) method to get the controller properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsController](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdscontroller)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)