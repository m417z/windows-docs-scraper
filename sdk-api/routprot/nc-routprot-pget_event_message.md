# PGET_EVENT_MESSAGE callback function

## Description

The
**GetEventMessage** function gets an entry from the routing protocol's message queue. The routing protocol uses the queue to inform the router manager of asynchronous events.

## Parameters

### `Event` [out]

Pointer to an event. Information about this event is reported in the associated message. Note that this is not an event object. (The **ROUTING_PROTOCOL_EVENTS** type is declared in Routprot.h.)

This parameter receives one of the following values:

| Value | Meaning |
| --- | --- |
| **ROUTER_STOPPED** | The router protocol shut down successfully. The message is empty for this event. (See [StopProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstop_protocol)) |
| **SAVE_GLOBAL_CONFIG_INFO** | The routing protocol reports that its global configuration information has been changed by an external agent, that is, through means other than [SetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_global_info). The routing protocol requests that the router manager retrieve and permanently store this information. The message is empty for this event. |
| **SAVE_INTERFACE_CONFIG_INFO** | The routing protocol reports that the configuration information associated with one of its interfaces has been changed by an external agent, that is, through means other than [SetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_interface_info). The routing protocol requests that the router manager retrieve and permanently store this information. The message contains the ID of the interface. |
| **UPDATE_COMPLETE** | The routing protocol has completed an autostatic update request from the router manager. The router manager converts received routing information to static. The message contains the index of the interface on which the update was performed, the type of the information received (routes or services), and the result field, which indicates whether the update succeeded. See [DoUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdo_update_routes) and [DoUpdateServices](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374005(v=vs.85)). |

### `Result` [out]

Pointer to a
[MESSAGE](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-message) union. The contents of the message are specific to the reported event.

This parameter is optional; the caller may specify **NULL** for this parameter.

## Return value

If the entry is retrieved successfully, the return value is NO_ERROR.

If the routing protocol's message queue does not contain any entries, the return value is ERROR_NO_MORE_ITEMS.

## See also

[DoUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdo_update_routes)

[DoUpdateServices](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374005(v=vs.85))

[MESSAGE](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-message)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[SetGlobalInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_global_info)

[SetInterfaceInfo](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pset_interface_info)

[StopProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstop_protocol)