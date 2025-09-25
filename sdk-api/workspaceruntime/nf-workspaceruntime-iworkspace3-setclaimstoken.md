# IWorkspace3::SetClaimsToken

## Description

Sets the claims token.

## Parameters

### `bstrAccessToken` [in]

A string containing the access token.

### `ullAccessTokenExpiration` [in]

The time, in milliseconds, until the access token expires.

### `bstrRefreshToken` [in]

A string containing the refresh token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspace3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace3)