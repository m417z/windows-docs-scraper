# LPNSPV2STARTUP callback function

## Description

The
**NSPv2Startup** function notifies a namespace service provider version-2 (NSPv2) provider that a new client process is to begin using the provider.

## Parameters

### `lpProviderId` [in]

A pointer to the GUID of the specific namespace provider to notify.

### `ppvClientSessionArg` [in]

A pointer to the client session.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (that is, 1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to initialize the service. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Service is unknown. The service cannot be found in the specified namespace. |

## Remarks

The
**NSPv2Startup** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPv2Startup** function can only be used for operations on NS_EMAIL namespace providers.

The
**NSPv2Startup** function is called each time a new client process begins using namespace provider. Providers may use the
client session argument pointed to by the *ppvClientSessionArg* parameter to store information about this session. The value in the *ppvClientSessionArg* parameter will be passed to subsequent NSPv2 function calls in the same session. The client session argument may **NULL**, if the namespace provider does not require this information.

The **NSPv2Startup** function is called when a new client session initializes.
The **NSPv2Startup** and
[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup) functions must be called as pairs.

The
**NSPv2Startup** function must be called successfully before calling the [NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup) function. It is permissible to make more than one
**NSPv2Startup** call. However, for each
**NSPv2Startup** call, a corresponding
**NSPv2Cleanup** call must also be issued. Only the final
**NSPv2Cleanup** for the service provider does the actual cleanup; the preceding calls decrement an internal reference count in the namespace service provider.

The **NSPv2Startup**, [NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown), and [NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup) functions are optional, dependent on the requirements of the NSPv2 provider.

 If the **NSPv2Startup** function isn't implemented, then calls to that function should be intercepted by a stub function that returns [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP). The NSPv2 function pointer to the unimplemented **NSPv2Startup** function in the [NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine) structure should point be to the stub function.

## See also

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)