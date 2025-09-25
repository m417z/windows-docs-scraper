# VDS_PORTAL_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of iSCSI portal events.

## Members

### `ulEvent`

Determines the iSCSI portal event for which an application will be notified, as one of the following
values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_PORTAL_ARRIVE**<br><br>123 | An iSCSI portal has been created. |
| **VDS_NF_PORTAL_DEPART**<br><br>124 | An existing iSCSI portal has been removed. |
| **VDS_NF_PORTAL_MODIFY**<br><br>125 | An existing iSCSI portal has changed. An example of change that triggers this notification would be changes to the [VDS_ISCSI_PORTAL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_portal_prop) structure. Applications are responsible for determining the nature of any changes. |

### `portalId`

The **VDS_OBJECT_ID** of the iSCSI portal that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive disk events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

To get the portal object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsIscsiPortal::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsiscsiportal-getproperties) method to get the portal properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsIscsiPortal](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsiscsiportal)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_ISCSI_PORTAL_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_iscsi_portal_prop)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)