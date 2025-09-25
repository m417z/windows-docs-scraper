# PQUERY_POWER callback function

## Description

The
*QueryPower* function is reserved for future use. It is not currently called by the router manager. Routing protocols should pass **NULL** as the pointer value for this function in
[MPR_ROUTING_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics)

The [PQUERY_POWER](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-mpr50_routing_characteristics) type defines a pointer to this callback function. *QueryPower* is a placeholder for the application-defined function name.

## Parameters

### `PowerType` [in]

Reserved for future use.

## See also

[SetPower](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_power)