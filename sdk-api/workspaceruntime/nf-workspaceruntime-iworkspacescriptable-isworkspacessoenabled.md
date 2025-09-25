# IWorkspaceScriptable::IsWorkspaceSSOEnabled

## Description

Determines whether single sign on (SSO) is enabled for RemoteApp and Desktop Connection.

## Parameters

### `pbSSOEnabled` [out, retval]

A pointer to a **VARIANT_BOOL** variable to receive whether SSO is enabled. This value is **VARIANT_TRUE** if SSO is enabled; otherwise, **VARIANT_FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceScriptable](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable)

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)