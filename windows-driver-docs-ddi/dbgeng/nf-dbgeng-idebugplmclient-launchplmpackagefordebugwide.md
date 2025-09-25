# IDebugPlmClient::LaunchPlmPackageForDebugWide

## Description

Launches a suspended Process Lifecycle Management (PLM) application.

## Parameters

### `Server` [in]

The server of the application.

### `Timeout` [in]

A time-out value.

### `PackageFullName` [in]

A pointer to the package name.

### `AppName` [in]

A pointer to the application name.

### `Arguments` [in, optional]

A pointer an arguments string.

### `ProcessId` [out]

A pointer to a process ID output.

### `ThreadId` [out]

A pointer to a thread ID output.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugPlmClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugplmclient)