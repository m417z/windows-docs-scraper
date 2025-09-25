# GetServiceW function

## Description

The
**GetService** function retrieves information about a network service in the context of a set of default namespaces or a specified namespace. The network service is specified by its type and name. The information about the service is obtained as a set of
[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa) data structures.

**Note** The
**GetService** function is a Microsoft-specific extension to the Windows Sockets 1.1 specification. This function is obsolete. For the convenience of Windows Sockets 1.1 developers, this reference material is included.

**Note** The functions detailed in
[Protocol-Independent Name Resolution](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-name-resolution-2) provide equivalent functionality in Windows Sockets 2.

## Parameters

### `dwNameSpace` [in]

The namespace, or a set of default namespaces, that the operating system should query for information about the specified network service.

Use one of the following constants to specify a namespace.

| Value | Meaning |
| --- | --- |
| **NS_DEFAULT** | A set of default namespaces. The operating system queries each namespace within this set. The set of default namespaces typically includes all the namespaces installed on the system. System administrators, however, can exclude particular namespaces from the set. NS_DEFAULT is the value that most applications should use for *dwNameSpace*. |
| **NS_DNS** | The Domain Name System used in the Internet for host name resolution. |
| **NS_NETBT** | The NetBIOS over TCP/IP layer. All operating systems register their computer names with NetBIOS. This namespace is used to resolve a computer name into an IP address using this registration. Note that NS_NETBT can access a WINS server to perform the resolution. |
| **NS_SAP** | The NetWare Service Advertising Protocol. This can access the NetWare bindery if appropriate. NS_SAP is a dynamic namespace that allows registration of services. |
| **NS_TCPIP_HOSTS** | Looks up host names and IP addresses in the <systemroot>\system32\drivers\etc\hosts file. |
| **NS_TCPIP_LOCAL** | Local TCP/IP name resolution mechanisms, including comparisons against the local host name and looks up host names and IP addresses in cache of host to IP address mappings. |

Most calls to
**GetService** should use the special value NS_DEFAULT. This lets a client get by without knowing available namespaces on an internetwork. The system administrator determines namespace access. Namespaces can come and go without the client having to be aware of the changes.

### `lpGuid` [in]

A pointer to a globally unique identifier (GUID) that specifies the type of the network service. The *Svcguid.h* header file includes GUID service types from many well-known services within the DNS and SAP namespaces.

The *Svcguid.h* header file is not automatically included by the *Winsock2.h* header file.

### `lpServiceName` [in]

A pointer to a zero-terminated string that uniquely represents the service name. For example, "MY SNA SERVER."

### `dwProperties` [in]

A set of bit flags that specify the service information that the function retrieves. Each of these bit flag constants, other than PROP_ALL, corresponds to a particular member of the
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) data structure. If the flag is set, the function puts information into the corresponding member of the data structures stored in **lpBuffer*. The following bit flags are defined.

| Value | Meaning |
| --- | --- |
| **PROP_COMMENT** | If this flag is set, the function stores data in the **lpComment** member of the data structures stored in **lpBuffer*. |
| **PROP_LOCALE** | If this flag is set, the function stores data in the **lpLocale** member of the data structures stored in **lpBuffer*. |
| **PROP_DISPLAY_HINT** | If this flag is set, the function stores data in the **dwDisplayHint** member of the data structures stored in **lpBuffer*. |
| **PROP_VERSION** | If this flag is set, the function stores data in the **dwVersion** member of the data structures stored in **lpBuffer*. |
| **PROP_START_TIME** | If this flag is set, the function stores data in the **dwTime** member of the data structures stored in **lpBuffer*. |
| **PROP_MACHINE** | If this flag is set, the function stores data in the **lpMachineName** member of the data structures stored in **lpBuffer*. |
| **PROP_ADDRESSES** | If this flag is set, the function stores data in the **lpServiceAddress** member of the data structures stored in **lpBuffer*. |
| **PROP_SD** | If this flag is set, the function stores data in the **ServiceSpecificInfo** member of the data structures stored in **lpBuffer*. |
| **PROP_ALL** | If this flag is set, the function stores data in all of the members of the data structures stored in **lpBuffer*. |

### `lpBuffer` [out]

A pointer to a buffer to receive an array of
[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa) structures and associated service information. Each
**NS_SERVICE_INFO** structure contains service information in the context of a particular namespace. Note that if *dwNameSpace* is NS_DEFAULT, the function stores more than one structure into the buffer; otherwise, just one structure is stored.

Each
[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa) structure contains a
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure. The members of these
**SERVICE_INFO** structures will contain valid data based on the bit flags that are set in the *dwProperties* parameter. If a member's corresponding bit flag is not set in *dwProperties*, the member's value is undefined.

The function stores the
[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa) structures in a consecutive array, starting at the beginning of the buffer. The pointers in the contained
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structures point to information that is stored in the buffer between the end of the
**NS_SERVICE_INFO** structures and the end of the buffer.

### `lpdwBufferSize` [in, out]

A pointer to a variable that, on input, contains the size, in bytes, of the buffer pointed to by *lpBuffer*. On output, this variable contains the number of bytes required to store the requested information. If this output value is greater than the input value, the function has failed due to insufficient buffer size.

### `lpServiceAsyncInfo` [in, optional]

Reserved for future use. Must be set to **NULL**.

## Return value

If the function succeeds, the return value is the number of
[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa) structures stored in **lpBuffer*. Zero indicates that no structures were stored.

If the function fails, the return value is SOCKET_ERROR ( – 1). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which returns one of the following extended error values.

| Error code | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer pointed to by *lpBuffer* is too small to receive all of the requested information. Call the function with a buffer at least as large as the value returned in **lpdwBufferSize*. |
| **ERROR_SERVICE_NOT_FOUND** | The specified service was not found, or the specified namespace is not in use. The function return value is zero in this case. |

## See also

[NS_SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-ns_service_infoa)

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)

[SetService](https://learn.microsoft.com/previous-versions/windows/desktop/qos/qos-structures)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The nspapi.h header defines GetService as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).