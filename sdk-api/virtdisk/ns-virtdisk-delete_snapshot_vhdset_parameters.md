# DELETE_SNAPSHOT_VHDSET_PARAMETERS structure

## Description

Contains snapshot deletion parameters, designating which snapshot to delete from the VHD Set.

## Members

### `Version`

A value from the [DELETE_SNAPSHOT_VHDSET_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-delete_snapshot_vhdset_version) enumeration that is the discriminant for the union.

### `Version1`

A structure with the following member.

### `Version1.SnapshotId`

The Snapshot Id in GUID format indicating which snapshot is to be deleted from the VHD Set.