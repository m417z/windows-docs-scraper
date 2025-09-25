# PDO_UPDATE_ROUTES callback function

## Description

The
**DoUpdateRoutes** function requests the routing protocol to perform a routing information update over the specified interface to obtain static route information. (This process is called an autostatic route update.)

## Parameters

### `InterfaceIndex` [in]

Specifies the interface in the set of interfaces configured on the router.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Description |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | The update operation cannot be performed. |
| **ERROR_INVALID_PARAMETER** | The *InterfaceIndex* parameter is invalid (for example, no interface exists with that index). |

## Remarks

If the function returns NO_ERROR, the update operation started successfully on the interface. Check the routing protocol event queue for a completion event (see
[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message)).

## See also

[DoUpdateServices](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa374005(v=vs.85))

[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)