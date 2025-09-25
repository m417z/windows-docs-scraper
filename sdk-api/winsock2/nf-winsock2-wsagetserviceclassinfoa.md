# WSAGetServiceClassInfoA function

## Description

The
**WSAGetServiceClassInfo** function retrieves the class information (schema) pertaining to a specified service class from a specified namespace provider.

## Parameters

### `lpProviderId` [in]

A pointer to a GUID that identifies a specific namespace provider.

### `lpServiceClassId` [in]

A pointer to a GUID identifying the service class.

### `lpdwBufSize` [in, out]

On input, the number of bytes contained in the buffer pointed to by the *lpServiceClassInfo* parameter.

On output, if the function fails and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), this parameter specifies the minimum size, in bytes, of the buffer pointed to *lpServiceClassInfo* needed to retrieve the record.

### `lpServiceClassInfo` [out]

A pointer to a [WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow) structure that contains the service class information from the indicated namespace provider for the specified service class.

## Return value

The return value is zero if the
**WSAGetServiceClassInfo** was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to access the information. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer pointed to by the *lpServiceClassInfo* parameter is too small to contain a WSASERVICECLASSINFOW. The application needs to pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified service class identifier or namespace provider identifier is not valid. This error is returned if the *lpProviderId*, *lpServiceClassId*, *lpdwBufSize*, or *lpServiceClassInfo* parameters are **NULL**. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The operation is not supported for the type of object referenced. This error is returned by some namespace providers that do not support getting service class information. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found. |

## Remarks

The
**WSAGetServiceClassInfo** function retrieves service class information from a namespace provider. The service class information retrieved from a particular namespace provider might not be the complete set of class information that was specified when the service class was installed. Individual namespace providers are only required to retain service class information that is applicable to the namespaces that they support. See the section
[Service Class Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/service-class-data-structures-in-the-spi-2) for more information.

> [!NOTE]
> The winsock2.h header defines WSAGetServiceClassInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Service Class Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/service-class-data-structures-in-the-spi-2)

[WSAInstallServiceClass](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsainstallserviceclassa)

[WSASERVICECLASSINFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)