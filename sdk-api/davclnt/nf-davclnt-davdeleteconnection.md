# DavDeleteConnection function

## Description

Closes a connection that was created by using the [DavAddConnection](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davaddconnection) function.

## Parameters

### `ConnectionHandle` [in]

A handle to an open connection that was created by using the [DavAddConnection](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davaddconnection) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)