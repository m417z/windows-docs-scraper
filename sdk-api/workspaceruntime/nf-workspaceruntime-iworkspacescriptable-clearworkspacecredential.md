# IWorkspaceScriptable::ClearWorkspaceCredential

## Description

Deletes the user credentials associated with the specified connection ID.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains a connection ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the connection ID has no active connections, it is removed from the credential store.

## See also

[IWorkspaceScriptable](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable)

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)