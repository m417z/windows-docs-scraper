# WTSSBX_MACHINE_INFO structure

## Description

Contains information about a computer and its current state.

## Members

### `ClientConnectInfo`

A [WTSSBX_MACHINE_CONNECT_INFO](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_machine_connect_info) structure that contains information about the computer.

### `wczFarmName`

A Unicode string that contains the name of the farm in RD Connection Broker that this computer belongs to. This string cannot exceed 256 characters.

### `InternalIPAddress`

A [WTSSBX_IP_ADDRESS](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_ip_address) structure that contains the internal IP address of this computer. RD Connection Broker uses this IP address for redirection purposes.

### `dwMaxSessionsLimit`

The maximum number of sessions that this computer can accept.

### `ServerWeight`

The server weight value of this computer. RD Connection Broker uses this value for load balancing.

### `SingleSessionMode`

A value of the [WTSSBX_MACHINE_SESSION_MODE](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_machine_session_mode) enumeration type that indicates the computer's session mode.

### `InDrain`

A value of the [WTSSBX_MACHINE_DRAIN](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_machine_drain) enumeration type that indicates whether the computer is accepting new user sessions.

### `MachineState`

A value of the [WTSSBX_MACHINE_STATE](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_machine_state) enumeration type that indicates the state of the computer.

## See also

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)