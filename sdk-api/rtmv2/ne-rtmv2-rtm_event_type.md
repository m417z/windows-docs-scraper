# RTM_EVENT_TYPE enumeration

## Description

The **RTM_EVENT_TYPE** enumeration enumerates the events that the routing table manager can notify the client about using the
[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback) callback.

## Constants

### `RTM_ENTITY_REGISTERED`

A client has just registered with the routing table manager.

### `RTM_ENTITY_DEREGISTERED`

A client has just unregistered.

### `RTM_ROUTE_EXPIRED`

A route has timed out.

### `RTM_CHANGE_NOTIFICATION`

A change notification has been made.

## See also

[RTM_EVENT_CALLBACK](https://learn.microsoft.com/windows/win32/api/rtmv2/nc-rtmv2-_event_callback)