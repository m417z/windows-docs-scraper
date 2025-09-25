# ITAgentEvent::get_Event

## Description

Gets an
[AGENT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_event) descriptor of the event that occurred.

## Parameters

### `pEvent` [out]

Pointer to
[AGENT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_event) descriptor of event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## See also

[AGENT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_event)

[ITAgentEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentevent)