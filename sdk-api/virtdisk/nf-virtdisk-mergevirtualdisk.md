# MergeVirtualDisk function

## Description

Merges a child virtual hard disk (VHD) in a differencing chain with one or more parent virtual disks in the chain.

## Parameters

### `VirtualDiskHandle` [in]

A handle to the open virtual disk, which must have been opened using the **VIRTUAL_DISK_ACCESS_METAOPS** flag. For information on how to open a virtual disk, see the [OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk) function.

### `Flags` [in]

Must be the **MERGE_VIRTUAL_DISK_FLAG_NONE** value of the [MERGE_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-merge_virtual_disk_flag) enumeration.

### `Parameters` [in]

A pointer to a valid [MERGE_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-merge_virtual_disk_parameters) structure that contains merge parameter data.

### `Overlapped` [in, optional]

An optional pointer to a valid [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure if [asynchronous](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-overlapped-input-and-output) operation is desired.

## Return value

Status of the request.

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error code. For more information, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**Note** All occurrences of the term *disk* in this section refer to virtual disks. The term *backing store* refers to the physical disk storage where the VHD image file or files reside.

The **MergeVirtualDisk** function updates all data blocks in one or more parent disks with the data blocks from the child disk referred to by the *VirtualDiskHandle* parameter. This is essentially a copy operation.

Merging a disk requires that the affected disks be detached during the operation.

The caller must have READ|WRITE access to the backing store for the affected disks.

The RWDepth of the disk must be greater than the merge depth specified by the [OPEN_VIRTUAL_DISK_PARAMETERS](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-open_virtual_disk_parameters).

Merge modifies the parent disk being merged into, therefore any other differencing disks dependent on that parent will no longer be valid.

The parent disk being merged into is changed to represent the same data as was held in the child differencing disk on which the merge is performed.

Any pre-existing data in the parent disk being merged into is overwritten.

If a merge operation is interrupted, the child disk is still usable. The **MergeVirtualDisk** function can be rerun to finish the merge.

The depth of a merge request is the number of parent VHD image files in the differencing chain to be merged. For example, if the **MergeDepth** member has a value of 1, the data blocks from the specified differencing disk are moved into its parent. If the *MergeDepth* member has a value of 2 and the specified differencing disk's parent is also a differencing disk (meaning there is a third disk in the chain), then the data blocks from both the first and second disks are moved into the third disk (with blocks from the first disk taking precedence over blocks from the second during the final operation).

Upon completion, the affected child disks are no longer considered valid, and any future operations on them will have unsupported results. In the previous example, upon successful completion of the merge, the third disk is valid and the first and second are not. The **MergeVirtualDisk** function will not delete any disks that are not valid, or perform any automatic differencing relationship reconnections. This must be explicitly done by the caller.

If a merge operation is performed on a nonleaf node of a differencing disk, it is the responsibility of the caller to fix up the parent information for the child nodes of the disk that is being merged.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))