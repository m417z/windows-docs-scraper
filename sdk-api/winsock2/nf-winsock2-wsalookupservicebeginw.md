# WSALookupServiceBeginW function

## Description

The
**WSALookupServiceBegin** function initiates a client query that is constrained by the information contained within a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure.
**WSALookupServiceBegin** only returns a handle, which should be used by subsequent calls to
[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) to get the actual results.

## Parameters

### `lpqsRestrictions` [in]

A pointer to the search criteria. See the Remarks for details.

### `dwControlFlags` [in]

A set of flags that controls the depth of the search.

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
| **LUP_RETURN_ALIASES**<br><br>0x0400 | Any available alias information is to be returned in successive calls to [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta), and each alias returned will have the RESULT_IS_ALIAS flag set. |
| **LUP_RETURN_QUERY_STRING**<br><br>0x0800 | Retrieves the query string used for the request. |
| **LUP_RETURN_ALL**<br><br>0x0FF0 | A set of flags that retrieves all of the LUP_RETURN_* values. |
| **LUP_FLUSHPREVIOUS**<br><br>0x1000 | Used as a value for the *dwControlFlags* parameter in [WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta). Setting this flag instructs the provider to discard the last result set, which was too large for the specified buffer, and move on to the next result set. |
| **LUP_FLUSHCACHE**<br><br>0x2000 | If the provider has been caching information, ignores the cache, and queries the namespace itself. |
| **LUP_RES_SERVICE**<br><br>0x8000 | This indicates whether prime response is in the remote or local part of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure. The other part needs to be usable in either case. |

### `lphLookup` [out]

A handle to be used when calling
[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) in order to start retrieving the results set.

## Return value

The return value is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were missing or invalid for this provider. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The name was found in the database but no data matching the given restrictions was located. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No such service is known. The service cannot be found in the specified name space.<br><br>This error is returned for a bluetooth service discovery request if no remote bluetooth devices were found. |

## Remarks

The *lpqsRestrictions* parameter points to a buffer containing a [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure. At a minimum, the **dwSize** member of the **WSAQUERYSET** must be set to the length of the buffer before calling the
**WSALookupServiceBegin** function. Applications can restrict the query by specifying other members in the **WSAQUERYSET**.

In most instances, applications interested in only a particular transport protocol should constrain their query by address family and protocol using the **dwNumberOfProtocols** and **lpafpProtocols** members of the [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) rather than by specifiying the namespace in the **dwNameSpace** member.

Information on supported network transport protocols can be retreived using the [EnumProtocols](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-enumprotocolsa), [WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa), [WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols), or [WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32) function.

It is also possible to constrain the query to a single namespace. For example, a query that only wants results from DNS (not results from the local hosts file and other naming services) would set the **dwNameSpace** member to NS_DNS. For example, a bluetooth device discovery would set the **dwNameSpace** member to NS_BTH.

Applications can also restrict the query to a specific namespace provider by specifying a pointer to the GUID for the provider in the **lpNSProviderId** member.

Information on namespace providers on the local computer can be retrieved using the [WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa), [WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa), [WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32), or [WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32) function.

If LUP_CONTAINERS is specified in a call, other restriction values should be avoided. If any are specified, it is up to the name service provider to decide if it can support this restriction over the containers. If it cannot, it should return an error.

Some name service providers can have other means of finding containers. For example, containers might all be of some well-known type, or of a set of well-known types, and therefore a query restriction can be created for finding them. No matter what other means the name service provider has for locating containers, LUP_CONTAINERS and LUP_NOCONTAINERS take precedence. Hence, if a query restriction is given that includes containers, specifying LUP_NOCONTAINERS will prevent the container items from being returned. Similarly, no matter the query restriction, if LUP_CONTAINERS is given, only containers should be returned. If a namespace does not support containers, and LUP_CONTAINERS is specified, it should simply return [WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The preferred method of obtaining the containers within another container, is the call:

```cpp
dwStatus = WSALookupServiceBegin(
      lpqsRestrictions,
      LUP_CONTAINERS,
      lphLookup);

```

This call is followed by the requisite number of
[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta) calls. This will return all containers contained immediately within the starting context; that is, it is not a deep query. With this, one can map the address space structure by walking the hierarchy, perhaps enumerating the content of selected containers. Subsequent uses of
**WSALookupServiceBegin** use the containers returned from a previous call.

As mentioned above, a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure is used as an input parameter to **WSALookupBegin** in order to qualify the query. The following table indicates how the
**WSAQUERYSET** is used to construct a query. When a parameter is marked as (Optional) a **NULL** pointer can be specified, indicating that the parameter will not be used as a search criteria. See section
[Query-Related Data Structures](https://learn.microsoft.com/windows/desktop/WinSock/name-resolution-data-structures-2) for additional information.

| WSAQUERYSET member | Query interpretation |
| --- | --- |
| **dwSize** | Must be set to sizeof([WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is a versioning mechanism. |
| **dwOutputFlags** | Ignored for queries. |
| **lpszServiceInstanceName** | (Optional) Referenced string contains service name. The semantics for wildcarding within the string are not defined, but can be supported by certain namespace providers. |
| **lpServiceClassId** | (Required) The GUID corresponding to the service class. |
| **lpVersion** | (Optional) References desired version number and provides version comparison semantics (that is, version must match exactly, or version must be not less than the value specified). |
| **lpszComment** | Ignored for queries. |
| **dwNameSpace**<br><br>See the Important note that follows. | Identifier of a single namespace in which to constrain the search, or NS_ALL to include all namespaces. |
| **lpNSProviderId** | (Optional) References the GUID of a specific namespace provider, and limits the query to this provider only. |
| **lpszContext** | (Optional) Specifies the starting point of the query in a hierarchical namespace. |
| **dwNumberOfProtocols** | Size of the protocol constraint array, can be zero. |
| **lpafpProtocols** | (Optional) References an array of [AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols) structure. Only services that utilize these protocols will be returned. |
| **lpszQueryString** | (Optional) Some namespaces (such as whois++) support enriched SQL-like queries that are contained in a simple text string. This parameter is used to specify that string. |
| **dwNumberOfCsAddrs** | Ignored for queries. |
| **lpcsaBuffer** | Ignored for queries. |
| **lpBlob** | (Optional) This is a pointer to a provider-specific entity. |

**Important** In most instances, applications interested in only a particular transport protocol should constrain their query by address family and protocol rather than by namespace. This would allow an application that needs to locate a TCP/IP service, for example, to have its query processed by all available namespaces such as the local hosts file, DNS, and NIS.

**Windows Phone 8:** The **WSALookupServiceBeginW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSALookupServiceBeginW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSALookupServiceBegin as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Bluetooth and WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsalookupservicebegin-for-service-discovery)

[EnumProtocols](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-enumprotocolsa)

[WSAEnumNameSpaceProviders](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersa)

[WSAEnumNameSpaceProvidersEx](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnamespaceprovidersexa)

[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa)

[WSALookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupserviceend)

[WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsalookupservicenexta)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[WSCEnumNameSpaceProviders32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceproviders32)

[WSCEnumNameSpaceProvidersEx32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumnamespaceprovidersex32)

[WSCEnumProtocols](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols)

[WSCEnumProtocols32](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wscenumprotocols32)