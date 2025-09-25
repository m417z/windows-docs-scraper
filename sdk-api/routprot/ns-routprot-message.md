# MESSAGE structure

## Description

The
**MESSAGE** union contains information about an event reported to the router manager through the routing protocol's message queue.

## Members

### `UpdateCompleteMessage`

Provides information associated with an UPDATE_COMPLETE event.

### `InterfaceIndex`

Identifies the interface associated with a SAVE_INTERFACE_CONFIG_INFO event.

## See also

[DoUpdateRoutes](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pdo_update_routes)

[DoUpdateServices](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374005(v=vs.85))

[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[Routing Protocol Interface Structures](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-structures)

[UPDATE_COMPLETE_MESSAGE](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-update_complete_message)