# WSACancelAsyncRequest function

## Description

The
**WSACancelAsyncRequest** function cancels an incomplete asynchronous operation.

## Parameters

### `hAsyncTaskHandle` [in]

Handle that specifies the asynchronous operation to be canceled.

## Return value

The value returned by
**WSACancelAsyncRequest** is zero if the operation was successfully canceled. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Indicates that the specified asynchronous task handle was invalid. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The asynchronous routine being canceled has already completed. |

**Note** It is unclear whether the application can usefully distinguish between
[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), since in both cases the error indicates that there is no asynchronous operation in progress with the indicated handle. (Trivial exception: zero is always an invalid asynchronous task handle.) The Windows Sockets specification does not prescribe how a conformant Windows Sockets provider should distinguish between the two cases. For maximum portability, a Windows Sockets application should treat the two errors as equivalent.

## Remarks

The
**WSACancelAsyncRequest** function is used to cancel an asynchronous operation that was initiated by one of the **WSAAsyncGetXByY** functions such as
[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname). The operation to be canceled is identified by the *hAsyncTaskHandle* parameter, which should be set to the asynchronous task handle as returned by the initiating **WSAAsyncGetXByY** function.

An attempt to cancel an existing asynchronous **WSAAsyncGetXByY** operation can fail with an error code of
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) for two reasons. First, the original operation has already completed and the application has dealt with the resultant message. Second, the original operation has already completed but the resultant message is still waiting in the application window queue.

## See also

[WSAAsyncGetHostByAddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyaddr)

[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname)

[WSAAsyncGetProtoByName](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetprotobyname)

[WSAAsyncGetProtoByNumber](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetprotobynumber)

[WSAAsyncGetServByName](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetservbyname)

[WSAAsyncGetServByPort](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncgetservbyport)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)