# LPNSPSETSERVICE callback function

## Description

The
**NSPSetService** function registers or deregisters a service instance within a namespace.

## Parameters

### `lpProviderId` [in]

A pointer to the GUID of the specific namespace provider in which the service is registered.

### `lpServiceClassInfo` [in]

The service class schema information.

### `lpqsRegInfo` [in]

The property information to be updated upon registration.

### `essOperation` [in]

The type of operation requested.

This parameter can be one of the values from the **WSAESETSERVICEOP** enumeration type defined in the *Winsock2.h* header file.

| Value | Meaning |
| --- | --- |
| **RNRSERVICE_REGISTER**<br><br>0 | Register the service. For the Service Advertising Protocol (SAP) namespace used within a NetWare environment, this means sending a periodic broadcast. This is an NOP for the Domain Name System (DNS) namespace. For persistent data stores this means updating the address information. |
| **RNRSERVICE_DEREGISTER**<br><br>1 | Deregister the service. For the SAP namespace, this means stop sending the periodic broadcast. This is a NOP for the DNS namespace. For persistent data stores this means deleting address information. |
| **RNRSERVICE_DELETE**<br><br>2 | Delete the service from dynamic name and persistent spaces. For services represented by multiple [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures (using the SERVICE_MULTIPLE flag), only the supplied address will be deleted, and this must match exactly the corresponding **CSADDR_INFO** structure supplied when the service was registered. |

### `dwControlFlags` [in]

A set of flags that controls the service operation requested.

The possible values for this parameter are defined in the *Winsock2.h* header file.

| Value | Meaning |
| --- | --- |
| **SERVICE_MULTIPLE**<br><br>0x00000001 | Control the scope of the operation. <br><br>When this value is set, the action is only performed on the given address set. A register operation does not invalidate existing addresses and a deregister operation only invalidates the given set of addresses.<br><br>When this value is absent, service addresses are managed as a group. A register or deregister invalidates all existing addresses before adding the given address set. |

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to install the service. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Service is unknown. The service cannot be found in the specified namespace. |

## Remarks

The following table lists the available values for *essOperation* and *dwControlFlags*.

| Operation | Flags | Service already exists | Service does not exist |
| --- | --- | --- | --- |
| **RNRSERVICE_REGISTER** | None | Overwrites the object. Uses only addresses specified. Object is REGISTERED. | Creates a new object. Uses only addresses specified. Object is REGISTERED. |
| **RNRSERVICE_REGISTER** | **SERVICE_MULTIPLE** | Updates object. Adds new addresses to existing set. Object is REGISTERED. | Creates a new object. Uses all addresses specified. Object is REGISTERED. |
| **RNRSERVICE_DEREGISTER** | None | Removes all addresses, but does not remove object from namespace. Object is DEREGISTERED. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DEREGISTER** | **SERVICE_MULTIPLE** | Updates object. Removes only addresses that are specified. Only mark object as DEREGISTERED if no addresses are present. Does not remove from the namespace. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DELETE** | None | Removes object from the namespace. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DELETE** | **SERVICE_MULTIPLE** | Removes only addresses that are specified. Only removes object from the namespace if no addresses remain. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |

When the *dwControlFlags* parameter is set to **SERVICE_MULTIPLE**, this enables an application to manage its addresses independently. This is useful when the application must manage its protocols individually or when the service resides on more than one computer. For example, when a service uses more than one protocol, one listening socket may abort, but the other sockets remain operational. In this example, the service could deregister the aborted address without affecting the other addresses.

When using **SERVICE_MULTIPLE**, an application must not let old addresses remain in the object. This can happen if the application aborts without issuing a **RNRSERVICE_DEREGISTER** request. When a service registers, it should store its addresses. On its next call, the service should explicitly deregister these old addresses before registering new addresses.

### Service Properties

The following table lists [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw) member names and describes how service property data is represented. Members labeled as (Optional) can be supplied with a null pointer.

| WSAQUERYSET member name | Service property description |
| --- | --- |
| **dwSize** | Set to the sizeof([WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)). This is a versioning mechanism. |
| **lpszServiceInstanceName** | The referenced string contains the service instance name. |
| **lpServiceClassId** | The GUID that corresponds to this service class. |
| **lpVersion** | Optional. Supplies the service instance version number. |
| **lpszComment** | Optional. An optional comment string. |
| **dwNameSpace** | Ignored for this operation. |
| **lpNSProviderId** | Ignored for this operation. The provider identifier is contained in the *lpProviderId* parameter. |
| **lpszContext** | Optional. The starting point of the query in a hierarchical namespace. |
| **dwNumberOfProtocols** | Ignored for this operation. |
| **lpafpProtocols** | Ignored for this operation. |
| **pszQueryString** | Ignored for this operation. |
| **dwNumberOfCsAddrs** | The number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures referenced by *lpcsaBuffer*. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures that contain the address or addresses that the service is listening on. |
| **dwOutputFlags** | Ignored for this operation. |
| **lpBlob** | Optional. Pointer to a provider-specific entity. |

**Note** It is acceptable for the **iProtocol** member of the
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure to contain the manifest constant **IPROTOCOL_ANY**, indicating a wildcard value. The namespace provider should substitute an acceptable value for the given address family and socket type.

## See also

[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaquerysetw)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)