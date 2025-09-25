# LPNSPV2LOOKUPSERVICENEXTEX callback function

## Description

The
**NSPv2LookupServiceNextEx** function is called after obtaining a handle from a previous call to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) in order to retrieve the requested information from a namespace version-2 service provider.

## Parameters

### `hAsyncCall` [in]

A handle returned from the previous call to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) used for asynchronous calls.

### `hLookup` [in]

A handle returned from the previous call to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin).

### `dwControlFlags` [in]

The flags used to control the next operation. Currently, only **LUP_FLUSHPREVIOUS** is defined as a means to handle a result set that is too large. If an application cannot supply a large enough buffer, setting **LUP_FLUSHPREVIOUS** instructs the provider to discard the last result set, which was too large, and move to the next set for this call.

### `lpdwBufferLength` [in, out]

The size, in bytes, on input, that is contained in the buffer pointed to by *lpqsResults*. On output, if the function fails and the error is WSAEFAULT, then it contains the minimum size, in bytes to pass for the *lpqsResults* to retrieve the record.

### `lpqsResults` [out]

A pointer to a memory block that will contain, on return, one result set in a
[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (that is, 1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A call to [NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend) was made while this call was still processing. The call has been canceled. The data in the *lpqsResults* buffer is undefined. <br><br>In Windows Sockets 2, conflicting error codes are defined for **WSAECANCELLED** (10103) and **WSA_E_CANCELLED** (10111).The error code **WSAECANCELLED** will be removed in a future version and only WSA_E_CANCELLED will remain. Namespace providers should use the **WSA_E_CANCELLED** error code to maintain compatibility with the widest possible range of applications. |
| **[WSA_E_NO_MORE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is no more data available. <br><br>In Windows Sockets 2, conflicting error codes are defined for **WSAENOMORE** (10102) and **WSA_E_NO_MORE** (10110).The error code **WSAENOMORE** will be removed in a future version and only WSA_E_NO_MORE will remain. Namespace providers should use the **WSA_E_NO_MORE** error code to maintain compatibility with the widest possible range of applications. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpqsResults* buffer was too small to contain a [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) set. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters are invalid, or missing, for this provider. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified lookup handle is invalid. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database, but no data, matching the given restrictions, was located. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service is unknown. The service cannot be found in the specified namespace. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |

## Remarks

The
**NSPv2LookupServiceNextEx** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPv2LookupServiceNextEx** function can only be used for operations on NS_EMAIL namespace providers.

The provider will pass a
[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure in the *lpqsResults* buffer. The client should call the **NSPv2LookupServiceNextEx** function until it returns **WSA_E_NOMORE**, indicating that all the
**WSAQUERYSET2** structures have been returned.

The *dwControlFlags* specified in this function and the ones specified at the time of
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) are handled as "restrictions" for the purpose of combination. The restrictions are combined between the ones at
**NSPv2LookupServiceBegin** time and the ones at
**NSPv2LookupServiceNextEx** time. Therefore, the flags at
**NSPv2LookupServiceNextEx** can never increase the amount of data returned beyond what was requested at
**NSPv2LookupServiceBegin**, although it is not an error to specify more or less flags. The flags specified at a given
**NSPv2LookupServiceNextEx** apply only to that call.

The *dwControlFlags* **LUP_FLUSHPREVIOUS** and **LUP_RES_SERVICE** are exceptions to the combined restrictions rule (because they are behavior flags instead of "restriction" flags). If either flag is used in
**NSPv2LookupServiceNextEx**, they have their defined effect regardless of the setting of the same flags at
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin).

For example, if **LUP_RETURN_VERSION** is specified at
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin), the service provider retrieves records including the version. If **LUP_RETURN_VERSION** is not specified at
**NSPv2LookupServiceNextEx**, the returned information does not include the version, even though it was available. No error is generated.

Also for example, if **LUP_RETURN_BLOB** is not specified at
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin), but is specified at
**NSPv2LookupServiceNextEx**, the returned information does not include the private data. No error is generated.

The **NSPv2LookupServiceNextEx** function is typically called at least twice. The first time to get the size of the needed buffer to receive the [WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) pointed to by the *lpqsResults* parameter, and the second time to get the actual query result set. On the first call, the NSPv2 provider should return the size necessary for the **WSAQUERYSET2** results.

The [WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure pointed to by the *lpqsResults* parameter that is returned is only useful in the same process context, since several of the members in the **WSAQUERYSET2** structure contains pointers to the actual data returned. If the query result needs to be passed to another process (using RPC, for example), then it will be necessary to serialize and marshal the data returned in the **WSAQUERYSET2** structure pointed to by the *lpqsResults* parameter including the data pointed to by members in the **WSAQUERYSET2** structure. The data needs to be serialized in a form that can be passed across process boundaries. Just passing a copy of the **WSAQUERYSET2** structure is insufficient, since only pointers to data will be passed and the actual data will be unavailable to other processes.

### Query Results

The following table lists [WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) and describes how query results are represented in the
**WSAQUERYSET2** structure. For more information, see [Query-Related Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2).

| WSAQUERYSET2 member name | Result interpretation |
| --- | --- |
| **dwSize** | The size, in bytes, of [WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure. This is used as a versioning mechanism. |
| **lpszServiceInstanceName** | A string that contains the service name. |
| **lpVersion** | References version number of the particular service instance. |
| **lpszComment** | A comment string supplied by service instance. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNameSpace** | The namespace identifier in which the name or service instance was found. |
| **lpNSProviderId** | The specific namespace provider that supplied this query result. |
| **lpszContext** | The context point in a hierarchical namespace at which the service is located. |
| **dwNumberOfProtocols** | This member is undefined for results. |
| **lpafpProtocols** | This member is undefined for results. All needed protocol information is in the [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpszQueryString** | When *dwControlFlags* includes **LUP_RETURN_QUERY_STRING**, this member returns the unparsed remainder of the **lpszServiceInstanceName** specified in the original query. For example, in a namespace that identifies services by hierarchical names that specify a host name and a file path within that host, the address returned might be the host address and the unparsed remainder might be the file path. If the **lpszServiceInstanceName** is fully parsed and **LUP_RETURN_QUERY_STRING** is used, this member is null or points to a zero-length string. |
| **dwNumberOfCsAddrs** | The number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures, with one complete transport address contained within each element. |
| **dwOutputFlags** | The **RESULT_IS_ALIAS** flag indicates this is an alias result. |
| **lpBlob** | A pointer to a provider-specific entity. This member is optional, dependent on the requirements of the NSPv2 service provider. |

## See also

[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info)

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)