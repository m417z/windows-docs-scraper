# MERGE_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains virtual hard disk (VHD) merge request parameters.

## Members

### `Version`

A [MERGE_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-merge_virtual_disk_version) enumeration
that specifies the version of the
**MERGE_VIRTUAL_DISK_PARAMETERS** structure
being passed to or from the VHD functions.

### `Version1`

This structure is used when the Version member is **MERGE_VIRTUAL_DISK_VERSION_1**
(1).

### `Version1.MergeDepth`

Depth of the merge request. This is the number of parent disks in the differencing chain to merge
together.

**Note** The RWDepth of the virtual disk must be greater than **MergeDepth**. For more
information, see
[OPEN_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-open_virtual_disk_parameters).

### `Version2`

This structure is used when the Version member is **MERGE_VIRTUAL_DISK_VERSION_2**
(2).

**Windows 7 and Windows Server 2008 R2:** This value is not supported until Windows 8 and Windows Server 2012.

### `Version2.MergeSourceDepth`

Depth from the leaf from which to begin the merge. The leaf is at depth 1.

### `Version2.MergeTargetDepth`

Depth from the leaf to target the merge. The leaf is at depth 1.

## Remarks

The depth of a merge request specified by the **MergeDepth** member is the number of
parent VHD image files in the differencing chain to be merged. For more information, see
[MergeVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-mergevirtualdisk).

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[MergeVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-mergevirtualdisk)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))