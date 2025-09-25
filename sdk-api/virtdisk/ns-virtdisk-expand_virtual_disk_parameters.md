# EXPAND_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains virtual disk expansion request parameters.

## Members

### `Version`

An [EXPAND_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-expand_virtual_disk_version)
enumeration value that specifies the version of the
**EXPAND_VIRTUAL_DISK_PARAMETERS** structure
being passed to or from the virtual disk functions.

### `Version1`

This structure is used if the **Version** member is
**EXPAND_VIRTUAL_DISK_VERSION_1** (1).

### `Version1.NewSize`

New size, in bytes, for the expansion request.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))