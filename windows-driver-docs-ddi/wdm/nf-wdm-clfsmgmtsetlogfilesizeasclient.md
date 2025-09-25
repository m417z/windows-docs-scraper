# ClfsMgmtSetLogFileSizeAsClient function

## Description

The **ClfsMgmtSetLogFileSizeAsClient** routine sets the log file size by adding containers to a client log or deleting containers from a client log.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the Common Log File System (CLFS) log, or a stream within the log, to which containers are being added or deleted. The value of this parameter is obtained through a call to the [ClfsCreateLogFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatelogfile) routine.

### `ClientCookie` [in, optional]

A pointer to a client-supplied cookie. The value of this parameter should be the **CLFS_MGMT_CLIENT** structure that is obtained through a call to the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine.

### `NewSizeInContainers` [in]

The desired size of the log, expressed in the number of containers. There can be at most 1,024 containers for a log file.

### `ResultingSizeInContainers` [out, optional]

The actual size of the log, expressed in the number of containers.

### `CompletionRoutine` [in, optional]

 Not used.

### `CompletionRoutineData` [in, optional]

 Not used.

## Return value

The **ClfsMgmtSetLogFileSizeAsClient** routine returns an NTSTATUS value.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The log file size has been set. |
| **STATUS_INVALID_PARAMETER_1** | The value of the *LogFile* parameter is **NULL**, or the contents of the *NewSizeInContainers* parameter is 1. |
| **STATUS_INVALID_PARAMETER_2** | The value of the *NewSizeInContainers* parameter is **NULL**. |
| **STATUS_LOG_POLICY_INVALID** | The installed set of policies on the log is invalid. This might be due to an invalid [ClfsMgmtPolicyAutoShrink](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb540325(v=vs.85)) policy or [ClfsMgmtPolicyMaximumSize](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb540328(v=vs.85)) policy. |
| **STATUS_COULD_NOT_RESIZE_LOG** | CLFS management could not delete enough containers to reach the value in *NewSizeInContainers*. |
| **STATUS_LOG_POLICY_CONFLICT** | A policy on the specified log prevented the operation from completing. This may occur if CLFS management could not add enough containers to the log to reach the value in *NewSizeInContainers*. This might be due to a conflict with a policy that the client set. |

This routine might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## See also

[CLFS Management Library Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)