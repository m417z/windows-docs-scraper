# IDebugPlmClient3::ActivateAndDebugPlmBgTaskWide

## Description

 Launches and attaches to a Process Lifecycle Management (PLM) background task.

## Parameters

### `Server` [in]

The server of the task.

### `PackageFullName` [in]

A pointer to the package name.

### `BackgroundTaskId` [in]

A pointer to the task ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

If a debugger session is not already started, this method starts one.

## See also

[IDebugPlmClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugplmclient3)