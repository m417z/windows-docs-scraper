# MPR60_ROUTING_CHARACTERISTICS structure

## Description

The
**MPR_ROUTING_CHARACTERISTICS** structure contains information used to register routing protocols with the router manager.

## Members

### `dwVersion`

On input, specifies the version of RRAS currently running.

On output, the routing protocol should specify the version of RRAS that it requires.

The symbol MS_ROUTER_VERSION in the header file Routprot.h is defined to be the RRAS version for a given implementation.

### `dwProtocolId`

Specifies the routing protocol that the router manager requests the DLL to register. (A common name space is used for all protocol families.)

### `fSupportedFunctionality`

On input, specifies the functionality that the router manager supports.

On output, the routing protocol should reset these flags to indicate the subset of functionality that it supports.

This parameter is a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ROUTING** | The protocol participates in multi-protocol routing by importing routing table manager APIs. There is one routing table manager that maintains a table for each protocol family (such as IP and IPX). |
| **SERVICES** | The protocol assumes responsibility for managing services (such as IPX SAP), and provides Service Table Management APIs. |
| **DEMAND_UPDATE_ROUTES** | The protocol is able to perform autostatic updates of routes when requested by the router manager. |
| **DEMAND_UPDATE_SERVICES** | The protocol is able to perform autostatic updates of services when requested by the router manager. |

### `pfnStartProtocol`

Pointer to an implementation of the
[StartProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstart_protocol) function for this routing protocol.

### `pfnStartComplete`

Pointer to an implementation of the
[StartComplete](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstart_complete) function for this routing protocol.

### `pfnStopProtocol`

Pointer to an implementation of the
[StopProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstop_protocol) function for this routing protocol.

### `pfnGetGlobalInfo`

Pointer to an implementation of the
[GetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_global_info) function for this routing protocol.

### `pfnSetGlobalInfo`

Pointer to an implementation of the
[SetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_global_info) function for this routing protocol.

### `pfnQueryPower`

Pointer to an implementation of the
[QueryPower](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pquery_power) function for this routing protocol.

### `pfnSetPower`

Pointer to an implementation of the
[SetPower](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_power) function for this routing protocol.

### `pfnAddInterface`

Pointer to an implementation of the
[AddInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-padd_interface) function for this routing protocol.

### `pfnDeleteInterface`

Pointer to an implementation of the
[DeleteInterface](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdelete_interface) function for this routing protocol.

### `pfnInterfaceStatus`

Pointer to an implementation of the
[InterfaceStatus](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pinterface_status) function for this routing protocol.

### `pfnGetInterfaceInfo`

Pointer to an implementation of the
[GetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_interface_info) function for this routing protocol.

### `pfnSetInterfaceInfo`

Pointer to an implementation of the
[SetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_interface_info) function for this routing protocol.

### `pfnGetEventMessage`

Pointer to an implementation of the
[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message) function for this routing protocol.

### `pfnUpdateRoutes`

Pointer to an implementation of the
[DoUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdo_update_routes) function for this routing protocol.

### `pfnConnectClient`

Pointer to an implementation of the
[ConnectClient](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pconnect_client) function for this routing protocol.

### `pfnDisconnectClient`

Pointer to an implementation of the
[DisconnectClient](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdisconnect_client) function for this routing protocol.

### `pfnGetNeighbors`

Pointer to an implementation of the
[GetNeighbors](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_neighbors) function for this routing protocol.

### `pfnGetMfeStatus`

Pointer to an implementation of the
[GetMfeStatus](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_mfe_status) function for this routing protocol.

### `pfnMibCreateEntry`

Pointer to an implementation of the
[MibCreate](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_create) function for this routing protocol.

### `pfnMibDeleteEntry`

Pointer to an implementation of the
[MibDelete](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_delete) function for this routing protocol.

### `pfnMibGetEntry`

Pointer to an implementation of the
[MibGet](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get) function for this routing protocol.

### `pfnMibSetEntry`

Pointer to an implementation of the
[MibSet](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_set) function for this routing protocol.

### `pfnMibGetFirstEntry`

Pointer to an implementation of the
[MibGetFirst](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_first) function for this routing protocol.

### `pfnMibGetNextEntry`

Pointer to an implementation of the
[MibGetNext](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_next) function for this routing protocol.

### `pfnMibSetTrapInfo`

Pointer to an implementation of the
[MibSetTrapInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_set_trap_info) function for this routing protocol.

### `pfnMibGetTrapInfo`

Pointer to an implementation of the
[MibGetTrapInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pmib_get_trap_info) function for this routing protocol.

### `pfnProtocolAction`

### `pfnGetStatistics`

### `pfnGetRoutingDomainGlobalInfo`

### `pfnSetRoutingDomainGlobalInfo`

### `pfnBufferFree`

## Remarks

Most of the members of this structure are pointers to functions implemented in the routing protocol DLL. The routing protocol fills in the address values for these pointers during a call to the
[RegisterProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pregister_protocol) function.

For a complete description of a particular function pointed to by one of the structure members, see the reference page for that function.

## See also

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[RegisterProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pregister_protocol)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[Routing Protocol Interface Structures](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-structures)