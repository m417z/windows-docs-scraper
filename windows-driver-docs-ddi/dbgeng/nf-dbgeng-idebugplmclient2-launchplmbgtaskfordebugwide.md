# IDebugPlmClient2::LaunchPlmBgTaskForDebugWide

## Description

Launches a suspended Process Lifecycle Management (PLM) background task.

## Parameters

### `Server` [in]

The server of the task.

### `Timeout` [in]

A time-out value.

### `PackageFullName` [in]

A pointer to the package name.

### `BackgroundTaskId` [in]

A pointer to the task ID.

### `ProcessId` [out]

A pointer to a process ID output.

### `ThreadId` [out]

A pointer to a thread ID output.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugPlmClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugplmclient2)