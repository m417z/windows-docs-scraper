# ITTAPIEventNotification::Event

## Description

The
**Event** method is called by TAPI to determine the response to an asynchronous event notification. The application implements a set of case statements that use *TapiEvent* to determine the type of event being signaled, then calls **IUnknown::QueryInterface** on *pEvent* to obtain the appropriate event interface pointer. Each event defined by TAPI 3 has an interface associated with it. The specific events handled depend on the needs of the application.

## Parameters

### `TapiEvent` [in]

[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) indicator of the event.

### `pEvent` [in]

Pointer to an **IDispatch** interface of the object associated with this event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

You must call the
[ITTAPI::put_EventFilter](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-put_eventfilter) method to set the event filter mask and enable reception of events. If you do not call **ITTAPI::put_EventFilter**, your application will not receive any events.

## See also

[Events overview](https://learn.microsoft.com/windows/desktop/Tapi/events)

[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification)

[Register Events code snippet](https://learn.microsoft.com/windows/desktop/Tapi/register-events)

[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event)