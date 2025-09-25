# WSALookupServiceNextA function

## Description

The
**WSALookupServiceNext** function is called after obtaining a handle from a previous call to
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) in order to retrieve the requested service information.

The provider will pass back a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure in the *lpqsResults* buffer. The client should continue to call this function until it returns WSA_E_NO_MORE, indicating that all of
**WSAQUERYSET** has been returned.

## Parameters

### `hLookup` [in]

A handle returned from the previous call to
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina).

### `dwControlFlags` [in]

A set of flags that controls the operation. The values passed in the *dwControlFlags* parameter to the [WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) function determine the possible criteria. Any values passed in the *dwControlFlags* parameter to the **WSALookupServiceNext** function further restrict the criteria for the service lookup.

Currently, LUP_FLUSHPREVIOUS is defined as a means to cope with a result set that is too large. If an application does not (or cannot) supply a large enough buffer, setting LUP_FLUSHPREVIOUS instructs the provider to discard the last result set—which was too large—and move on to the next set for this call.

Supported values for the *dwControlFlags* parameter are defined in the *Winsock2.h* header file and can be a combination of the following options.

| Flag | Meaning |
| --- | --- |
| **LUP_DEEP**<br><br>0x0001 | Queries deep as opposed to just the first level. |
| **LUP_CONTAINERS**<br><br>0x0002 | Returns containers only. |
| **LUP_NOCONTAINERS**<br><br>0x0004 | Do not return containers. |
| **LUP_NEAREST**<br><br>0x0008 | If possible, returns results in the order of distance. The measure of distance is provider specific. |
| **LUP_RETURN_NAME**<br><br>0x0010 | Retrieves the name as *lpszServiceInstanceName*. |
| **LUP_RETURN_TYPE**<br><br>0x0020 | Retrieves the type as *lpServiceClassId*. |
| **LUP_RETURN_VERSION**<br><br>0x0040 | Retrieves the version as *lpVersion*. |
| **LUP_RETURN_COMMENT**<br><br>0x0080 | Retrieves the comment as *lpszComment*. |
| **LUP_RETURN_ADDR**<br><br>0x0100 | Retrieves the addresses as *lpcsaBuffer*. |
| **LUP_RETURN_BLOB**<br><br>0x0200 | Retrieves the private data as *lpBlob*. |
| **LUP_RETURN_ALIASES**<br><br>0x0400 | Any available alias information is to be returned in successive calls to **WSALookupServiceNext**, and each alias returned will have the RESULT_IS_ALIAS flag set. |
| **LUP_RETURN_QUERY_STRING**<br><br>0x0800 | Retrieves the query string used for the request. |
| **LUP_RETURN_ALL**<br><br>0x0FF0 | A set of flags that retrieves all of the LUP_RETURN_* values. |
| **LUP_FLUSHPREVIOUS**<br><br>0x1000 | Used as a value for the *dwControlFlags* parameter in **WSALookupServiceNext**. Setting this flag instructs the provider to discard the last result set, which was too large for the specified buffer, and move on to the next result set. |
| **LUP_FLUSHCACHE**<br><br>0x2000 | If the provider has been caching information, ignores the cache, and queries the namespace itself. |
| **LUP_RES_SERVICE**<br><br>0x8000 | This indicates whether prime response is in the remote or local part of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure. The other part needs to be usable in either case. |

### `lpdwBufferLength` [in, out]

On input, the number of bytes contained in the buffer pointed to by *lpqsResults*. On output, if the function fails and the error is
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), then it contains the minimum number of bytes to pass for the *lpqsResults* to retrieve the record.

### `lpqsResults` [out]

