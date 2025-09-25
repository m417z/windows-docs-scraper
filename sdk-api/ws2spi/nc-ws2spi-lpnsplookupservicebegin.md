# LPNSPLOOKUPSERVICEBEGIN callback function

## Description

The
**NSPLookupServiceBegin** function initiates a client query of a name service provider that is constrained by the information contained within a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure.

**NSPLookupServiceBegin** only returns a handle, which should be used by subsequent calls to
[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext) to get the actual results. Because this operation cannot be canceled, it should be implemented to execute quickly. While it is acceptable to initiate a network query, this function should not require a response to return successfully.

## Parameters

### `lpProviderId` [in]

A pointer to the name service provider identifier to query.

### `lpqsRestrictions` [in]

A pointer to the search criteria. See Remarks.

### `lpServiceClassInfo` [in]

A pointer to the [WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow) structure that contains schema information for the service.

### `dwControlFlags` [in]

A value that controls the depth of the search.

| Value | Meaning |
| --- | --- |
| **LUP_DEEP**<br><br>0x0001 | Queries down the hierarchy of a provider as opposed to just the first level. |
| **LUP_CONTAINERS**<br><br>0x0002 | Returns containers only. |
| **LUP_NOCONTAINERS**<br><br>0x0004 | Returns no containers. |
| **LUP_NEAREST**<br><br>0x0008 | If possible, returns results in the order of distance. The measure of distance is provider specific. |
| **LUP_RETURN_NAME**<br><br>0x0010 | Retrieves the name as **lpszServiceInstanceName**. |
| **LUP_RETURN_TYPE**<br><br>0x0020 | Retrieves the type as **lpServiceClassId**. |
| **LUP_RETURN_VERSION**<br><br>0x0040 | Retrieves the version as **lpVersion**. |
| **LUP_RETURN_COMMENT**<br><br>0x0080 | Retrieves the comment as **lpszComment**. |
| **LUP_RETURN_ADDR**<br><br>0x0100 | Retrieves the addresses as **lpcsaBuffer**. |
| **LUP_RETURN_BLOB**<br><br>0x0200 | Retrieves the private data as **lpBlob**. |
| **LUP_RETURN_ALIASES**<br><br>0x0400 | Any available alias information is to be returned in successive calls to [NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext), and each alias returned will have the **RESULT_IS_ALIAS** flag set. |
| **LUP_RETURN_QUERY_STRING**<br><br>0x0800 | Retrieves the query string as **lpszQueryString**. |
| **LUP_RETURN_ALL**<br><br>0x0ff0 | Retrieves information including the name, type, version, comment, address, blob, aliases, and query string. |
| **LUP_FLUSHCACHE**<br><br>0x1000 | If the provider has cached information, ignore the cache and query the namespace itself. |
| **LUP_FLUSHPREVIOUS**<br><br>0x2000 | Used as a value for the *dwControlFlags* parameter in [NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext). Setting this flag instructs the provider to discard the last result set, which was too large for the supplied buffer, and move on to the next result set. |
| **LUP_NON_AUTHORITATIVE**<br><br>0x4000 | Indicates that the namespace provider should included non-authoritative results for names. |
| **LUP_RES_RESERVICE**<br><br>0x8000 | Indicates whether prime response is in the remote or local part of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure. The other part must be usable in either case. This option applies only to service instance requests. |
| **LUP_SECURE**<br><br>0x8000 | Indicates that the namespace provider should use a secure query. This option only applies to name query requests. |
| **LUP_RETURN_PREFERRED_NAMES**<br><br>0x10000 | Indicates that the namespace provider should return only preferred names. |
| **LUP_ADDRCONFIG**<br><br>0x100000 | Indicates that the namespace provider should return the address configuration. |
| **LUP_DUAL_ADDR**<br><br>0x200000 | Indicates that the namespace provider should return the dual addresses. This option only applies to dual-mode sockets (IPv6 and IPv4 mapped addresses). |

### `lphLookup` [out]

A pointer to the handle to be used in subsequent calls to
[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext) in order to retrieve the results set.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database, but it does not have the correct associated data that is resolved for. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Service is unknown. The service cannot be found in the specified namespace. |

## Remarks

If **LUP_CONTAINERS** is specified in a call, avoid all other restriction values. If any are supplied, the name service provider must decide if it can support this restriction over the containers. If not, it should return an error.

Some name service providers may have other means of finding containers. For example, containers can all be of some well-known type, or of a set of well-known types, and therefore a query restriction could be created for finding them. No matter what other means the name service provider has for locating containers, **LUP_CONTAINERS** and **LUP_NOCONTAINERS** take precedence. Therefore, if a query restriction is given that includes containers, specifying **LUP_NOCONTAINERS** will prevent the container items from being returned. Similarly, no matter what the query restriction, if **LUP_CONTAINERS** is given, only containers should be returned. If a namespace does not support containers and **LUP_CONTAINERS** is specified, it should return [WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The preferred method of obtaining the containers within another container, is the call:

```cpp
dwStatus = NSPLookupServiceBegin(
    lpqsRestrictions,
    LUP_CONTAINERS,
    lphLookup);

```

followed by the requisite number of
[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext) calls. This will return all containers contained immediately within the starting context; that is, it is not a deep query. With this, one can map the address space structure by walking the hierarchy, perhaps enumerating the content of selected containers. Subsequent uses of
**NSPLookupServiceBegin** use the containers returned from a previous call.

### Forming Queries

As mentioned, a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure is used as an input parameter to
**NSPLookupServiceBegin** to qualify the query. The following table lists **WSAQUERYSET** member names and describes how the
**WSAQUERYSET** is used to construct a query. When a member is marked as (Optional) a null pointer can be supplied, indicating that the parameter will not be used as a search criteria. For more information, see [Query-Related Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2).

| WSAQUERYSET member name | Query interpretation |
| --- | --- |
| **dwSize** | Will be set to sizeof([WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is a versioning mechanism. |
| **dwOutputFlags** | Ignored for queries. |
| **lpszServiceInstanceName** | Optional. Referenced string contains service name. The semantics for wildcarding within the string are not defined, but can be supported by certain namespace providers. |
| **lpServiceClassId** | Required. GUID corresponding to the service class. |
| **lpVersion** | Optional. References desired version number and provides version comparison semantics (that is, version must match exactly, or version must be not less than the value supplied). |
| **lpszComment** | Ignored for queries. |
| **dwNameSpace** | Identifier of a single namespace in which to constrain the search, or **NS_ALL** to include all namespaces. |
| **lpNSProviderId** | Optional. References the GUID of a specific namespace provider and limits the query to this provider only. |
| **lpszContext** | Optional. Specifies the starting point of the query in a hierarchical namespace. |
| **dwNumberOfProtocols** | Size, in bytes, of the number of entries in the protocol constraint array, can be zero. |
| **lpafpProtocols** | Optional. A references to an array of [AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols) structures. Only services that use these protocols will be returned. It is permissible for the value **AF_UNSPEC** to appear as a protocol family value, signifying a wildcard. Namespace providers may supply information about any service that uses the corresponding protocol, regardless of address family. |
| **lpszQueryString** | Optional. Some namespaces (such as whois++) support rich SQL-like queries contained in a simple text string. This parameter is used to specify that string. |
| **dwNumberOfCsAddrs** | Ignored for queries. |
| **lpcsaBuffer** | Ignored for queries. |
| **lpBlob** | Optional. A pointer to a provider-specific entity. |

## See also

[AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols)

[NSPLookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupserviceend)

[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext)

[NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)