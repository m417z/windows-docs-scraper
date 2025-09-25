# ITAgentEvent::get_Agent

## Description

The
**get_Agent** method gets the interface for the agent on which the event occurred.

## Parameters

### `ppAgent` [out]

Pointer to
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppAgent* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent) interface returned by **ITAgentEvent::get_Agent**. The application must call **Release** on the
**ITAgent** interface to free resources associated with it.

## See also

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[ITAgentEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentevent)