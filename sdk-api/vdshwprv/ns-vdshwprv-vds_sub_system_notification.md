# VDS_SUB_SYSTEM_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of subsystem events.

## Members

### `ulEvent`

Determines the subsystem event for which an application will be notified, as one of the following
values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_SUB_SYSTEM_ARRIVE**<br><br>101 | A new subsystem was connected to the server or network. |
| **VDS_NF_SUB_SYSTEM_DEPART**<br><br>102 | An existing subsystem was disconnected. |
| **VDS_NF_SUB_SYSTEM_MODIFY**<br><br>151 | A member of the [VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) structure was changed. |

### `subSystemId`

The subsystem's GUID.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive subsystem events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the
[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

To get the subsystem object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsSubSystem::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-getproperties) method or the [IVdsSubSystem2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem2-getproperties2) methodto get the subsystem properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)

[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop)