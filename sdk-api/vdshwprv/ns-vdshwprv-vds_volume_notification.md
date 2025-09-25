# VDS_VOLUME_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of volume events.

## Members

### `ulEvent`

Determines the volume event for which an application will be notified, as one of the following
values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_VOLUME_ARRIVE**<br><br>4 | A new volume arrived. |
| **VDS_NF_VOLUME_DEPART**<br><br>5 | An existing volume was removed. |
| **VDS_NF_VOLUME_MODIFY**<br><br>6 | A member of the [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure changed. This value can also indicate a change in one of the plexes associated with the volume, such as the addition, removal, or repair of a plex. |
| **VDS_NF_VOLUME_REBUILDING_PROGRESS**<br><br>7 | A volume is being rebuilt. |

### `volumeId`

The **VDS_OBJECT_ID** of the volume that triggered the event.

### `plexId`

The **VDS_OBJECT_ID** of a volume plex. VDS applies this identifier during the
rebuild operation, which can execute on multiple plexes at different rates.

### `ulPercentCompleted`

The degree to which the operation is complete.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this
structure as a member.

An application can receive volume events by implementing the
[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface
pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)
method.

To get the volume object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsVolume::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-getproperties) method or the [IVdsVolume2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume2-getproperties2) method to get the volume properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)

[VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop)