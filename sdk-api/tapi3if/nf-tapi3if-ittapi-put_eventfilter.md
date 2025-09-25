# ITTAPI::put_EventFilter

## Description

The
**put_EventFilter** method sets the event filter mask. The mask is a series of ORed members of the
[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) enumeration.

**Note** You must call this method to enable reception of events. If you do not call **ITTAPI::put_EventFilter**, your application will not receive any events.

## Parameters

### `lFilterMask` [in]

Event filter mask.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Events overview](https://learn.microsoft.com/windows/desktop/Tapi/events)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification)

[Register Events code snippet](https://learn.microsoft.com/windows/desktop/Tapi/register-events)

[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event)

[get_EventFilter](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-get_eventfilter)