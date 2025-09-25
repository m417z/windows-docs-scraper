# ROUTER_CONNECTION_STATE enumeration

## Description

The
**ROUTER_CONNECTION_STATE** type enumerates the possible states of an interface on a router.

## Constants

### `ROUTER_IF_STATE_UNREACHABLE`

The interface is unreachable. For a list of possible reasons, see
[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons).

### `ROUTER_IF_STATE_DISCONNECTED`

The interface is reachable but disconnected.

### `ROUTER_IF_STATE_CONNECTING`

The interface is in the process of connecting.

### `ROUTER_IF_STATE_CONNECTED`

The interface is connected.

## Remarks

These states are sometimes referred to as *operational states*.

## See also

[MPR_INTERFACE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_0)

[MPR_INTERFACE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_1)

[Router Management Enumerated Types](https://learn.microsoft.com/windows/desktop/RRAS/router-management-enumerations)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons)