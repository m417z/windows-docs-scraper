# ITAgentHandlerEvent::get_AgentHandler

## Description

The
**get_AgentHandler** method gets the
[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler) interface pointer.

## Parameters

### `ppAgentHandler` [out]

Pointer to the
[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler) interface on which the event occurred.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppAgentHandler* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler) interface returned by **ITAgentHandlerEvent::get_AgentHandler**. The application must call **Release** on the
**ITAgentHandler** interface to free resources associated with it.

## See also

[ITAgentHandler](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandler)

[ITAgentHandlerEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagenthandlerevent)