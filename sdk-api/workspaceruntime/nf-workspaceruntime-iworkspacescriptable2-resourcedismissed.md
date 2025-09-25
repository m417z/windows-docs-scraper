# IWorkspaceScriptable2::ResourceDismissed

## Description

Alerts the user that a resource has been disabled or otherwise dismissed.

## Parameters

### `bstrWorkspaceId` [in]

String containing the ID of the workspace that contains the unavailable resource.

### `bstrWorkspaceFriendlyName` [in]

String containing the friendly name of the workspace that holds the unavailable resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)