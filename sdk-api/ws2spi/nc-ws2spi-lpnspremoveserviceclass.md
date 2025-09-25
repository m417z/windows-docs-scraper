# LPNSPREMOVESERVICECLASS callback function

## Description

The
**NSPRemoveServiceClass** function permanently removes a specified service class from the namespace.

## Parameters

### `lpProviderId` [in]

A pointer to the GUID of the specific namespace provider that this service class schema is to be removed from.

### `lpServiceClassId` [in]

A pointer to the GUID for the service class to remove.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified GUID was not valid. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to remove the Service. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified service class identifier GUID was not valid. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found in any of the namespaces. |

## See also

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)