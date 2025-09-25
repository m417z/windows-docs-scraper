# ITCallHubEvent::get_Event

## Description

The
**get_Event** method returns a pointer to a
[CALLHUB_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callhub_event) enum description of the event that occurred.

## Parameters

### `pEvent` [out]

Pointer to a
[CALLHUB_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callhub_event) enum description of the event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## See also

[CALLHUB_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-callhub_event)

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHubEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhubevent)