# WTSSBX_MACHINE_SESSION_MODE enumeration

## Description

Contains values that indicate the session mode of a Remote Desktop Session Host (RD Session Host) server.

## Constants

### `WTSSBX_MACHINE_SESSION_MODE_UNSPEC:0`

The session mode of the server is unspecified.

### `WTSSBX_MACHINE_SESSION_MODE_SINGLE:0x1`

The server is in single session mode. It can only accept one session per user.

### `WTSSBX_MACHINE_SESSION_MODE_MULTIPLE:0x2`

The server is in multiple session mode. It can accept multiple sessions per user.