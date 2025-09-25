# VDS_SUB_SYSTEM_STATUS enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the
set of object status values for a subsystem.

## Constants

### `VDS_SSS_UNKNOWN:0`

This value is reserved.

### `VDS_SSS_ONLINE:1`

The subsystem is working properly.

### `VDS_SSS_NOT_READY:2`

The subsystem is initializing and not yet ready to work.

### `VDS_SSS_OFFLINE:4`

The subsystem is unavailable. This value indicates either that the subsystem is disconnected or that it has
failed so severely that it appears to be disconnected.

### `VDS_SSS_FAILED:5`

The subsystem has failed. This value indicates that the subsystem is not merely
disconnected but rather that it has failed.

### `VDS_SSS_PARTIALLY_MANAGED:9`

The subsystem is operating in a degraded state. This means that one or more of the subsystem's subcomponents, such as disk drives or controllers, are in a failed state.

**Windows Server 2008, Windows Vista and Windows Server 2003:** This value is not supported.

## Remarks

The [IVdsSubSystem::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-setstatus) method passes a **VDS_SUB_SYSTEM_STATUS**
value as an argument to set the status of a subsystem, and the
[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop) structure includes a **VDS_SUB_SYSTEM_STATUS** value
as a member to indicate the current status.

**Note** Additional constants might be added to the **VDS_SUB_SYSTEM_STATUS** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_SUB_SYSTEM_STATUS** enumeration constant.

## See also

[IVdsSubSystem::SetStatus](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-setstatus)

[VDS_SUB_SYSTEM_PROP](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_sub_system_prop)