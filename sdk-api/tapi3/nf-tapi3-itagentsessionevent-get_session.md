# ITAgentSessionEvent::get_Session

## Description

The
**get_Session** method gets a pointer to the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) on which the event occurred.

## Parameters

### `ppSession` [out]

Pointer to the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppSession* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface returned by **ITAgentSessionEvent::get_Session**. The application must call **Release** on the
[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession) interface to free resources associated with it.

## See also

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[ITAgentSessionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsessionevent)