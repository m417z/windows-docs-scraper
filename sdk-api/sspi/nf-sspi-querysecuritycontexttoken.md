# QuerySecurityContextToken function

## Description

Obtains the [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) for a client [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) and uses it directly.

## Parameters

### `phContext` [in]

Handle of the context to query.

### `Token` [out]

Returned handle to the access token.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns a nonzero error code. One possible error code return is SEC_E_INVALID_HANDLE.

## Remarks

This function is called by a server application to control impersonation outside the SSPI layer, such as when launching a child process. The handle returned must be closed with [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) when the handle is no longer needed.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)