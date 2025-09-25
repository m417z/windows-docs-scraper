# WTSSBX_MACHINE_DRAIN enumeration

## Description

Contains values that indicate the drain state of a Remote Desktop Session Host (RD Session Host) server. The drain state indicates whether an RD Session Host server is accepting new connections. If the RD Session Host server is currently accepting new connections, its drain state is off. If it is not accepting new connections, its drain state is on.

## Constants

### `WTSSBX_MACHINE_DRAIN_UNSPEC:0`

The drain state of the server is unspecified.

### `WTSSBX_MACHINE_DRAIN_OFF:0x1`

The server is accepting new user sessions.

### `WTSSBX_MACHINE_DRAIN_ON:0x2`

The server is not accepting new user sessions.