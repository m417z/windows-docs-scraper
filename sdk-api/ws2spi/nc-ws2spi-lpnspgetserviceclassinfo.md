## Description

The **NSPGetServiceClassInfo** function retrieves all the pertinent class information (schema) pertaining to the namespace provider. This call retrieves any namespace-specific information that is common to all instances of the service, including connection information for SAP, or port information for SAP or TCP.

## Parameters

### `lpProviderId` [in]

A pointer to the [GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) of the specific namespace provider from which the service class schema is to be retrieved.

### `lpdwBufSize` [in, out]

On input, the size, in bytes, of the buffer pointed to by *lpServiceClassInfo* parameter.

On output, if the function fails and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), this parameter specifies the minimum size, in bytes, of the buffer pointed to the *lpServiceClassInfo* parameter needed to retrieve the record.

### `lpServiceClassInfo` [in, out]

Returns a pointer to [WSASERVICECLASSINFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow) structure that contains the service class to namespace-specific mapping information. The *lpServiceClassId* parameter must be filled to indicate which **WSASERVICECLASSINFOW** record should be returned.

## Return value

If no error occurs, the **NSPGetServiceClassInfo** function returns **NO_ERROR** (zero). Otherwise, **SOCKET_ERROR** (–1) is returned and the namespace provider must set the appropriate error code using [WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to access the information. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer pointed to by the *lpServiceClass* parameter was too small to contain a [WSASERVICECLASSINFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow) structure. The application needs to pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified service class identifier or namespace provider identifier is not valid. This error is returned if the *lpProviderId*, *lpServiceClassId*, *lpdwBufSize*, or *lpServiceClassInfo* parameters are **NULL**. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. |
| **[WSATYPE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified class was not found. |

## Remarks

The W2_32.dll uses this function to implement the
[WSAGetServiceClassNameByClassId](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetserviceclassnamebyclassida) function, as well as to retrieve the namespace-specific information passed to the
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) and
[NSPSetService](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspsetservice) functions.

## See also

[NSPInstallServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspinstallserviceclass)

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPRemoveServiceClass](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspremoveserviceclass)

[NSPSetService](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspsetservice)

[WSAGetServiceClassInfo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetserviceclassinfoa)

[WSAGetServiceClassNameByClassId](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsagetserviceclassnamebyclassida)

[WSASERVICECLASSINFOW](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)