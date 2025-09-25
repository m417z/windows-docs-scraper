# MODIFY_VHDSET_PARAMETERS structure

## Description

Contains VHD Set modification parameters, indicating how the VHD Set should be altered.

## Members

### `Version`

A value from the MODIFY_VHDSET_VERSION enumeration that determines that is the discriminant for the union.

### `SnapshotPath`

A structure with the following members.

### `SnapshotPath.SnapshotId`

The Snapshot Id in GUID format indicating which snapshot is to have its path altered in the VHD Set.

### `SnapshotPath.SnapshotFilePath`

The new file path for the Snapshot indicated by the SnapshotId field.

### `SnapshotId`

The Snapshot Id in GUID format indicating which snapshot is to be removed from the VHD Set file.

### `DefaultFilePath`

The file path for the default Snapshot of the Vhd Set.