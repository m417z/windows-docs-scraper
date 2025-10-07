# GetAddressByNameA function

## Description

[**GetAddressByName** is no longer available for use as of Windows Sockets 2. Instead, use the functions detailed in
[Protocol-Independent Name Resolution](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-name-resolution-2).]

The
**GetAddressByName** function queries a namespace, or a set of default namespaces, to retrieve network address information for a specified network service. This process is known as service name resolution. A network service can also use the function to obtain local address information that it can use with the
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function.

## Parameters

### `dwNameSpace` [in]

The namespace, or set of default namespaces, that the operating system should query for network address information.

Use one of the following constants to specify a namespace.

| Value | Meaning |
| --- | --- |
| **NS_DEFAULT** | A set of default namespaces. The function queries each namespace within this set. The set of default namespaces typically includes all the namespaces installed on the system. System administrators, however, can exclude particular namespaces from the set. This is the value that most applications should use for *dwNameSpace*. |
| **NS_DNS** | The Domain Name System (DNS) used in the Internet for host name resolution. |
| **NS_NETBT** | The NetBIOS over TCP/IP layer. All operating systems register their computer names with NetBIOS. This namespace is used to convert a computer name to an IP address that uses this registration. Note that NS_NETBT can access a WINS server to perform the resolution. |
| **NS_SAP** | The NetWare Service Advertising Protocol. This can access the NetWare bindery if appropriate. NS_SAP is a dynamic namespace that allows registration of services. |
| **NS_TCPIP_HOSTS** | Lookup value in the \<systemroot>\system32\drivers\etc\hosts file. |
| **NS_TCPIP_LOCAL** | Local TCP/IP name resolution mechanisms, including comparisons against the local host name and looks up host names and IP addresses in cache of host to IP address mappings. |

Most calls to
**GetAddressByName** should use the special value NS_DEFAULT. This lets a client get by with no knowledge of which namespaces are available on an internetwork. The system administrator determines namespace access. Namespaces can come and go without the client having to be aware of the changes.

### `lpServiceType` [in]

A pointer to a globally unique identifier (GUID) that specifies the type of the network service. The Svcguid.h header file includes definitions of several GUID service types, and macros for working with them.

The Svcguid.h header file is not automatically included by the Winsock2.h header file.

### `lpServiceName` [in, optional]

A pointer to a zero-terminated string that uniquely represents the service name. For example, "MY SNA SERVER".

Setting *lpServiceName* to **NULL** is the equivalent of setting *dwResolution* to RES_SERVICE. The function operates in its second mode, obtaining the local address to which a service of the specified type should bind. The function stores the local address within the **LocalAddr** member of the
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures stored into **lpCsaddrBuffer*.

If *dwResolution* is set to RES_SERVICE, the function ignores the *lpServiceName* parameter.

If *dwNameSpace* is set to NS_DNS, **lpServiceName* is the name of the host.

### `lpiProtocols` [in, optional]

A pointer to a zero-terminated array of protocol identifiers. The function restricts a name resolution attempt to namespace providers that offer these protocols. This lets the caller limit the scope of the search.

If *lpiProtocols* is set to **NULL**, the function retrieves information on all available protocols.

### `dwResolution` [in]

A set of bit flags that specify aspects of the service name resolution process. The following bit flags are defined.

| Value | Meaning |
| --- | --- |
| **RES_SERVICE** | If set, the function retrieves the address to which a service of the specified type should bind. This is the equivalent to setting the *lpServiceName* parameter to **NULL**.<br><br>If this flag is clear, normal name resolution occurs. |
| **RES_FIND_MULTIPLE** | If this flag is set, the operating system performs an extensive search of all namespaces for the service. It asks every appropriate namespace to resolve the service name. If this flag is clear, the operating system stops looking for service addresses as soon as one is found. |
| **RES_SOFT_SEARCH** | This flag is valid if the namespace supports multiple levels of searching.<br><br>If this flag is valid and set, the operating system performs a simple and quick search of the namespace. This is useful if an application only needs to obtain easy-to-find addresses for the service.<br><br>If this flag is valid and clear, the operating system performs a more extensive search of the namespace. |

### `lpServiceAsyncInfo` [in, optional]

Reserved for future use; must be set to **NULL**.

### `lpCsaddrBuffer` [out]

A pointer to a buffer to receive one or more
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) data structures. The number of structures written to the buffer depends on the amount of information found in the resolution attempt. You should assume that multiple structures will be written, although in many cases there will only be one.

### `lpdwBufferLength` [in, out]

A pointer to a variable that, upon input, specifies the size, in bytes, of the buffer pointed to by *lpCsaddrBuffer*.

Upon output, this variable contains the total number of bytes required to store the array of
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. If this value is less than or equal to the input value of **lpdwBufferLength*, and the function is successful, this is the number of bytes actually stored in the buffer. If this value is greater than the input value of **lpdwBufferLength*, the buffer was too small, and the output value of **lpdwBufferLength* is the minimal required buffer size.

### `lpAliasBuffer` [in, out]

A pointer to a buffer to receive alias information for the network service.

If a namespace supports aliases, the function stores an array of zero-terminated name strings into the buffer pointed to by *lpAliasBuffer*. There is a double zero-terminator at the end of the list. The first name in the array is the service's primary name. Names that follow are aliases. An example of a namespace that supports aliases is DNS.

If a namespace does not support aliases, it stores a double zero-terminator into the buffer.

This parameter is optional, and can be set to **NULL**.

### `lpdwAliasBufferLength` [in, out]

A pointer to a variable that, upon input, specifies the size, in elements (characters), of the buffer pointed to by *lpAliasBuffer*.

Upon output, this variable contains the total number of elements (characters) required to store the array of name strings. If this value is less than or equal to the input value of **lpdwAliasBufferLength*, and the function is successful, this is the number of elements actually stored in the buffer. If this value is greater than the input value of **lpdwAliasBufferLength*, the buffer was too small, and the output value of **lpdwAliasBufferLength* is the minimal required buffer size.

If *lpAliasBuffer* is **NULL**, *lpdwAliasBufferLength* is meaningless and can also be **NULL**.

## Return value

If the function succeeds, the return value is the number of
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) data structures written to the buffer pointed to by *lpCsaddrBuffer*.

If the function fails, the return value is SOCKET_ERROR( –1). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns the following extended error value.

| Error code | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by *lpCsaddrBuffer* was too small to receive all of the relevant [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures. Call the function with a buffer at least as large as the value returned in **lpdwBufferLength*. |

## Remarks

This function is a more powerful version of the
[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) function. The
**GetAddressByName** function works with multiple name services.

**Note** The
[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) function has been deprecated by the introduction of the
[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function. Developers creating Windows Sockets 2 applications are urged to use the
**getaddrinfo** function instead of
**gethostbyname**.

The
**GetAddressByName** function lets a client obtain a Windows Sockets address for a network service. The client specifies the service of interest by its service type and service name.

Many name services support a default prefix or suffix that the name service provider considers when resolving service names. For example, in the DNS namespace, if a domain is named "nt.microsoft.com", and "ftp millikan" is provided as input, the DNS software fails to resolve "millikan", but successfully resolves "millikan.nt.microsoft.com".

Note that the
**GetAddressByName** function can search for a service address in two ways: within a particular namespace, or within a set of default namespaces. Using a default namespace, an administrator can specify that certain namespaces will be searched for service addresses only if specified by name. An administrator or namespace—setup program can also control the ordering of namespace searches.

> [!NOTE]
> The nspapi.h header defines GetAddressByName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname)