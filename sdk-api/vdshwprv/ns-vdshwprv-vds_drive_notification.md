# VDS_DRIVE_NOTIFICATION structure

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the details of drive events.

## Members

### `ulEvent`

Determines the drive event for which an application will be notified, as one of the following values.

| Value | Meaning |
| --- | --- |
| **VDS_NF_DRIVE_ARRIVE**<br><br>105 | A drive is reported as physically present on the subsystem. The [VDS_DRIVE_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_status) value associated with this notification should be any value except **VDS_DRS_REMOVED**. |
| **VDS_NF_DRIVE_DEPART**<br><br>106 | A drive was physically removed from the subsystem. The [VDS_DRIVE_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_status) value should be **VDS_DRS_UNKNOWN** or **VDS_DRS_REMOVED**. |
| **VDS_NF_DRIVE_MODIFY**<br><br>107 | A member of the [VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop) structure changed, or an extent on a drive changed. |
| **VDS_NF_DRIVE_REMOVED**<br><br>354 | A drive that was in use as part of a RAID group or storage pool is no longer in use as part of the RAID group or storage pool. For example, if a RAID group drive was detected as failing and was replaced with a hot spare, the [VDS_DRIVE_STATUS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_drive_status) value should be **VDS_DRS_FAILED** (removed from use because of failure), **VDS_DRS_OFFLINE** (not failed, but not in use), **VDS_DRS_NOT_READY**, or **VDS_DRS_UNKNOWN**. If the drive was removed as part of rebalancing the storage, the drive is not failing, and the **VDS_DRIVE_STATUS** value should be **VDS_DRS_OFFLINE** or **VDS_DRS_NOT_READY**.<br><br>**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported. |

### `driveId`

The GUID of the drive that triggered the event.

## Remarks

The [VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification) structure includes this structure as a member.

An application can receive drive events by implementing the [IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink) interface and passing the interface pointer as an argument to the [IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise) method.

To get the drive object, use the [IVdsService::GetObject](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-getobject) method. You can then use the [IVdsDrive::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-getproperties) method or the [IVdsDrive2::GetProperties2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive2-getproperties2) method to get the drive properties.

## See also

[IVdsAdviseSink](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsadvisesink)

[IVdsService::Advise](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsservice-advise)

[VDS Structures](https://learn.microsoft.com/windows/desktop/VDS/vds-structures)

[VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop)

[VDS_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_notification)