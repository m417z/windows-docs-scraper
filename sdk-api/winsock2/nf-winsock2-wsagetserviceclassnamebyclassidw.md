# WSAGetServiceClassNameByClassIdW function

## Description

The
**WSAGetServiceClassNameByClassId** function retrieves the name of the service associated with the specified type. This name is the generic service name, like FTP or SNA, and not the name of a specific instance of that service.

## Parameters

### `lpServiceClassId` [in]

A pointer to the GUID for the service class.

### `lpszServiceClassName` [out]

A pointer to the service name.

### `lpdwBufferLength` [in, out]

On input, the length of the buffer returned by *lpszServiceClassName*, in characters. On output, the length of the service name copied into *lpszServiceClassName*, in characters.

## Return value

The
**WSAGetServiceClassNameByClassId** function returns a value of zero if successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpServiceClassId* parameter specified is invalid. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to access the information. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified buffer pointed to by *lpszServiceClassName* is too small. Pass in a larger buffer. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space available. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The operation is not supported for the type of object referenced. This error is returned by some namespace providers that do not support getting service class information. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpServiceClassId* is valid, but no data of the requested type was found. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |

## See also

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The winsock2.h header defines WSAGetServiceClassNameByClassId as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).