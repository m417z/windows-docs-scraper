# PssDuplicateSnapshot function

## Description

Duplicates a snapshot handle from one process to another.

## Parameters

### `SourceProcessHandle` [in]

A handle to the source process from which the original snapshot was captured. The handle must have **PROCESS_VM_READ** and **PROCESS_DUP_HANDLE** rights.

### `SnapshotHandle` [in]

A handle to the snapshot to duplicate. This handle must be in the context of the source process.

### `TargetProcessHandle` [in]

A handle to the target process that receives the duplicate snapshot. The handle must have **PROCESS_VM_OPERATION**, **PROCESS_VM_WRITE**, and **PROCESS_DUP_HANDLE** rights.

### `TargetSnapshotHandle` [out]

A handle to the duplicate snapshot that this function creates, in the context of the target process.

### `Flags` [in, optional]

The duplication flags. For more information, see [PSS_DUPLICATE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_duplicate_flags).

## Return value

This function returns **ERROR_SUCCESS** on success or the following error code.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)