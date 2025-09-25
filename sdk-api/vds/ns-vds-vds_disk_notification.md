# VDS_DISK_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines
the details of disk events.

## Members

### `ulEvent`

Determines the disk event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_DISK_ARRIVE**<br><br>8 | A disk was inserted, or a RAID controller surfaced a LUN that is local to the host. |
| **VDS_NF_DISK_DEPART**<br><br>9 | A disk was removed, or a RAID controller unbound a LUN. |
| **VDS_NF_DISK_MODIFY**<br><br>10 | A member of the [VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop) structure changed, or an extent on a disk changed. |

### `diskId`

The GUID of the disk object that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive disk events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

To get the disk object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsDisk::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk-getproperties) method or the [IVdsDisk3::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsdisk3-getproperties2) method to get the disk properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsDisk](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsdisk)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DISK_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_disk_prop)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)