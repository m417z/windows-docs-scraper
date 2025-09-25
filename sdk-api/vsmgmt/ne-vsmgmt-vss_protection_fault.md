# VSS_PROTECTION_FAULT enumeration

## Description

Defines the set of shadow copy protection faults. A shadow copy protection fault occurs when the VSS service is unable to perform a copy-on-write operation to the shadow copy storage area (also called the diff area).

## Constants

### `VSS_PROTECTION_FAULT_NONE:0`

No shadow copy protection fault has occurred.

### `VSS_PROTECTION_FAULT_DIFF_AREA_MISSING`

The volume that contains the shadow copy storage area could not be found. Usually this fault means that the volume has not yet arrived in the system.

### `VSS_PROTECTION_FAULT_IO_FAILURE_DURING_ONLINE`

The volume that contains the shadow copy storage area could not be brought online because an I/O failure occurred.

### `VSS_PROTECTION_FAULT_META_DATA_CORRUPTION`

The shadow copy metadata for the shadow copy storage area has been corrupted.

### `VSS_PROTECTION_FAULT_MEMORY_ALLOCATION_FAILURE`

A memory allocation failure occurred. This could be caused by a temporary low-memory condition that does not happen again after you clear the fault and restart the shadow copy operation.

### `VSS_PROTECTION_FAULT_MAPPED_MEMORY_FAILURE`

A memory mapping failure occurred. This fault could mean that the page file is too small, or it could be caused by a low-memory condition.

### `VSS_PROTECTION_FAULT_COW_READ_FAILURE`

A read failure occurred during the copy-on-write operation when data was being copied from the live volume to the shadow copy storage area volume.

### `VSS_PROTECTION_FAULT_COW_WRITE_FAILURE`

A read or write failure occurred during the copy-on-write operation when data was being copied from the live volume to the shadow copy storage area volume. One possible reason is that the shadow copy storage area volume has been removed from the system.

### `VSS_PROTECTION_FAULT_DIFF_AREA_FULL`

This failure means that either the shadow copy storage area is full or the shadow copy storage area volume is full. After clearing the protection fault, you can do one of the following:

* Delete unused shadow copy storage areas by calling the [IVssDifferentialSoftwareSnapshotMgmt3::DeleteUnusedDiffAreas](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-deleteunuseddiffareas) method.
* Increase the shadow copy storage area maximum size for the volume by calling the [IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize) method or the [IVssDifferentialSoftwareSnapshotMgmt2::ChangeDiffAreaMaximumSizeEx](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt2-changediffareamaximumsizeex) method.

### `VSS_PROTECTION_FAULT_GROW_TOO_SLOW`

The size of the shadow copy storage area could not be increased because there was no longer enough space on the shadow copy storage area volume.

### `VSS_PROTECTION_FAULT_GROW_FAILED`

The size of the shadow copy storage area could not be increased.

### `VSS_PROTECTION_FAULT_DESTROY_ALL_SNAPSHOTS`

An unexpected error occurred.

### `VSS_PROTECTION_FAULT_FILE_SYSTEM_FAILURE`

Either the shadow copy storage area files could not be opened or the shadow copy storage area volume could not be mounted because of a file system operation failure.

### `VSS_PROTECTION_FAULT_IO_FAILURE`

A read or write failure occurred on the shadow copy storage area volume.

### `VSS_PROTECTION_FAULT_DIFF_AREA_REMOVED`

The shadow copy storage area volume was removed from the system or could not be accessed for some other reason.

### `VSS_PROTECTION_FAULT_EXTERNAL_WRITER_TO_DIFF_AREA`

Another application attempted to write to the shadow copy storage area.

### `VSS_PROTECTION_FAULT_MOUNT_DURING_CLUSTER_OFFLINE`

## See also

[IVssDifferentialSoftwareSnapshotMgmt3::ClearVolumeProtectFault](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt3-clearvolumeprotectfault)

[VSS_PROTECTION_FAULT](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_protection_fault)

[VSS_VOLUME_PROTECTION_INFO](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_protection_info)