# VDS_LUN_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of object status values for a LUN.

## Constants

### `VDS_LS_UNKNOWN:0`

This value is reserved.

### `VDS_LS_ONLINE:1`

The LUN is available.

### `VDS_LS_NOT_READY:2`

The LUN is busy.

### `VDS_LS_OFFLINE:4`

The LUN is unavailable.

### `VDS_LS_FAILED:5`

The LUN has failed.

## Remarks

The [IVdsLun::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-setstatus) method passes a **VDS_LUN_STATUS** value as an argument to set the status of a LUN, and the [VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop) structure includes a **VDS_LUN_STATUS** value as a member to indicate the current status.

**Note** Additional constants might be added to the **VDS_LUN_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_LUN_STATUS** enumeration constant.

## See also

[IVdsLun::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-setstatus)

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)

[VDS_LUN_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_lun_prop)