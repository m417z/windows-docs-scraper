# ITAgentSessionEvent::get_Event

## Description

The
**get_Event** method gets an
[AGENT_SESSION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_event) descriptor of the event that occurred.

## Parameters

### `pEvent` [out]

Pointer to the
[AGENT_SESSION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_event) descriptor of the event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## See also

[AGENT_SESSION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_event)

[ITAgentSessionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsessionevent)