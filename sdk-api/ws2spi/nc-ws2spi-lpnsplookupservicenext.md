# LPNSPLOOKUPSERVICENEXT callback function

## Description

The
**NSPLookupServiceNext** function is called after obtaining a handle from a previous call to
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) in order to retrieve the requested service information.

The provider will pass a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure in the *lpqsResults* buffer. The client should call this function until it returns **WSA_E_NOMORE**, indicating that all the
**WSAQUERYSET** have been returned.

## Parameters

### `hLookup` [in]

A handle returned from the previous call to
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina).

### `dwControlFlags` [in]

The flags used to control the next operation. Currently, only **LUP_FLUSHPREVIOUS** is defined as a means to handle a result set that is too large. If an application cannot supply a large enough buffer, setting **LUP_FLUSHPREVIOUS** instructs the provider to discard the last result set, which was too large, and move to the next set for this call.

### `lpdwBufferLength` [in, out]

The size, in bytes, on input, that is contained in the buffer pointed to by *lpqsResults*. On output, if the function fails and the error is WSAEFAULT, then it contains the minimum size, in bytes to pass for the *lpqsResults* to retrieve the record.

### `lpqsResults` [out]

A pointer to a memory block that will contain, on return, one result set in a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A call to [NSPLookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupserviceend) was made while this call was still processing. The call has been canceled. The data in the *lpqsResults* buffer is undefined. <br><br>In Windows Sockets 2, conflicting error codes are defined for **WSAECANCELLED** (10103) and **WSA_E_CANCELLED** (10111).The error code **WSAECANCELLED** will be removed in a future version and only WSA_E_CANCELLED will remain. Namespace providers should use the **WSA_E_CANCELLED** error code to maintain compatibility with the widest possible range of applications. |
| **[WSA_E_NO_MORE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is no more data available. <br><br>In Windows Sockets 2, conflicting error codes are defined for **WSAENOMORE** (10102) and **WSA_E_NO_MORE** (10110).The error code **WSAENOMORE** will be removed in a future version and only WSA_E_NO_MORE will remain. Namespace providers should use the **WSA_E_NO_MORE** error code to maintain compatibility with the widest possible range of applications. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified lookup handle is invalid. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpqsResults* buffer was too small to contain a [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) set. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters are invalid, or missing, for this provider. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database, but no data, matching the given restrictions, was located. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service is unknown. The service cannot be found in the specified namespace. |

## Remarks

The *dwControlFlags* specified in this function and the ones specified at the time of
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) are handled as "restrictions" for the purpose of combination. The restrictions are combined between the ones at
**NSPLookupServiceBegin** time and the ones at
**NSPLookupServiceNext** time. Therefore, the flags at
**NSPLookupServiceNext** can never increase the amount of data returned beyond what was requested at
**NSPLookupServiceBegin**, although it is not an error to specify more or less flags. The flags specified at a given
**NSPLookupServiceNext** apply only to that call.

The *dwControlFlags* **LUP_FLUSHPREVIOUS** and **LUP_RES_SERVICE** are exceptions to the combined restrictions rule (because they are behavior flags instead of "restriction" flags). If either flag is used in
**NSPLookupServiceNext**, they have their defined effect regardless of the setting of the same flags at
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin).

For example, if **LUP_RETURN_VERSION** is specified at
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin), the service provider retrieves records including the version. If **LUP_RETURN_VERSION** is not specified at
**NSPLookupServiceNext**, the returned information does not include the version, even though it was available. No error is generated.

Also for example, if **LUP_RETURN_BLOB** is not specified at
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin), but is specified at
**NSPLookupServiceNext**, the returned information does not include the private data. No error is generated.

### Query Results

The following table lists [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) and describes how query results are represented in the
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure. For more information, see [Query-Related Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2).

| WSAQUERYSET member name | Result interpretation |
| --- | --- |
| **dwSize** | Will be set to sizeof([WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is used as a versioning mechanism. |
| **dwOutputFlags** | **RESULT_IS_ALIAS** flag indicates this is an alias result. |
| **lpszServiceInstanceName** | References the string that contains the service name. |
| **lpServiceClassId** | GUID corresponding to the service class. |
| **lpVersion** | References version number of the particular service instance. |
| **lpszComment** | Optional. Comment string supplied by service instance. |
| **dwNameSpace** | Namespace in which the service instance was found. |
| **lpNSProviderId** | Identifies the specific namespace provider that supplied this query result. |
| **lpszContext** | Specifies the context point in a hierarchical namespace at which the service is located. |
| **dwNumberOfProtocols** | Undefined for results. |
| **lpafpProtocols** | Undefined for results, all needed protocol information is in the [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpszQueryString** | When *dwControlFlags* includes **LUP_RETURN_QUERY_STRING**, this member returns the unparsed remainder of the **lpszServiceInstanceName** specified in the original query. For example, in a namespace that identifies services by hierarchical names that specify a host name and a file path within that host, the address returned might be the host address and the unparsed remainder might be the file path. If the **lpszServiceInstanceName** is fully parsed and **LUP_RETURN_QUERY_STRING** is used, this member is null or points to a zero-length string. |
| **dwNumberOfCsAddrs** | Indicates the number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures, with one complete transport address contained within each element. |
| **lpBlob** | Optional. A pointer to a provider-specific entity. |

## See also

[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info)

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPLookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupserviceend)

[NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)