# PREGISTER_PROTOCOL callback function

## Description

The
**RegisterProtocol** function registers the routing protocol with the router manager. It also informs the router manager of the functionality that the routing protocol supports.

## Parameters

### `pRoutingChar` [in, out]

On input, pointer to an
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) structure.

On output, receives pointers to functions implemented for the routing protocol.

See the reference page for the
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) structure for more information on how to use it with the
**RegisterProtocol** function.

### `pServiceChar` [in, out]

On input, pointer to an
[MPR_SERVICE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-mpr40_service_characteristics) structure.

On output, receives pointers to functions implemented for the routing protocol.

See the reference page for the
[MPR_SERVICE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-mpr40_service_characteristics) structure for more information on how to use it with the
**RegisterProtocol** function.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is ERROR_NOT_SUPPORTED.

## Remarks

All routing protocol DLLs must fill in values for the
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) structure.

Routing protocol DLLs that provide services must fill in values for the
[MPR_SERVICE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-mpr40_service_characteristics) structure. If a routing protocol DLL does not provide services, it should fill in zero for the **fSupportedFunctionality** member of this structure, but need not fill in values for the other members.

Routing protocols are implemented in user-mode DLLs. A single DLL may implement multiple routing protocols. Therefore, router manager may call
**RegisterProtocol** multiple times, once for each routing protocol implemented in the DLL.

## See also

[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics)

[MPR_SERVICE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/stm/ns-stm-mpr40_service_characteristics)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)