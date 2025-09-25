# WSCEnumNameSpaceProviders32 function

## Description

The **WSCEnumNameSpaceProviders32** function returns information on available 32-bit namespace providers.

**Note** This call is a strictly 32-bit version of [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa) for use on 64-bit platforms. It is provided to allow 64-bit processes to access the 32-bit catalogs.

## Parameters

### `lpdwBufferLength` [in, out]

On input, the number of bytes contained in the buffer pointed to by *lpnspBuffer*. On output (if the function fails, and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)), the minimum number of bytes to allocate for the *lpnspBuffer* buffer to allow it to retrieve all the requested information. The buffer passed to **WSCEnumNameSpaceProviders32** must be sufficient to hold all of the namespace information.

### `lpnspBuffer` [out]

A buffer that is filled with
[WSANAMESPACE_INFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures. The returned structures are located consecutively at the head of the buffer. Variable sized information referenced by pointers in the structures point to locations within the buffer located between the end of the fixed sized structures and the end of the buffer. The number of structures filled in is the return value of
**WSCEnumNameSpaceProviders32**.

## Return value

The
**WSCEnumNameSpaceProviders32** function returns the number of
[WSANAMESPACE_INFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures copied into *lpnspBuffer*. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpnspBuffer* parameter was a **NULL** pointer or the buffer length, *lpdwBufferLength*, was too small to receive all the relevant [WSANAMESPACE_INFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow) structures and associated information. When this error is returned, the buffer length required is returned in the *lpdwBufferLength* parameter. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

**WSCEnumNameSpaceProviders32** is a strictly 32-bit version of [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa). On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

The 32-bit SPI function is equivalent to the native API function ([WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)) because there is no concept of a "hidden" namespace provider.

The **WSCEnumNameSpaceProviders32** function is a Unicode only function and returns [WSANAMESPACE_INFOEXW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infoexw) structures.

## See also

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSANAMESPACE_INFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsanamespace_infow)

[WSCInstallNameSpace32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespace32)

[WSCInstallNameSpaceEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallnamespaceex)