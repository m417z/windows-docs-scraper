# IDebugPlmClient3::LaunchAndDebugPlmAppWide

## Description

 Launches and attaches to a Process Lifecycle Management (PLM) application.

## Parameters

### `Server` [in]

The server of the application.

### `PackageFullName` [in]

A pointer to the package name.

### `AppName` [in]

A pointer to the application name.

### `Arguments` [in]

A pointer to an arguments string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

If a debugger session is not already started, this method starts one.

## See also

[IDebugPlmClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugplmclient3)