# WSAAdvertiseProvider function

## Description

The
**WSAAdvertiseProvider** function makes a specific namespace version-2 provider available for all eligible clients.

## Parameters

### `puuidProviderId` [in]

A pointer to the provider ID of the namespace provider to be advertised.

### `pNSPv2Routine` [in]

A pointer to a **NSPV2_ROUTINE** structure with the namespace service provider version-2 entry points supported by the provider.

## Return value

If no error occurs,
[WSAProviderCompleteAsyncCall](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaprovidercompleteasynccall) returns zero.

If the function fails, the return value is SOCKET_ERROR. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror), which returns one of the following extended error values.

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An internal error occurred. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A parameter was not valid. This error is returned if the *puuidProviderId* or *pNSPv2Routine* parameters were **NULL**. <br><br>This error is also returned if the **NSPv2LookupServiceBegin**, **NSPv2LookupServiceNextEx**, or **NSPv2LookupServiceEnd** members of the **NSPV2_ROUTINE** structure pointed to by the *pNSPv2Routine* parameter are **NULL**. A namespace version-2 provider must at least support name resolution which this minimum set of functions. |
| **[WSAEINVALIDPROVIDER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The namespace provider could not be found for the specified *puuidProviderId* parameter. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *Ws2_32.dll* has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |

## Remarks

The
**WSAAdvertiseProvider** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **WSAAdvertiseProvider** function can only be used for operations on NS_EMAIL namespace providers.

The
**WSAAdvertiseProvider** function advertises an instance of a NSPv2 provider for clients to find. If the instance to be advertised is an instance of an application-type provider (a namespace provider where the **dwProvideType** member of the [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure is **ProviderType_Application**), the advertised provider instance will be visible to all the client processes running under the same user and in the same session as the caller of **WSAAdvertiseProvider**.

In general, NSPv2 providers are implemented in processes other than the calling applications. NSPv2 providers are not activated as a result of client activity. Each provider hosting application decides when to make a specific provider available or unavailable by calling the **WSAAdvertiseProvider** and [WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) functions. The client activity only results in attempts to contact the provider, when available (when the namespace provider is advertised).

The
**WSAAdvertiseProvider** function is called by any application that wants to make a specific provider available for all eligible clients (currently all the applications running with the same credentials as the hosting application, and in the same user session).

A process can implement and advertise multiple providers at the same time. Windows Sockets will manage the namespace providers by dispatching calls to the correct one. It will also hide RPC interface details and translates cross-process calls into in-process calls. So that the NSPv2 provider has only to implement a table of entry point functions similar to the [NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine) structure used by an NSPv1 provider. A NSPv2 provider does not have to worry about RPC specific requirements (data marshalling and serialization, for example).

The **WSAAdvertiseProvider** caller passes a pointer to an [NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine) structure in the *pNSPv2Routine* parameter with the NSPv2 entry points supported by the provider.

The
[WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) function makes a specific namespace provider no longer available for clients.

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[NAPI_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/nsemail/ne-nsemail-napi_provider_type)

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSAProviderCompleteAsyncCall](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaprovidercompleteasynccall)

[WSASetService](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetservicea)

[WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)