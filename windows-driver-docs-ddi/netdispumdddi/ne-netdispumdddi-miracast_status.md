# MIRACAST_STATUS enumeration

## Description

Specifies status types that the user-mode display driver uses to report Miracast connection status.

## Constants

### `MIRACAST_STATUS_CRITICAL_ERROR`

An unspecified error occurred, and the Miracast connected session cannot continue.

### `MIRACAST_STATUS_MISSING_KEEPALIVE`

The Miracast sink failed to respond to the protocol keep-alive message.

### `MIRACAST_STATUS_SINK_DISOCNNECT_REQUEST`

The Miracast sink requested that it be disconnected.

### `MIRACAST_STATUS_INSUFFICIENT_BANDWIDTH`

The bandwidth of the wireless connection has changed such that the current mode cannot be sustained.

### `MIRACAST_STATUS_SINK_FAILED_STANDARD_MODE_CHANGE`

The Miracast sink failed to set a standard Video Electronics Standards Association (VESA) setting, Consumer Electronics Association (CEA) standard setting, or a hand-held mode change.

### `MIRACAST_STATUS_COMPANION_DRIVER_DISCONNECT`

### `MIRACAST_STATUS_FORCE_UINT32`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.