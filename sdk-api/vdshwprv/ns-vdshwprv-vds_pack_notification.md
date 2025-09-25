# VDS_PACK_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the details of pack events.

## Members

### `ulEvent`

Determines the pack event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_PACK_ARRIVE**<br><br>1 | A new pack arrived. |
| **VDS_NF_PACK_DEPART**<br><br>2 | An existing pack was removed. |
| **VDS_NF_PACK_MODIFY**<br><br>3 | A member of the [VDS_PACK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_pack_prop) structure for the pack was changed. |

### `packId`

The GUID for the pack that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive pack events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the
[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

To get the pack object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsPack::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdspack-getproperties) method to get the pack properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)