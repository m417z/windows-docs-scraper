# VDS_PARTITION_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of partition events.

## Members

### `ulEvent`

Determines the partition event for which an application will be notified, as one of the following
values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_PARTITION_ARRIVE**<br><br>11 | A new partition arrived. If the partition is a volume, the event also triggers a volume-arrival notification. |
| **VDS_NF_PARTITION_DEPART**<br><br>12 | An existing partition was removed. If the partition is a volume, the event also triggers a volume-departure notification. |
| **VDS_NF_PARTITION_MODIFY**<br><br>13 | A member was changed in the [VDS_PARTITION_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_partition_prop) structure for the partition. If the partition is a volume, and if the properties of the partition have changed, a **VDS_NF_VOLUME_MODIFY** notification is also sent. |

### `diskId`

The GUID of the disk containing the partition that triggered the event.

### `ullOffset`

The Partition offset.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive partition events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)