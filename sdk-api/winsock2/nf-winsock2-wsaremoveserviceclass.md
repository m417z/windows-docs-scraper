# WSARemoveServiceClass function

## Description

The
**WSARemoveServiceClass** function permanently removes the service class schema from the registry.

## Parameters

### `lpServiceClassId` [in]

Pointer to the GUID for the service class you want to remove.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to remove the Service. |
| **[WSAETOOMANYREFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There are service instances that still reference the class. Removal of this class is not possible at this time. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified GUID was not valid. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## See also

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)