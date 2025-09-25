# LPNSPV2SETSERVICEEX callback function

## Description

The
**NSPv2SetServiceEx** function registers or deregisters a name or service instance within a namespace of a namespace service provider version-2 (NSPv2) provider.

## Parameters

### `hAsyncCall` [in]

A handle returned from the previous call to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) used for asynchronous calls.

### `lpProviderId` [in]

A pointer to the GUID of the specific namespace provider in which the name or service is registered.

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

A set of flags that controls the operation requested.

The possible values for this parameter are defined in the *Winsock2.h* header file.

| Value | Meaning |
| --- | --- |
| **SERVICE_MULTIPLE**<br><br>0x00000001 | Control the scope of the operation. <br><br>When this value is set, the action is only performed on the given address set. A register operation does not invalidate existing addresses and a deregister operation only invalidates the given set of addresses.<br><br>When this value is absent, service addresses are managed as a group. A register or deregister invalidates all existing addresses before adding the given address set. |

### `lpvClientSessionArg` [in]

A pointer to the client session.

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (that is, 1) if the routine fails and it must set the appropriate error code using
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The calling routine does not have sufficient privileges to install the service. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One or more parameters were invalid, or missing, for this provider. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. This error can also be returned if the specified *dwControlCode* is an unrecognized command. |
| **[WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Service is unknown. The service cannot be found in the specified namespace. |

## Remarks

The
**NSPv2SetServiceEx** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPv2SetServiceEx** function can only be used for operations on NS_EMAIL namespace providers.

The
[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup) function is called each time a new client process begins using namespace provider. Providers may use the
client session argument pointed to by the *ppvClientSessionArg* parameter to store information about this session. This client session argument can be passed to the **NSPv2SetServiceEx** function in the *lpvClientSessionArg* parameter.

The **NSPv2SetServiceEx** function is optional, dependent on the requirements of the NSPv2 provider. If the **NSPv2SetServiceEx** function isn't implemented, then the NSPv2 function pointer can be to a stub function that always returns **NO_ERROR**.

The following table lists the possible combination of values for *essOperation* and *dwControlFlags* parameters.

| essOperation | dwControlFlags | Service already exists | Service does not exist |
| --- | --- | --- | --- |
| **RNRSERVICE_REGISTER** | None | Overwrites the object. Uses only addresses specified. Object is REGISTERED. | Creates a new object. Uses only addresses specified. Object is REGISTERED. |
| **RNRSERVICE_REGISTER** | **SERVICE_MULTIPLE** | Updates object. Adds new addresses to existing set. Object is REGISTERED. | Creates a new object. Uses all addresses specified. Object is REGISTERED. |
| **RNRSERVICE_DEREGISTER** | None | Removes all addresses, but does not remove object from namespace. Object is DEREGISTERED. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DEREGISTER** | **SERVICE_MULTIPLE** | Updates object. Removes only addresses that are specified. Only mark object as DEREGISTERED if no addresses are present. Does not remove from the namespace. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DELETE** | None | Removes object from the namespace. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |
| **RNRSERVICE_DELETE** | **SERVICE_MULTIPLE** | Removes only addresses that are specified. Only removes object from the namespace if no addresses remain. | [WSASERVICE_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) |

When the *dwControlFlags* parameter is set to **SERVICE_MULTIPLE**, this enables an application to manage its addresses independently. This is useful when the application must manage its protocols individually or when the service resides on more than one computer. For example, when a service uses more than one protocol, one listening socket may abort, but the other sockets remain operational. In this example, the service could deregister the aborted address without affecting the other addresses.

When using **SERVICE_MULTIPLE**, an application must not let old addresses remain in the object. This can happen if the application aborts without issuing a **RNRSERVICE_DEREGISTER** request. When a service registers, it should store its addresses. On its next call, the service should explicitly deregister these old addresses before registering new addresses.

 If the **NSPv2SetServiceEx** function isn't implemented, then calls to that function should be intercepted by a stub function that returns [WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP). The NSPv2 function pointer to the unimplemented **NSPv2SetServiceEx** function in the [NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine) structure should point be to the stub function.

### Service Properties

The following table lists [WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w) member names and describes how service property data is represented. Members labeled as optional and dependent on the requirements of the NSPv2 provider may be supplied as a **NULL** pointer when unused by the namespace provider.

| WSAQUERYSET2 member name | Service property description |
| --- | --- |
| **dwSize** | Set to the sizeof([WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)). This is a versioning mechanism. |
| **lpszServiceInstanceName** | A string that contains the service instance name. |
| **lpVersion** | The service instance version number. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszComment** | A comment string. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNameSpace** | The namespace identifier. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpNSProviderId** | The provider identifier. Note that the namespace provider identifier is also passed in the *lpProviderId* parameter. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszContext** | The starting point of the query in a hierarchical namespace. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNumberOfProtocols** | The size, in bytes, of the number of entries in the protocol constraint array. This member can be zero.This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpafpProtocols** | An array of [AFPROTOCOLS](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-afprotocols) structures. This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpszQueryString** | Some namespaces (such as whois++) support rich SQL-like queries contained in a simple text string. This parameter is used to specify that string.This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **dwNumberOfCsAddrs** | The number of elements in the array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures referenced by *lpcsaBuffer*. |
| **lpcsaBuffer** | A pointer to an array of [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structures that contain the address or addresses that the service is listening on. |
| **dwOutputFlags** | This member is optional, dependent on the requirements of the NSPv2 service provider. |
| **lpBlob** | A pointer to a provider-specific entity. This member is required for the NS_EMAIL namespace. This member is optional, dependent on the requirements for other NSPv2 service providers. |

**Note** It is acceptable for the **iProtocol** member of the
[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) structure to contain the manifest constant **IPROTOCOL_ANY**, indicating a wildcard value. The namespace provider should substitute an acceptable value for the given address family and socket type.

## See also

[CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info)

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceEnd](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupserviceend)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)