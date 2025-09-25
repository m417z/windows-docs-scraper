# WSASetServiceW function

## Description

The
**WSASetService** function registers or removes from the registry a service instance within one or more namespaces.

## Parameters

### `lpqsRegInfo` [in]

A pointer to the service information for registration or deregistration.

### `essoperation` [in]

A value that determines that operation requested. This parameter can be one of the values from the WSAESETSERVICEOP enumeration type defined in the *Winsock2.h* header file.

| Value | Meaning |
| --- | --- |
| **RNRSERVICE_REGISTER** | Register the service. For SAP, this means sending out a periodic broadcast. This is an NOP for the DNS namespace. For persistent data stores, this means updating the address information. |
| **RNRSERVICE_DEREGISTER** | Remove the service from the registry. For SAP, this means stop sending out the periodic broadcast. This is an NOP for the DNS namespace. For persistent data stores this means deleting address information. |
| **RNRSERVICE_DELETE** | Delete the service from dynamic name and persistent spaces. For services represented by multiple [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures (using the SERVICE_MULTIPLE flag), only the specified address will be deleted, and this must match exactly the corresponding **CSADDR_INFO** structure that was specified when the service was registered. |

### `dwControlFlags` [in]

Service install flags value that further controls the operation performed of the **WSASetService** function. The possible values for this parameter are defined in the *Winsock2.h* header file.

| Flag | Meaning |
| --- | --- |
| **SERVICE_MULTIPLE** | Controls scope of operation. When this flag is not set, service addresses are managed as a group. A register or removal from the registry invalidates all existing addresses before adding the given address set. When set, the action is only performed on the given address set. A register does not invalidate existing addresses and a removal from the registry only invalidates the given set of addresses. |

## Return value

The return value for
**WSASetService** is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to install the Service. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more required parameters were invalid or missing. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *Ws2_32.dll* has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

The **WSASetService** function can be used to affect a specific namespace provider, all providers associated with a specific namespace, or all providers across all namespaces.

The available values for *essOperation* and *dwControlFlags* combine to control operation of the **WSASetService** function as shown in the following table.

| Operation | Flags | Service already exists | Service does not exist |
| --- | --- | --- | --- |
| RNRSERVICE_REGISTER | None | Overwrites the object. Uses only addresses specified. The object is REGISTERED. | Creates a new object. Uses only addresses specified. Object is REGISTERED. |
| RNRSERVICE_REGISTER | SERVICE_MULTIPLE | Updates the object. Adds new addresses to the existing set. The object is REGISTERED. | Creates a new object. Uses all addresses specified. Object is REGISTERED. |
| RNRSERVICE_DEREGISTER | None | Removes all addresses, but does not remove the object from the namespace. The object is removed from the registry. | WSASERVICE_NOT_FOUND |
| RNRSERVICE_DEREGISTER | SERVICE_MULTIPLE | Updates the object. Removes only addresses that are specified. Only marks the object as DEREGISTERED if no addresses are present. Does not remove the object from the namespace. | WSASERVICE_NOT_FOUND |
| RNRSERVICE_DELETE | None | Removes the object from the namespace. | WSASERVICE_NOT_FOUND |
| RNRSERVICE_DELETE | SERVICE_MULTIPLE | Removes only addresses that are specified. Only removes object from the namespace if no addresses remain. | WSASERVICE_NOT_FOUND |

Publishing services to directories, such as Active Directory Services, is restricted based on access control lists (ACLs). For more information, see [Security Issues for Service Publication](https://learn.microsoft.com/windows/desktop/AD/security-issues-for-service-publication).

When the *dwControlFlags* parameter is set to **SERVICE_MULTIPLE**, an application can manage its addresses independently. This is useful when the application wants to manage its protocols individually or when the service resides on more than one computer. For instance, when a service uses more than one protocol, it may find that one listening socket aborts but the other sockets remain operational. In this case, the service could remove the aborted address from the registry without affecting the other addresses.

When the *dwControlFlags* parameter is set to **SERVICE_MULTIPLE**, an application must not let stale addresses remain in the object. This can happen if the application aborts without issuing a DEREGISTER request. When a service registers, it should store its addresses. On its next invocation, the service should explicitly remove these old stale addresses from the registry before registering new addresses.

**Note** If ANSI character strings are used, there is a chance that the [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) data in *lpqsRegInfo* may not contain any results after this function returns. This is because the ANSI version of this method, **WSASetServiceA**, converts the ANSI data in **WSAQUERYSET** to Unicode internally, but does not convert the results back to ANSI. This primarily impacts transports that return a "service record handle" used to uniquely identify a record. To work around this issue, applications should use Unicode string data in **WSAQUERYSET** when calling this function.

### Service Properties

The following table describes how service property data is represented in a
[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) structure. Fields labeled as (Optional) can contain a null pointer.

| WSAQUERYSET member | Service property description |
| --- | --- |
| **dwSize** | Must be set to sizeof ([WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is a versioning mechanism. |
| **dwOutputFlags** | Not applicable and ignored. |
| **lpszServiceInstanceName** | Referenced string contains the service instance name. |
| **lpServiceClassId** | The GUID corresponding to this service class. |
| **lpVersion** | (Optional) Supplies service instance version number. |
| **lpszComment** | (Optional) An optional comment string. |
| **dwNameSpace** | See table that follows. |
| **lpNSProviderId** | See table that follows. |
| **lpszContext** | (Optional) Specifies the starting point of the query in a hierarchical namespace. |
| **dwNumberOfProtocols** | Ignored. |
| **lpafpProtocols** | Ignored. |
| **lpszQueryString** | Ignored. |
| **dwNumberOfCsAddrs** | The number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures referenced by **lpcsaBuffer**. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures that contain the address(es) that the service is listening on. |
| **lpBlob** | (Optional) This is a pointer to a provider-specific entity. |

As illustrated in the following, the combination of the **dwNameSpace** and **lpNSProviderId** members determine that namespace providers are affected by this function.

| **dwNameSpace** | **lpNSProviderId** | Scope of impact |
| --- | --- | --- |
| Ignored | Non-null | The specified name-space provider. |
| A valid name- space identifier | Null | All name-space providers that support the indicated namespace. |
| NS_ALL | Null | All name-space providers. |

**Windows Phone 8:** The **WSASetServiceW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSASetServiceW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSASetService as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Bluetooth and WSASetService](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsasetservice)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)