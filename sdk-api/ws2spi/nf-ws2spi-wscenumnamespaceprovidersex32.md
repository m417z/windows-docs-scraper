# WSCEnumNameSpaceProvidersEx32 function

## Description

The
**WSCEnumNameSpaceProvidersEx32** function retrieves information on available 32-bit namespace providers.

## Parameters

### `lpdwBufferLength` [in, out]

On input, the number of bytes contained in the buffer pointed to by *lpnspBuffer*. On output (if the function fails, and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)), the minimum number of bytes to allocate for the *lpnspBuffer* buffer to allow it to retrieve all the requested information. The buffer passed to **WSCEnumNameSpaceProvidersEx32** must be sufficient to hold all of the namespace information.

### `lpnspBuffer` [out]

A buffer that is filled with
[WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures. The returned structures are located consecutively at the head of the buffer. Variable sized information referenced by pointers in the structures point to locations within the buffer located between the end of the fixed sized structures and the end of the buffer. The number of structures filled in is the return value of
**WSCEnumNameSpaceProvidersEx32**.

## Return value

The
**WSCEnumNameSpaceProvidersEx32** function returns the number of
[WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures copied into *lpnspBuffer*. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer length was too small to receive all the relevant [WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures and associated information or the *lpnspBuffer* parameter was a **NULL** pointer. When this error is returned, the buffer length required is returned in the *lpdwBufferLength* parameter. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

**WSCEnumNameSpaceProvidersEx32** is a strictly 32-bit version of [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa). On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

 Currently, the only namespace included with Windows that uses information in the **ProviderSpecific** member of the [WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structure are namespace providers for the NS_EMAIL namespace. The format of the **ProviderSpecific** member for an NS_EMAIL namespace provider is a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

The 32-bit SPI function is equivalent to the native API function ([WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)) because there is no concept of a "hidden" namespace provider.

The provider-specific data blob associated with namespace entry
passed in the *lpProviderInfo* parameter to the [WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32) function can be queried using **WSCEnumNameSpaceProvidersEx32** function.

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw)

[WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex32)