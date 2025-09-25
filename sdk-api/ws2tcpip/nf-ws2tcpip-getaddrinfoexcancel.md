# GetAddrInfoExCancel function

## Description

The
**GetAddrInfoExCancel** function cancels an asynchronous operation by the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function.

## Parameters

### `lpHandle` [in]

The handle of the asynchronous operation to cancel. This is the handle returned in the *lpNameHandle* parameter by the [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) function.

## Return value

On success, **GetAddrInfoExCancel** returns **NO_ERROR** (0). Failure returns a nonzero Windows Sockets error code, as found in the
[Windows Sockets Error Codes](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

## Remarks

The **GetAddrInfoExCancel** function cancels an asynchronous [GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa) operation. The result is that the user's completion
mechanism, either a callback or an event, is immediately invoked. No results are returned,
and the error code returned for the **GetAddrInfoEx** asynchronous operation is set to **WSA_E_CANCELLED**. If the **GetAddrInfoEx** request has already completed or timed out,
or the handle is invalid, and **WSA_INVALID_HANDLE** will be returned by **GetAddrInfoExCancel** function.

Since many of the underlying operations (legacy name service providers, for example) are synchronous, these operations
will not actually be cancelled. These operations will continue running and consuming resources. Once the
last outstanding name service provider request has completed, the resources will be released.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)