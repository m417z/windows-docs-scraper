# IWorkspace3::GetClaimsToken2

## Description

Retrieves a claims token.

## Parameters

### `bstrClaimsHint` [in]

String containing the claims hint.

### `bstrUserHint` [in]

String containing the user hint.

### `claimCookie` [in]

The claim cookie.

### `hwndCredUiParent` [in]

Handle of the parent UI element the request came from.

### `rectCredUiParent` [in]

Pointer to a RECT structure that contains the X and Y coordinates of the parent UI.

### `pbstrAccessToken` [out, retval]

On success, return a pointer to a string containing the access token.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspace3](https://learn.microsoft.com/windows/desktop/api/workspaceruntime/nn-workspaceruntime-iworkspace3)