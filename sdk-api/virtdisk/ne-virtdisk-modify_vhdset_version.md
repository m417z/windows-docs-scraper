# MODIFY_VHDSET_VERSION enumeration

## Description

Contains the version of the [MODIFY_VHDSET_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-modify_vhdset_parameters) structure to use in calls to virtual disk functions.

## Constants

### `MODIFY_VHDSET_UNSPECIFIED:0`

Not Supported.

### `MODIFY_VHDSET_SNAPSHOT_PATH:1`

The **SnapshotPath** member structure will be used.

### `MODIFY_VHDSET_REMOVE_SNAPSHOT:2`

The **SnapshotId** member structure will be used.

### `MODIFY_VHDSET_DEFAULT_SNAPSHOT_PATH:3`

The **DefaultFilePath** member structure will be used