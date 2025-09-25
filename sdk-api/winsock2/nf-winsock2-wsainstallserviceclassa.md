# WSAInstallServiceClassA function

## Description

The
**WSAInstallServiceClass** function registers a service class schema within a namespace. This schema includes the class name, class identifier, and any namespace-specific information that is common to all instances of the service, such as the SAP identifier or object identifier.

## Parameters

### `lpServiceClassInfo` [in]

Service class to namespace specific–type mapping information. Multiple mappings can be handled at one time.

See the section
[Service Class Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2) for a description of pertinent data structures.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The namespace provider cannot supply the requested class information. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling function does not have sufficient privileges to install the service. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Service class information has already been registered for this service class identifier. To modify service class information, first use [WSARemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaremoveserviceclass), and then reinstall with updated class information data. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service class information was not valid or improperly structured. This error is returned if the *lpServiceClassInfo* parameter is **NULL**. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |

## See also

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetserviceclassinfoa)

[WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The winsock2.h header defines WSAInstallServiceClass as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).