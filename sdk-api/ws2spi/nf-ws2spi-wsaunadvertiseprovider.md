# WSAUnadvertiseProvider function

## Description

The
**WSAUnadvertiseProvider** function makes a specific namespace version-2 provider no longer available for clients.

## Parameters

### `puuidProviderId` [in]

A pointer to the provider ID of the namespace provider.

## Return value

If no error occurs,
**WSAUnadvertiseProvider** returns zero. Otherwise, it returns **SOCKET_ERROR**, and a specific error code is available by calling [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A parameter was not valid. This error is returned if the *puuidProviderId* parameter was **NULL**. |

## Remarks

The
**WSAUnadvertiseProvider** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **WSAUnadvertiseProvider** function can only be used for operations on NS_EMAIL namespace providers.

In general, NSPv2 providers are implemented in processes other than the calling applications. NSPv2 providers are not activated as result of client activity. Each provider hosting application decides when to make a specific provider available or unavailable by calling the [WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider) and **WSAUnadvertiseProvider** functions. The client activity only results in attempts to contact the provider, when available (when the namespace provider is advertised).

## See also

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSASetService](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasetservicea)