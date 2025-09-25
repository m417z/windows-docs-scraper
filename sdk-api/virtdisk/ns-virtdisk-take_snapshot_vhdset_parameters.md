# TAKE_SNAPSHOT_VHDSET_PARAMETERS structure

## Description

Contains snapshot parameters, indicating information about the new snapshot to be created.

## Members

### `Version`

A value from the [TAKE_SNAPSHOT_VHDSET_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-take_snapshot_vhdset_version) enumeration that is the discriminant for the union.

### `Version1`

A structure with the following member.

### `Version1.SnapshotId`

The Id of the new Snapshot to be added to the Vhd Set.