# IXblIdpAuthManager::GetTokenAndSignatureWithTokenResult

## Description

Reserved for Microsoft use.

## Parameters

### `msaAccountId`

Type: **__RPC__in_opt_string**

### `appSid`

Type: **__RPC__in_string**

### `msaTarget`

Type: **__RPC__in_string**

### `msaPolicy`

Type: **__RPC__in_string**

### `httpMethod`

Type: **__RPC__in_string**

### `uri`

Type: **__RPC__in_string**

### `headers`

Type: **__RPC__in_opt_string**

### `body`

Type: **BYTE***

### `bodySize`

Type: **__RPC__in_ecount_full_opt**

### `forceRefresh`

Type: **BOOL**

### `result`

Type: **IXblIdpAuthTokenResult****

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IXblIdpAuthManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/xblidpauthmanager/nn-xblidpauthmanager-ixblidpauthmanager)