# WSCGetProviderPath32 function

## Description

The **WSCGetProviderPath32** function retrieves the DLL path for the specified 32-bit provider.

**Note** This call is a strictly 32-bit version of [WSCGetProviderPath](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderpath) for use on 64-bit platforms. It is provided to allow 64-bit processes to access the 32-bit catalogs.

## Parameters

### `lpProviderId` [in]

Locally unique identifier of the provider. This value is obtained by using
[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32).

### `lpszProviderDllPath` [out]

Pointer to a buffer into which the provider DLL's path string is returned. The path is a null-terminated string and any embedded environment strings, such as %SystemRoot%, have not been expanded.

### `lpProviderDllPathLen` [in, out]

Size of the buffer pointed to by the *lpszProviderDllPath* parameter, in characters.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If
no error occurs, **WSCGetProviderPath32** returns zero. Otherwise, it returns SOCKET_ERROR. The specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter does not specify a valid provider. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpszProviderDllPath* or *lpErrno* parameter is not in a valid part of the user address space, or *lpProviderDllPathLen* is too small. |

## Remarks

**WSCGetProviderPath32** is a strictly 32-bit version of [WSCGetProviderPath](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscgetproviderpath). On a 64-bit computer, all calls not specifically 32-bit (for example, all functions that do not end in "32") operate on the native 64-bit catalog. Processes that execute on a 64-bit computer must use the specific 32-bit function calls to operate on a strictly 32-bit catalog and preserve compatibility. The definitions and semantics of the specific 32-bit calls are the same as their native counterparts.

The
**WSCGetProviderPath32** function retrieves the DLL path for the specified provider. The DLL path can contain embedded environment strings, such as %SystemRoot%, and thus should be expanded prior to being used with the Windows [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. For more information, see **LoadLibrary**.

## See also

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)

[WSCInstallProvider64_32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider64_32)