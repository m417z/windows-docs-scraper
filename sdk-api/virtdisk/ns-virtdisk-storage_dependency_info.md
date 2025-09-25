# STORAGE_DEPENDENCY_INFO structure

## Description

Contains virtual hard disk (VHD) storage dependency information.

## Members

### `Version`

A [STORAGE_DEPENDENCY_INFO_TYPE_1](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-storage_dependency_info_type_1) or [STORAGE_DEPENDENCY_INFO_TYPE_2](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-storage_dependency_info_type_2).

### `NumberEntries`

Number of entries returned in the following unioned members.

### `Version1Entries`

Variable-length array containing [STORAGE_DEPENDENCY_INFO_TYPE_1](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-storage_dependency_info_type_1) structures.

### `Version2Entries`

Variable-length array containing [STORAGE_DEPENDENCY_INFO_TYPE_2](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-storage_dependency_info_type_2) structures.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))