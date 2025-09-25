# WSAProviderCompleteAsyncCall function

## Description

The
**WSAProviderCompleteAsyncCall** function notifies a client when an asynchronous call to a namespace version-2 provider is completed.

## Parameters

### `hAsyncCall`

The handle passed to the asynchronous call being completed. This handle is passed by the client to the namespace version-2 provider in the asynchronous function call.

### `iRetCode`

The return code for the asynchronous call to the namespace version-2 provider.

## Return value

If no error occurs,
**WSAProviderCompleteAsyncCall** returns zero.

If the function fails, the return value is SOCKET_ERROR. To get extended error information, call
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror), which returns one of the following extended error values.

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An internal error occurred. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A parameter was not valid. This error is returned if the *hAsyncCall* parameter was **NULL**. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *Ws2_32.dll* has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |

## Remarks

The
**WSAProviderCompleteAsyncCall** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the [WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) function can only be used for operations on NS_EMAIL namespace providers. Asynchronous calls to NSPv2 providers are not supported on Windows Vista and Windows Server 2008. So the **WSAProviderCompleteAsyncCall** is not currently applicable. This function is planned for use in later versions of Windows when asynchronous calls to namespace providers are supported.

In general, NSPv2 providers are implemented in processes other than the calling applications. NSPv2 providers are not activated as result of client activity. Each provider hosting application decides when to make a specific provider available or unavailable by calling the [WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider) and [WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider) functions. The client activity only results in attempts to contact the provider, when available (when the namespace provider is advertised).

## See also

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[WSAAdvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaadvertiseprovider)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAUnadvertiseProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wsaunadvertiseprovider)