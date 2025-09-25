# VDS_LUN_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the details of a LUN notification.

## Members

### `ulEvent`

Determines the LUN event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| ****VDS_NF_LUN_ARRIVE****<br><br>108 | A new LUN has been created. |
| ****VDS_NF_LUN_DEPART****<br><br>109 | An existing LUN has been deleted. |
| ****VDS_NF_LUN_MODIFY****<br><br>110 | A member was changed in the [VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop) structure for an external LUN. Examples of changes that trigger this notification include changes to the **VDS_LUN_PROP** structure and the addition of a plex to the LUN. Applications are responsible for determining the precise nature of the change. |

### `LunId`

The GUID of the LUN.

## Remarks

This structure is included as a member in the
[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure.

An application can receive LUN events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the
[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

To get the LUN object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method to get the LUN properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)