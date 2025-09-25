# VDS_VDISK_STATE enumeration

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Defines the set of status values for a virtual disk object.

## Constants

### `VDS_VST_UNKNOWN:0`

VDS was not able to identify the virtual disk's current status.

### `VDS_VST_ADDED`

The virtual disk is has been added to the VDS virtual disk provider.

### `VDS_VST_OPEN`

A handle has been opened to the virtual disk file.

### `VDS_VST_ATTACH_PENDING`

The virtual disk is being attached

### `VDS_VST_ATTACHED_NOT_OPEN`

The virtual disk is attached, but a handle has not been opened to the virtual disk file.

### `VDS_VST_ATTACHED`

The virtual disk is attached and a handle has been opened to the virtual disk file.

### `VDS_VST_DETACH_PENDING`

The virtual disk is being detached and a handle is being opened to the virtual disk file.

### `VDS_VST_COMPACTING`

The virtual disk is being compacted.

### `VDS_VST_MERGING`

The virtual disk is being merged.

### `VDS_VST_EXPANDING`

The virtual disk is being expanded.

### `VDS_VST_DELETED`

The virtual disk has been deleted.

### `VDS_VST_MAX`

This value is reserved for system use.

## Remarks

**Note** Additional constants might be added to the **VDS_VDISK_STATE** enumeration in future Windows versions. For this reason, your application must be designed to gracefully handle an unrecognized **VDS_VDISK_STATE** enumeration constant.

## See also

[VDS Enumerations](https://learn.microsoft.com/windows/desktop/VDS/vds-enumerations)