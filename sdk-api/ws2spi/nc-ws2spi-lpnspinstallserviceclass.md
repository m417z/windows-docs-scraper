# LPNSPINSTALLSERVICECLASS callback function

## Description

The
**NSPInstallServiceClass** function registers service class schema within the namespace providers.

The schema includes the class name, class identifier, and any namespace-specific type information that is common to all instances of the service, such as SAP identifier or object identifier. A dynamic namespace provider is expected to store any class information associated with that namespace.

## Parameters

### `lpProviderId` [in]

A pointer to the GUID of the specific namespace provider that this service class schema is registered in.

### `lpServiceClassInfo` [in]

A pointer to the service class schema information.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_PARAMETER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The namespace provider cannot supply the requested class information. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to perform this operation. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service class information has already been registered for this service class identifier. To modify service class information, first call [NSPRemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspremoveserviceclass), then reinstall with updated class information data. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service class identifier was invalid or improperly structured. This error is returned if the *lpServiceClassInfo* parameter is **NULL**. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |

## Remarks

Namespace providers are encouraged, but not required, to store information that is specific to the namespace they support.

## See also

[NSPGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspgetserviceclassinfo)

[NSPRemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspremoveserviceclass)

[WSASERVICECLASSINFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)