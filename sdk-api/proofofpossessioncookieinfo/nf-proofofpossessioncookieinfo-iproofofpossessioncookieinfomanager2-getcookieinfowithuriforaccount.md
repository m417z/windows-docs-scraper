## Description

Retrieves cookie information corresponding to the supplied [WebAccount](https://learn.microsoft.com/uwp/api/windows.security.credentials.webaccount) and URI. A case-sensitive string search is performed on the supplied URI. You should free the returned array by using [FreeProofOfPossessionCookieInfoArray](https://learn.microsoft.com/windows/win32/api/proofofpossessioncookieinfo/nf-proofofpossessioncookieinfo-freeproofofpossessioncookieinfoarray).

## Parameters

### `webAccount`

A [WebAccount](https://learn.microsoft.com/uwp/api/windows.security.credentials.webaccount) as **IInspectable**. You can obtain a **WebAccount** object by calling methods on [WebAuthenticationCoreManager](https://learn.microsoft.com/uwp/api/windows.security.authentication.web.core.webauthenticationcoremanager) suchas **FindAccountAsync** and **FindAllAccountsAsync**.

### `uri`

The URI to retrieve cookie information for. The URI is case-sensitive.

### `cookieInfoCount`

The number of cookies found. `*cookieInfoCount` contains the number of elements in *cookieInfo*.

### `cookieInfo`

A returned array of cookie information objects. You should free the returned array by using [FreeProofOfPossessionCookieInfoArray](https://learn.microsoft.com/windows/win32/api/proofofpossessioncookieinfo/nf-proofofpossessioncookieinfo-freeproofofpossessioncookieinfoarray).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProofOfPossessionCookieInfoManager2](https://learn.microsoft.com/windows/win32/api/proofofpossessioncookieinfo/nn-proofofpossessioncookieinfo-iproofofpossessioncookieinfomanager2)