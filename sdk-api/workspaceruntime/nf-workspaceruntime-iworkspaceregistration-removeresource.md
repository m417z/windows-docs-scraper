# IWorkspaceRegistration::RemoveResource

## Description

Notifies the RemoteApp and Desktop Connection runtime that the client is disconnecting the connection.

## Parameters

### `dwCookieConnection` [in]

A **DWORD** value that contains a connection cookie returned by the [AddResource](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nf-workspaceruntime-iworkspaceregistration-addresource) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceRegistration](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspaceregistration)

[IWorkspaceRegistration2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspaceregistration2)