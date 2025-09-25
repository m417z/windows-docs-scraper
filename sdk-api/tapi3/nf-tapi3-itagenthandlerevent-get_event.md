# ITAgentHandlerEvent::get_Event

## Description

The
**get_Event** method gets the description for the event that has occurred.

## Parameters

### `pEvent` [out]

Pointer to the
[AGENTHANDLER_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agenthandler_event) descriptor.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## See also

[AGENTHANDLER_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agenthandler_event)

[ITAgentHandlerEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandlerevent)