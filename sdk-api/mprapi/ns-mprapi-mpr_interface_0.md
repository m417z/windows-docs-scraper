# MPR_INTERFACE_0 structure

## Description

The
**MPR_INTERFACE_0** structure contains information for a particular router interface.

## Members

### `wszInterfaceName`

Pointer to a Unicode string that contains the name of the interface.

### `hInterface`

Handle to the interface.

### `fEnabled`

Specifies whether the interface is enabled. This member is **TRUE** if the interface is enabled, **FALSE** if the interface is administratively disabled.

### `dwIfType`

Specifies the
[type of interface](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type).

### `dwConnectionState`

Specifies the current state of the interface, for example connected, disconnected, or unreachable. For a list of possible states, see
[ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state).

### `fUnReachabilityReasons`

Specifies a value that represents a reason why the interface cannot be reached. See
[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons) for a list of possible values.

### `dwLastError`

Specifies a nonzero value if the interface fails to connect.

## See also

[MprAdminInterfaceEnum](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfaceenum)

[MprAdminInterfaceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacegetinfo)

[ROUTER_CONNECTION_STATE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_connection_state)

[ROUTER_INTERFACE_TYPE](https://learn.microsoft.com/windows/desktop/api/mprapi/ne-mprapi-router_interface_type)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)

[Unreachability Reasons](https://learn.microsoft.com/windows/desktop/RRAS/unreachability-reasons)