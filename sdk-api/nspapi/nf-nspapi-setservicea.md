# SetServiceA function

## Description

The
**SetService** function registers or removes from the registry a network service within one or more namespaces. The function can also add or remove a network service type within one or more namespaces.

**Note** The
**SetService** function is obsolete. The functions detailed in
[Protocol-Independent Name Resolution](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-name-resolution-2) provide equivalent functionality in Windows Sockets 2. For the convenience of Windows Sockets 1.1 developers, the reference material is as follows.

## Parameters

### `dwNameSpace` [in]

The namespace, or a set of default namespaces, within which the function will operate.

Use one of the following constants to specify a namespace.

| Value | Meaning |
| --- | --- |
| **NS_DEFAULT** | A set of default namespaces. The function queries each namespace within this set. The set of default namespaces typically includes all the namespaces installed on the system. System administrators, however, can exclude particular namespaces from the set. NS_DEFAULT is the value that most applications should use for *dwNameSpace*. |
| **NS_DNS** | The Domain Name System used in the Internet to resolve the name of the host. |
| **NS_NDS** | The NetWare 4 provider. |
| **NS_NETBT** | The NetBIOS over TCP/IP layer. All Windows systems register their computer names with NetBIOS. This namespace is used to convert a computer name to an IP address that uses this registration. |
| **NS_SAP** | The NetWare Service Advertising Protocol. This can access the NetWare bindery, if appropriate. NS_SAP is a dynamic namespace that enables the registration of services. |
| **NS_TCPIP_HOSTS** | Lookup value in the \<systemroot>\system32\drivers\etc\posts file. |
| **NS_TCPIP_LOCAL** | Local TCP/IP name resolution mechanisms, including comparisons against the local host name and lookup value in the cache of host to IP address mappings. |

### `dwOperation` [in]

The operation that the function will perform. Use one of the following values to specify an operation:

| Value | Meaning |
| --- | --- |
| **SERVICE_REGISTER** | Register the network service with the namespace. This operation can be used with the SERVICE_FLAG_DEFER and SERVICE_FLAG_HARD bit flags. |
| **SERVICE_DEREGISTER** | Remove from the registry the network service from the namespace. This operation can be used with the SERVICE_FLAG_DEFER and SERVICE_FLAG_HARD bit flags. |
| **SERVICE_FLUSH** | Perform any operation that was called with the SERVICE_FLAG_DEFER bit flag set to one. |
| **SERVICE_ADD_TYPE** | Add a service type to the namespace. <br><br>For this operation, use the **ServiceSpecificInfo** member of the [SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure pointed to by *lpServiceInfo* to pass a [SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa) structure. You must also set the **ServiceType** member of the **SERVICE_INFO** structure. Other **SERVICE_INFO** members are ignored. |
| **SERVICE_DELETE_TYPE** | Remove a service type, added by a previous call specifying the SERVICE_ADD_TYPE operation, from the namespace. |

### `dwFlags` [in]

A set of bit flags that modify the function's operation. You can set one or more of the following bit flags:

| Value | Meaning |
| --- | --- |
| **SERVICE_FLAG_DEFER** | This bit flag is valid only if the operation is SERVICE_REGISTER or SERVICE_DEREGISTER. <br><br>If this bit flag is one, and it is valid, the namespace provider should defer the registration or deregistration operation until a SERVICE_FLUSH operation is requested. |
| **SERVICE_FLAG_HARD** | This bit flag is valid only if the operation is SERVICE_REGISTER or SERVICE_DEREGISTER. <br><br>If this bit flag is one, and it is valid, the namespace provider updates any relevant persistent store information when the operation is performed.<br><br>For example: If the operation involves deregistration in a namespace that uses a persistent store, the namespace provider would remove the relevant persistent store information. |

### `lpServiceInfo` [in]

A pointer to a
[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa) structure that contains information about the network service or service type.

### `lpServiceAsyncInfo` [in, optional]

Reserved for future use. Must be set to **NULL**.

### `lpdwStatusFlags` [out]

A set of bit flags that receive function status information. The following bit flag is defined:

| Value | Meaning |
| --- | --- |
| **SET_SERVICE_ PARTIAL_SUCCESS** | One or more namespace providers were unable to successfully perform the requested operation. |

## Return value

If the function fails, the return value is SOCKET_ERROR. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** can return the following extended error value.

| Error code | Meaning |
| --- | --- |
| **ERROR_ALREADY_ REGISTERED** | The function tried to register a service that was already registered. |

## See also

[GetService](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getservicea)

[SERVICE_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_infoa)

[SERVICE_TYPE_INFO_ABS](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-service_type_info_absa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

## Remarks

> [!NOTE]
> The nspapi.h header defines SetService as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).