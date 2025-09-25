# IWorkspaceScriptable::IsWorkspaceCredentialSpecified

## Description

Determines whether user credentials exist for the specified connection ID.

## Parameters

### `bstrWorkspaceId` [in]

A string that contains the connection ID.

### `bCountUnauthenticatedCredentials` [in]

**VARIANT_TRUE** to specify that the *pbCredExist* parameter should return **VARIANT_TRUE** if credentials (authenticated or unauthenticated) exist for the connection ID specified in the *bstrWorkspaceId* parameter. **VARIANT_FALSE** to specify that the *pbCredExist* parameter should return **VARIANT_TRUE** only if authenticated credentials exist for the connection ID specified in the *bstrWorkspaceId* parameter.

### `pbCredExist` [out, retval]

A pointer to a **VARIANT_BOOL** variable to receive whether credentials exist for the connection ID specified in the *bstrWorkspaceId* parameter. This value is **VARIANT_TRUE** if credentials exist; otherwise, **VARIANT_FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceScriptable](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable)

[IWorkspaceScriptable2](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable2)

[IWorkspaceScriptable3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspacescriptable3)