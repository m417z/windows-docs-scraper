# IWorkspaceScriptable::OnAuthenticated

## Description

Marks the authentication of user credentials for the connection ID, and subsequently shows the connect notification in the taskbar notification area. The **OnAuthenticated** method also resets the credential time-out.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains the connection ID.

### `bstrUserName` [in]

A string that contains a user name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceScriptable](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable)

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)