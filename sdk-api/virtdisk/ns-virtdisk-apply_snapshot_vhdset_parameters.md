# APPLY_SNAPSHOT_VHDSET_PARAMETERS structure

## Description

Contains snapshot parameters, indicating information about the new snapshot to be applied.

## Members

### `Version`

An [APPLY_SNAPSHOT_VHDSET_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-apply_snapshot_vhdset_version)
enumeration that specifies the version of the
**APPLY_SNAPSHOT_VHDSET_PARAMETERS** structure being passed to or from the VHD functions.

### `Version1`

A structure with the following member.

### `Version1.SnapshotId`

The ID of the new snapshot to be applied to the VHD set.

### `Version1.LeafSnapshotId`

Indicates whether the current default leaf data should be retained as part of the apply operation. When a zero GUID is specified, the apply operation will discard the current default leaf data. When a non-zero GUID is specified, the apply operation will convert the default leaf data into a writable snapshot with the specified ID.