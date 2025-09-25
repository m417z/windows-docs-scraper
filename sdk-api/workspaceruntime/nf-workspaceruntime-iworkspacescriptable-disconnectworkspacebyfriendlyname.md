# IWorkspaceScriptable::DisconnectWorkspaceByFriendlyName

## Description

Disconnects all existing connections associated with the connection that has the specified name. It also deletes the corresponding entries from the RemoteApp and Desktop Connection store.

## Parameters

### `bstrWorkspaceFriendlyName` [in]

A string that contains the friendly name of the connection to disconnect.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceScriptable](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable)

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)