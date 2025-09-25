# WPUGetProviderPath function

## Description

The
**WPUGetProviderPath** function retrieves the DLL path for the specified provider.

## Parameters

### `lpProviderId` [in]

Locally unique identifier of the provider. This must be a value obtained by using
[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols).

### `lpszProviderDllPath` [out]

Pointer to a buffer containing a string that identifies the provider DLL's path. This path is a null-terminated string and any embedded environment strings (such as %SystemRoot%) have not been expanded.

### `lpProviderDllPathLen` [in, out]

Size of the buffer pointed to by *lpszProviderDllPath*, in characters.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WPUGetProviderPath** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProviderId* parameter does not specify a valid provider. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Either *lpszProviderDllPath* or *lpErrno* is not in a valid part of the user address space, or *lpProviderDllPathLen* is too small. |

## Remarks

The
**WPUGetProviderPath** function retrieves the DLL path for the specified provider. The DLL path is null-terminated and may contain embedded environment strings (such as %SystemRoot%). Thus, the string should be expanded prior to being used with [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya). For more information, see **LoadLibrary**.

## See also

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCInstallProvider](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscinstallprovider)