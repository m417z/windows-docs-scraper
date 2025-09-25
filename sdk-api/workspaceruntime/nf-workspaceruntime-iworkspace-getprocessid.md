# IWorkspace::GetProcessId

## Description

Retrieves the process ID of the current connection in RemoteApp and Desktop Connection.

## Parameters

### `pulProcessId` [out, retval]

A pointer to a **ULONG** variable to receive the process ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspace](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace)

[IWorkspace2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace2)

[IWorkspace3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace3)