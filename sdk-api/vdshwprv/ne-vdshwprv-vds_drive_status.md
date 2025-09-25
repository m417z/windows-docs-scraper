# VDS_DRIVE_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a drive.

## Constants

### `VDS_DRS_UNKNOWN:0`

The status of the drive cannot be determined.

### `VDS_DRS_ONLINE:1`

The drive is available and in use. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value associated with this drive status can be any value except **VDS_H_FAILED**.

### `VDS_DRS_NOT_READY:2`

The drive is busy. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value except **VDS_H_FAILED**.

### `VDS_DRS_OFFLINE:4`

The drive is physically present but has been removed from its RAID group or storage pool. For example, if the drive was removed from its RAID group because it failed, the drive status should be **VDS_DRS_FAILED**. If the drive was removed as part of rebalancing storage, the drive status should be **VDS_DRS_OFFLINE**.

When this drive status is set, a **VDS_NF_DRIVE_REMOVED** notification is sent.

The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value can be any value.

### `VDS_DRS_FAILED:5`

The drive has failed. The [VDS_HEALTH](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_health) value should be **VDS_H_FAILED** or **VDS_H_FAILING**.

### `VDS_DRS_REMOVED:8`

The drive has been physically unplugged from the subsystem. When this status is set, a **VDS_NF_DRIVE_DEPART** notification is sent.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The [IVdsDrive::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-setstatus) method passes a **VDS_DRIVE_STATUS** value as an argument to set the status of a drive, and the [VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop) structure includes a **VDS_DRIVE_STATUS** value as a member to indicate the current status.

If your application encounters a **VDS_DRIVE_STATUS** value that it does not recognize, it should display the drive status as unknown. It should not attempt to map the unrecognized drive status to another drive status.

**Note** Additional constants might be added to the **VDS_DRIVE_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_DRIVE_STATUS** enumeration constant.

## See also

[IVdsDrive::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsdrive-setstatus)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_DRIVE_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_drive_prop)