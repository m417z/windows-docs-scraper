# _EVENT_CALLBACK callback function

## Description

The
**RTM_EVENT_CALLBACK** callback is used by the routing table manager to inform a client that the specified event occurred.

## Parameters

### `RtmRegHandle`

Handle to the client to which the routing table manager is sending the notification.

### `EventType`

Specifies the event about which the routing table manager is notifying the client. The following values are used.

| Value | Meaning |
| --- | --- |
| **RTM_ENTITY_REGISTERED** | A client has just registered with the routing table manager. |
| **RTM_ENTITY_DEREGISTERED** | A client has just unregistered. |
| **RTM_ROUTE_EXPIRED** | A route has timed out. |
| **RTM_CHANGE_NOTIFICATION** | A change notification has been made. |

### `Context1`

For RTM_ENTITY_REGISTERED calls: Contains the handle to the entity that registered.

For RTM_ENTITY_DEREGISTERED calls: Contains the handle to the entity that unregistered.

For RTM_ROUTE_EXPIRED calls: Contains the handle to the route that timed out.

For RTM_CHANGE_NOTIFICATION calls: Contains the handle to the change notification.

### `Context2`

For RTM_ENTITY_REGISTERED calls: Contains a pointer to the
[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info) structure referred to by the handle in *Context1*. If the client must retain this information, the client must copy it to a structure it has allocated.

For RTM_ENTITY_DEREGISTERED calls: Contains a pointer to the
[RTM_ENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_info) structure referred to by the handle in *Context1*. If the client must retain this information, the client must copy it to a structure it has allocated.

For RTM_ROUTE_EXPIRED calls: Contains a pointer to the
[RTM_ROUTE_INFO](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_route_info) structure referred to by the handle in *Context1*. If the client must retain this information, the client must copy it to a structure it has allocated.

For RTM_CHANGE_NOTIFICATION calls: Contains the notification context that was given to the client by a previous call to
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification).

## Return value

If the routing table manager issues an RTM_ROUTE_EXPIRED callback, and the client returns to the routing table manager the value ERROR_NOT_SUPPORTED, the routing table manager will delete the route from the routing table.

All other errors returned by the client are ignored.

## Remarks

After a client has registered for change notification, the routing table manager uses this callback to keep the client informed about events.

If a client receives an
**RTM_EVENT_CALLBACK** for the RTM_ENTITY_REGISTERED or RTM_ENTITY_DEREGISTERED events, the client must not make calls to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity),
[RtmDeregisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmderegisterentity), or
[RtmGetRegisteredEntities](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetregisteredentities) in the context of this callback.

If a client receives an
**RTM_EVENT_CALLBACK** for the RTM_CHANGE_NOTIFICATION event, the client must not call
[RtmRegisterForChangeNotification](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterforchangenotification) in the context of this callback.

## See also

[RTM_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/rtmv2/ne-rtmv2-rtm_event_type)

[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity)