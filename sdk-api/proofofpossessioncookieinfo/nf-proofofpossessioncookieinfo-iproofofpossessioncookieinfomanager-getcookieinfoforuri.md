## Description

Retrieves cookie information for the supplied URI to be used for proof of possession cookies.

## Parameters

### `uri` [in]

The URI to retrieve cookie information for. The URI is case-sensitive.

### `cookieInfoCount` [out]

The number of cookies found. `*cookieInfoCount` contains the number of elements in *cookieInfo*.

### `cookieInfo` [out]

A returned array of cookie information objects. You should free the returned array by using [FreeProofOfPossessionCookieInfoArray](https://learn.microsoft.com/windows/win32/api/proofofpossessioncookieinfo/nf-proofofpossessioncookieinfo-freeproofofpossessioncookieinfoarray).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProofOfPossessionCookieInfoManager](https://learn.microsoft.com/windows/win32/api/proofofpossessioncookieinfo/nn-proofofpossessioncookieinfo-iproofofpossessioncookieinfomanager)