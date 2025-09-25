# AuthzFreeContext function

## Description

The **AuthzFreeContext** function frees all structures and memory associated with the client context. The list of handles for a client is freed in this call.

Starting with Windows Server 2012 and Windows 8, this function also frees the memory associated with device groups, user claims, and device claims.

## Parameters

### `hAuthzClientContext` [in]

The **AUTHZ_CLIENT_CONTEXT_HANDLE** structure to be freed.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)