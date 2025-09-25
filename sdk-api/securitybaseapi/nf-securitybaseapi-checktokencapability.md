# CheckTokenCapability function

## Description

The **CheckTokenCapability** function checks the capabilities of a given token.

## Parameters

### `TokenHandle` [in, optional]

A handle to an access token. The handle must have TOKEN_QUERY access to the token. The token must be an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

If *TokenHandle* is **NULL**, **CheckTokenCapability** uses the impersonation token of the calling thread. If the thread is not impersonating, the function duplicates the thread's [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) to create an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

### `CapabilitySidToCheck` [in]

A pointer to a capability [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure. The **CheckTokenCapability** function checks the capabilities of this access token.

### `HasCapability` [out]

Receives the results of the check. If the access token has the capability, it returns **TRUE**, otherwise, it returns **FALSE**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)