A pointer to a block of memory, which will contain one result set in a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure on return.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A call to [WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend) was made while this call was still processing. The call has been canceled. The data in the *lpqsResults* buffer is undefined. In Windows Sockets version 2, conflicting error codes are defined for [WSAECANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) (10103) and [WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) (10111). The error code WSAECANCELLED will be removed in a future version and only WSA_E_CANCELLED will remain. For Windows Sockets version 2, however, applications should check for both WSAECANCELLED and WSA_E_CANCELLED for the widest possible compatibility with namespace providers that use either one. |
| **[WSA_E_NO_MORE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is no more data available. In Windows Sockets version 2, conflicting error codes are defined for [WSAENOMORE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) (10102) and [WSA_E_NO_MORE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) (10110). The error code WSAENOMORE will be removed in a future version and only WSA_E_NO_MORE will remain. For Windows Sockets version 2, however, applications should check for both WSAENOMORE and WSA_E_NO_MORE for the widest possible compatibility with name-space providers that use either one. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpqsResults* buffer was too small to contain a [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) set. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more required parameters were invalid or missing. |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified Lookup handle is invalid. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database, but no data matching the given restrictions was located. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

The *dwControlFlags* parameter specified in this function and the ones specified at the time of
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) are treated as restrictions for the purpose of combination. The restrictions are combined between the ones at
**WSALookupServiceBegin** time and the ones at
**WSALookupServiceNext** time. Therefore the flags at
**WSALookupServiceNext** can never increase the amount of data returned beyond what was requested at
**WSALookupServiceBegin**, although it is not an error to specify more or fewer flags. The flags specified at a given
**WSALookupServiceNext** apply only to that call.

The *dwControlFlags* LUP_FLUSHPREVIOUS and LUP_RES_SERVICE are exceptions to the combined restrictions rule (because they are behavior flags instead of restriction flags). If either of these flags are used in
**WSALookupServiceNext** they have their defined effect regardless of the setting of the same flags at
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina).

For example, if LUP_RETURN_VERSION is specified at
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) the service provider retrieves records including the version. If LUP_RETURN_VERSION is NOT specified at
**WSALookupServiceNext**, the returned information does not include the version, even though it was available. No error is generated.

Also for example, if LUP_RETURN_BLOB is NOT specified at
[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina) but is specified at
**WSALookupServiceNext**, the returned information does not include the private data. No error is generated.

If the **WSALookupServiceNext** function fails with an error of
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), this indicates that the buffer pointed to by the *lpqsResults* parameter was too small to contain the query results. A new buffer for a [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) should be provided with a size specified by the value pointed to by the *lpdwBufferLength* parameter. This new buffer for the **WSAQUERYSET** needs to have some of the members of the **WSAQUERYSET** specified before calling the **WSALookupServiceNext** function again. At a minimum, the **dwSize** member of the **WSAQUERYSET** must be set to the new size of the buffer.

### Query Results

The following table describes how the query results are represented in the
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure.

| WSAQUERYSET member | Result interpretation |
| --- | --- |
| **dwSize** | Will be set to sizeof( [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is used as a versioning mechanism. |
| **dwOutputFlags** | RESULT_IS_ALIAS flag indicates this is an alias result. |
| **lpszServiceInstanceName** | Referenced string contains service name. |
| **lpServiceClassId** | The GUID corresponding to the service class. |
| **lpVersion** | References version number of the particular service instance. |
| **lpszComment** | Optional comment string specified by service instance. |
| **dwNameSpace** | Namespace in which the service instance was found. |
| **lpNSProviderId** | Identifies the specific namespace provider that supplied this query result. |
| **lpszContext** | Specifies the context point in a hierarchical namespace at which the service is located. |
| **dwNumberOfProtocols** | Undefined for results. |
| **lpafpProtocols** | Undefined for results, all needed protocol information is in the [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpszQueryString** | When *dwControlFlags* includes LUP_RETURN_QUERY_STRING, this parameter returns the unparsed remainder of the *lpszServiceInstanceName* specified in the original query. For example, in a namespace that identifies services by hierarchical names that specify a host name and a file path within that host, the address returned might be the host address and the unparsed remainder might be the file path. If the *lpszServiceInstanceName* is fully parsed and LUP_RETURN_QUERY_STRING is used, this parameter is **NULL** or points to a zero-length string. |
| **dwNumberOfCsAddrs** | Indicates the number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures, with one complete transport address contained within each element. |
| **lpBlob** | (Optional) This is a pointer to a provider-specific entity. |

**Windows Phone 8:** The **WSALookupServiceNextW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSALookupServiceNextW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSALookupServiceNext as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Bluetooth and WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsalookupservicenext)

[WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicebegina)

[WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)