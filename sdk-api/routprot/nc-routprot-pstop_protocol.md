# PSTOP_PROTOCOL callback function

## Description

The
**StopProtocol** function causes the routing protocol to perform an orderly shutdown.

## Parameters

### `unnamedParam1`

## Return value

If the routing protocol shutdown successfully (synchronous completion), the return value is NO_ERROR.

If routing protocol is shutting down asynchronously, the return value is ERROR_PROTOCOL_STOP_PENDING. In this case, the protocol reports the results of the shutdown through the event message queue.

## See also

[GetEventMessage](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pget_event_message)

[Routing Protocol Interface Functions](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-functions)

[Routing Protocol Interface Reference](https://learn.microsoft.com/windows/desktop/RRAS/routing-protocol-interface-reference)

[StartProtocol](https://learn.microsoft.com/windows/desktop/api/routprot/nc-routprot-pstart_protocol)