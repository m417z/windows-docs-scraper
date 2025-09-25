# LPNSPV2CLEANUP callback function

## Description

The
**NSPv2Cleanup** function notifies a namespace service provider version-2 (NSPv2) provider that a client session has terminated.

## Parameters

### `lpProviderId` [in]

A pointer to the GUID of the namespace provider to be notified.

### `pvClientSessionArg` [in]

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
**NSPv2Cleanup** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPv2Cleanup** function can only be used for operations on NS_EMAIL namespace providers.

The
[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup) function is called each time a new client process begins using namespace provider. Providers may use the
client session argument pointed to by the *ppvClientSessionArg* parameter to store information about this session. If a value was specified for the client session argument in the call to the **NSPv2Startup** function, then this same client session argument can be passed in the pvClientSessionArg parameter to the **NSPv2Cleanup** function to notify namespace provider that the client session has terminated.

The
**NSPv2Cleanup** function is called when an application is finished using a Windows Sockets namespace service provider. The
**NSPv2Cleanup** allows the namespace provider to free any of namespace provider resources that were allocated for the client session.

The
[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup) function must be called successfully before calling the **NSPv2Cleanup** function. It is permissible to make more than one
**NSPv2Startup** call. However, for each
**NSPv2Startup** call, a corresponding
**NSPv2Cleanup** call must also be issued. Only the final
**NSPv2Cleanup** for the service provider does the actual cleanup; the preceding calls decrement an internal reference count in the service provider.

The [NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup), [NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown), and **NSPv2Cleanup** functions are optional, dependent on the requirements of the NSPv2 provider.

 If the **NSPv2Cleanup** function isn't implemented, then calls to that function should be intercepted by a stub function that returns [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP). The NSPv2 function pointer to the unimplemented **NSPv2Cleanup** function in the [NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine) structure should point be to the stub function.

## See also

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)