# PssFreeSnapshot function

## Description

Frees a snapshot.

## Parameters

### `ProcessHandle` [in]

A handle to the process that contains the snapshot. The handle must have **PROCESS_VM_READ**, **PROCESS_VM_OPERATION**, and **PROCESS_DUP_HANDLE** rights. If the snapshot was captured from the current process, or duplicated into the current process, then pass in the result of [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess).

### `SnapshotHandle` [in]

A handle to the snapshot to free.

## Return value

This function returns **ERROR_SUCCESS** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The specified handle is invalid. |
| **ERROR_NOT_SUPPORTED** | The remote snapshot was not created with **PSS_CREATE_USE_VM_ALLOCATIONS**. |

All error codes are defined in winerror.h. Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the **FORMAT_MESSAGE_FROM_SYSTEM** flag to get a message for an error code.

## Remarks

This API can free snapshot handles in the context of either the local or remote processes. If the snapshot was captured in the local process with [PssCaptureSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psscapturesnapshot), or duplicated into the local process with [PssDuplicateSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-pssduplicatesnapshot), then specify the result of [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) as the process handle. If the snapshot is in the context of a remote process (for example, duplicated into the remote process), then specify the handle to that process.

The operation does not protect against concurrent access to the same descriptor.

For remote process frees, only snapshot handles that were created with **PSS_CREATE_USE_VM_ALLOCATIONS** or duplicated remotely can be freed by this API.

The behavior of this routine on a descriptor that has already been freed is undefined.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)