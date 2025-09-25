# IWorkspaceRegistration2::AddResourceEx

## Description

Not implemented.

Adds a resource to the connection in RemoteApp and Desktop Connection.

## Parameters

### `pUnk` [in]

A pointer to the [IWorkspaceClientExt](https://learn.microsoft.com/windows/desktop/api/workspaceruntimeclientext/nn-workspaceruntimeclientext-iworkspaceclientext) object that called this method.

### `bstrEventLogUploadAddress` [in]

TBD

### `pdwCookie` [out]

A pointer to a **DWORD** variable to receive the connection cookie for a new resource.

### `correlationId` [in]

TBD

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceRegistration2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspaceregistration2)