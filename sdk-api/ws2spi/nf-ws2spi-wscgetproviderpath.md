# WSCGetProviderPath function

## Description

The
**WSCGetProviderPath** function retrieves the DLL path for the specified provider.

## Parameters

### `lpProviderId` [in]

A pointer to a globally unique identifier (GUID) for the provider. This value is obtained by using
[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols).

### `lpszProviderDllPath` [out]

A pointer to a buffer into which the provider DLL's path string is returned. The path is a null-terminated string and any embedded environment strings, such as %SystemRoot%, have not been expanded.

### `lpProviderDllPathLen` [in, out]

The size, in characters, of the buffer pointed to by the *lpszProviderDllPath* parameter.

### `lpErrno` [out]

A pointer to the error code if the function fails.

## Return value

If no error occurs,
**WSCGetProviderPath** returns zero. Otherwise, it returns SOCKET_ERROR. The specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter does not specify a valid provider. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpszProviderDllPath* or *lpErrno* parameter is not in a valid part of the user address space, or *lpProviderDllPathLen* is too small. |

## Remarks

The
**WSCGetProviderPath** function retrieves the DLL path for the specified provider. The DLL path can contain embedded environment strings, such as %SystemRoot%, and thus should be expanded prior to being used with the Windows [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function. For more information, see **LoadLibrary**.

## See also

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider)