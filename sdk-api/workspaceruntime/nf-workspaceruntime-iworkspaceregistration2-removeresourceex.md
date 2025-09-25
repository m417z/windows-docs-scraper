# IWorkspaceRegistration2::RemoveResourceEx

## Description

Not implemented.

Notifies the RemoteApp and Desktop Connection runtime that the client is disconnecting the connection.

## Parameters

### `dwCookieConnection` [in]

A **DWORD** value that contains a connection cookie returned by the [AddResourceEx](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nf-workspaceruntime-iworkspaceregistration2-addresourceex) method.

### `correlationId` [in]

TBD

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceRegistration2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspaceregistration2)