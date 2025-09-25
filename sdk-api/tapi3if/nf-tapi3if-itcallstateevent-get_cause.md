# ITCallStateEvent::get_Cause

## Description

The
**get_Cause** method gets the cause associated with this event.

## Parameters

### `pCEC` [out]

Pointer to
[CALL_STATE_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state_event_cause) indicator.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCEC* parameter is not a valid pointer. |

## See also

[CALL_STATE_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state_event_cause)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallStateEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallstateevent)