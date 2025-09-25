# MPR40_SERVICE_CHARACTERISTICS structure

## Description

The
**MPR_SERVICE_CHARACTERISTICS** structure contains information used to register a routing protocol with the router manager.

## Members

### `dwVersion`

On input, specifies the version of RRAS currently running.

On output, the routing protocol should specify the version of RRAS that it requires.

The symbol MS_ROUTER_VERSION in the header file Routprot.h is defined to be the RRAS version for a given implementation.

### `dwProtocolId`

Specifies the routing protocol that the router manager requests the DLL to register. (A common name space is used for all protocol families.)

### `fSupportedFunctionality`

On input, specifies the functionality that the router manager supports.

On output, the routing protocol should reset these flags to indicate the subset of functionality that it supports. If this routing protocol does not provide services, **fSupportedFunctionality** should be zero.

This parameter is one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ROUTING** | The protocol participates in multi-protocol routing by importing routing table manager APIs. There is one routing table manager that maintains a table for each protocol family (such as IP and IPX). |
| **SERVICES** | The protocol assumes responsibility for managing services (such as IPX SAP), and provides Service Table Management APIs. |
| **DEMAND_UPDATE_ROUTES** | The protocol is able to perform autostatic updates of routes when requested by the router manager. |
| **DEMAND_UPDATE_SERVICES** | The protocol is able to perform autostatic updates of services when requested by the router manager. |

### `pfnIsService`

Pointer to an implementation of the
[IsService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pis_service) function for this routing protocol.

### `pfnUpdateServices`

### `pfnCreateServiceEnumerationHandle`

Pointer to an implementation of the
[CreateServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_service_enumeration_handle) function for this routing protocol.

### `pfnEnumerateGetNextService`

Pointer to an implementation of the
[EnumerateGetNextService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-penumerate_get_next_service) function for this routing protocol.

### `pfnCloseServiceEnumerationHandle`

Pointer to an implementation of the
[CloseServiceEnumerationHandle](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pclose_service_enumeration_handle) function for this routing protocol.

### `pfnGetServiceCount`

Pointer to an implementation of the
[GetServiceCount](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pget_service_count) function for this routing protocol.

### `pfnCreateStaticService`

Pointer to an implementation of the
[CreateStaticService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pcreate_static_service) function for this routing protocol.

### `pfnDeleteStaticService`

Pointer to an implementation of the
[DeleteStaticService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pdelete_static_service) function for this routing protocol.

### `pfnBlockConvertServicesToStatic`

Pointer to an implementation of the
[BlockConvertServicesToStatic](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pblock_convert_services_to_static) function for this routing protocol.

### `pfnBlockDeleteStaticServices`

Pointer to an implementation of the
[BlockDeleteStaticServices](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pblock_delete_static_services) function for this routing protocol.

### `pfnGetFirstOrderedService`

Pointer to an implementation of the
[GetFirstOrderedService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pget_first_ordered_service) function for this routing protocol.

### `pfnGetNextOrderedService`

Pointer to an implementation of the
[GetNextOrderedService](https://learn.microsoft.com/windows/desktop/api/stm/nc-stm-pget_next_ordered_service) function for this routing protocol.

## Remarks

The members of this structure are pointers to Service Table Management functions implemented in the routing protocol DLL. The routing protocol fills in the address values for these pointers during a call to the
[RegisterProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pregister_protocol) function.

Only routing protocol DLLs that support services need to fill in the
**MPR_SERVICE_CHARACTERISTICS** structure.

For a complete description of a particular function pointed to by one of the structure members, see the reference page for that function.

To use this structure, the user should add -DMPR50=1 to the compiler flags.

## See also

[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics)

[Protocol Identifiers](https://learn.microsoft.com/windows/desktop/RRAS/protocol-identifiers)

[RegisterProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pregister_protocol)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[Routing Protocol Interface Structures](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-structures)