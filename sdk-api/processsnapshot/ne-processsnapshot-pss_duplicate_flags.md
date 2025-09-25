# PSS_DUPLICATE_FLAGS enumeration

## Description

Duplication flags for use by [PssDuplicateSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssduplicatesnapshot).

## Constants

### `PSS_DUPLICATE_NONE:0x00`

No flag.

### `PSS_DUPLICATE_CLOSE_SOURCE:0x01`

Free the source handle. This will only succeed if you set the **PSS_CREATE_USE_VM_ALLOCATIONS** flag when you called [PssCaptureSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psscapturesnapshot) to create the snapshot and handle. The handle will be freed even if duplication fails.
The close operation does not protect against concurrent access to the same descriptor.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)