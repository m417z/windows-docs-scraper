# LPNSPV2LOOKUPSERVICEBEGIN callback function

## Description

The
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function initiates a client query of a namespace version-2 service provider that is constrained by the information contained within a
[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure.

## Parameters

### `lpProviderId` [in]

A pointer to the identifier for the namespace service provider to query.

### `lpqsRestrictions` [in]

A pointer to the search criteria. See Remarks.

### `dwControlFlags` [in]

A set of flags that affect the search. This parameter can be a combination of the following values defined in the *Winsock2.h* header file.

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
| **LUP_RETURN_ALIASES**<br><br>0x0400 | Any available alias information is to be returned in successive calls to [NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex), and each alias returned will have the **RESULT_IS_ALIAS** flag set. |
| **LUP_RETURN_QUERY_STRING**<br><br>0x0800 | Retrieves the query string as **lpszQueryString**. |
| **LUP_RETURN_ALL**<br><br>0x0ff0 | Retrieves information including the name, type, version, comment, address, blob, aliases, and query string. |
| **LUP_FLUSHCACHE**<br><br>0x1000 | If the provider has cached information, ignore the cache and query the namespace itself. |
| **LUP_FLUSHPREVIOUS**<br><br>0x2000 | Used as a value for the *dwControlFlags* parameter in [NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex). Setting this flag instructs the provider to discard the last result set, which was too large for the supplied buffer, and move on to the next result set. |
| **LUP_NON_AUTHORITATIVE**<br><br>0x4000 | Indicates that the namespace provider should included non-authoritative results for names. |
| **LUP_RES_RESERVICE**<br><br>0x8000 | Indicates whether prime response is in the remote or local part of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure. The other part must be usable in either case. This option applies only to service instance requests. |
| **LUP_SECURE**<br><br>0x8000 | Indicates that the namespace provider should use a secure query. This option only applies to name query requests. |
| **LUP_RETURN_PREFERRED_NAMES**<br><br>0x10000 | Indicates that the namespace provider should return only preferred names. |
| **LUP_ADDRCONFIG**<br><br>0x100000 | Indicates that the namespace provider should return the address configuration. |
| **LUP_DUAL_ADDR**<br><br>0x200000 | Indicates that the namespace provider should return the dual addresses. This option only applies to dual-mode sockets (IPv6 and IPv4 mapped addresses). |
| **LUP_DISABLE_IDN_ENCODING**<br><br>0x800000 | Indicates that the namespace provider should disable automatic International Domain Names encoding.<br><br>This value is supported on Windows 8 and Windows Server 2012 |

### `lpvClientSessionArg` [out]

A pointer to the client session.

### `lphLookup` [out]

A pointer to the handle to be used in subsequent calls to
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex) in order to retrieve the results set.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (that is, 1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database, but it does not have the correct associated data that is resolved for. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service is unknown. The service cannot be found in the specified namespace. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |

## Remarks

The
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the [NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function can only be used for operations on NS_EMAIL namespace providers.

The
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function only returns a handle, which should be used by subsequent calls to
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex) to get the actual results. Because this operation cannot be canceled, it should be implemented to execute quickly. While it is acceptable to initiate a network query, this function should not require a response to return successfully.

The
[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup) function is called each time a new client process begins using namespace provider. Providers may use the
client session argument pointed to by the *ppvClientSessionArg* parameter to store information about this session. If a value was specified for the client session argument in the call to the **NSPv2Startup** function, then this same client session argument is passed in the *lpvClientSessionArg*  parameter to the [NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function.

If **LUP_CONTAINERS** is specified in a call, avoid all other restriction values. If any are supplied, the name service provider must decide if it can support this restriction over the containers. If not, it should return an error.

Some name service providers may have other means of finding containers. For example, containers can all be of some well-known type, or of a set of well-known types, and therefore a query restriction could be created for finding them. No matter what other means the name service provider has for locating containers, **LUP_CONTAINERS** and **LUP_NOCONTAINERS** take precedence. Therefore, if a query restriction is given that includes containers, specifying **LUP_NOCONTAINERS** will prevent the container items from being returned. Similarly, no matter what the query restriction, if **LUP_CONTAINERS** is given, only containers should be returned. If a namespace does not support containers and **LUP_CONTAINERS** is specified, it should return [WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The preferred method of obtaining the containers within another container, is the call:

```cpp
dwStatus = NSPv2LookupServiceBegin(
    lpProviderId,
    lpqsRestrictions,
    LUP_CONTAINERS,
    lpClientSession,
    lphLookup);

```

followed by the requisite number of
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex) calls. This will return all containers contained immediately within the starting context; that is, it is not a deep query. With this, one can map the address space structure by walking the hierarchy, perhaps enumerating the content of selected containers. Subsequent uses of
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) use the containers returned from a previous call.

### Forming Queries

The
[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) structure is used as an input parameter to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) to qualify the query. The following table lists **WSAQUERYSET2** member names and describes how the
**WSAQUERYSET2** is used to construct a query. Members labeled as optional and dependent on the requirements of the NSPv2 provider may be supplied as a **NULL** pointer when unused as a search criteria by the namespace provider. For more information, see [Query-Related Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2).

| WSAQUERYSET2 member name | Query interpretation |
| --- | --- |
| **dwSize** | Will be set to sizeof([WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)). This is a versioning mechanism. |
| **lpszServiceInstanceName** | A string that contains the service name. The semantics for wildcarding within the string are not defined, but can be supported by certain namespace providers. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpVersion** | The desired version number that provides version comparison semantics (that is, version must match exactly, or version must be not less than the value supplied). This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszComment** | This member is ignored for queries. |
| **dwNameSpace** | The identifier of a single namespace in which to constrain the search, or **NS_ALL** to include all namespaces. |
| **lpNSProviderId** | The GUID of a specific namespace provider that limits the query to this provider only. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszContext** | The starting point of the query in a hierarchical namespace. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNumberOfProtocols** | The size, in bytes, of the number of entries in the protocol constraint array. This member can be zero. |
| **lpafpProtocols** | An array of [AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols) structures. Only services that use these protocols will be returned. It is permissible for the value **AF_UNSPEC** to appear as a protocol family value, signifying a wildcard. Namespace providers may supply information about any service that uses the corresponding protocol, regardless of address family. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszQueryString** | Some namespaces (such as whois++) support rich SQL-like queries contained in a simple text string. This parameter is used to specify that string.This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNumberOfCsAddrs** | This member is ignored for queries. |
| **lpcsaBuffer** | This member is ignored for queries. |
| **dwOutputFlags** | This member is ignored for queries. |
| **lpBlob** | A pointer to a provider-specific entity. This member is optional, dependent on the requirements of the NSPv2 service provider. |

## See also

[AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols)

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASERVICECLASSINFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaserviceclassinfow)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)