# WSAEnumNameSpaceProvidersExW function

## Description

The
**WSAEnumNameSpaceProvidersEx** function retrieves information on available namespace providers.

## Parameters

### `lpdwBufferLength` [in, out]

On input, the number of bytes contained in the buffer pointed to by *lpnspBuffer*. On output (if the function fails, and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)), the minimum number of bytes to allocate for the *lpnspBuffer* buffer to allow it to retrieve all the requested information. The buffer passed to **WSAEnumNameSpaceProvidersEx** must be sufficient to hold all of the namespace information.

### `lpnspBuffer` [out]

A buffer that is filled with
[WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures. The returned structures are located consecutively at the head of the buffer. Variable sized information referenced by pointers in the structures point to locations within the buffer located between the end of the fixed sized structures and the end of the buffer. The number of structures filled in is the return value of
**WSAEnumNameSpaceProvidersEx**.

## Return value

The
**WSAEnumNameSpaceProvidersEx** function returns the number of
[WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures copied into *lpnspBuffer*. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpnspBuffer* parameter was a **NULL** pointer or the buffer length, *lpdwBufferLength*, was too small to receive all the relevant [WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures and associated information. When this error is returned, the buffer length required is returned in the *lpdwBufferLength* parameter. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

The **WSAEnumNameSpaceProvidersEx** function is an enhanced version of the [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) function. The provider-specific data blob associated with the namespace entry
passed in the *lpProviderInfo* parameter to the [WSCInstallNameSpaceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex) function can be queried using **WSAEnumNameSpaceProvidersEx** function.

Currently, the only namespace provider included with Windows that sets information in the **ProviderSpecific** member of the [WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structure is the NS_EMAIL provider. The format of the **ProviderSpecific** member for an NS_EMAIL namespace provider is a [NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob) structure.

When UNICODE or _UNICODE is defined, **WSAEnumNameSpaceProvidersEx** is defined to **WSAEnumNameSpaceProvidersExW**, the Unicode version of this function. The *lpnspBuffer* parameter is defined to the [LPSAWSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) data type and **WSANAMESPACE_INFOEXW** structures are returned on success.

When UNICODE or _UNICODE is not defined, **WSAEnumNameSpaceProvidersEx** is defined to **WSAEnumNameSpaceProvidersExA**, the ANSI version of this function. The *lpnspBuffer* parameter is defined to the [LPSAWSANAMESPACE_INFOEXA](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) data type and **WSANAMESPACE_INFOEXA** structures are returned on success.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSAEnumNameSpaceProvidersExW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSAEnumNameSpaceProvidersEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NAPI_PROVIDER_INSTALLATION_BLOB](https://learn.microsoft.com/windows/desktop/api/nsemail/ns-nsemail-napi_provider_installation_blob)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSANAMESPACE_INFOEX](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)