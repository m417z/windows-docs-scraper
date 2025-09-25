# WTS_RCM_DRAIN_STATE enumeration

## Description

Contains information about the drain state of the Remote Desktop Session Host (RD Session Host) server. A server in drain mode will not accept new connections, but it will reconnect users to existing sessions.

## Constants

### `WTS_DRAIN_STATE_NONE`

There has been no change in the drain state.

### `WTS_DRAIN_IN_DRAIN`

The server is in drain mode, or it is entering drain mode. (It is not accepting new connections.)

### `WTS_DRAIN_NOT_IN_DRAIN`

The server is not in drain mode, or it is exiting drain mode. (It is accepting new connections.)

## Remarks

This enumeration type is used by the [WTS_SERVICE_STATE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_service_state) structure.