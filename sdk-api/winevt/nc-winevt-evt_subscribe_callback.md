# EVT_SUBSCRIBE_CALLBACK callback function

## Description

Implement this callback if you call the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function to receive events that match your query. The service calls your callback when events that match your query criteria are raised.

## Parameters

### `Action`

Determines whether the *Event* parameter contains an event or an error code. For possible notify action values, see the [EVT_SUBSCRIBE_NOTIFY_ACTION](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_subscribe_notify_action) enumeration.

### `UserContext`

The context that the subscriber passed to the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function.

### `Event`

A handle to the event. The event handle is only valid for the duration of the callback function. You can use this handle with any event log function that takes an event handle (for example, [EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender) or [EvtFormatMessage](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtformatmessage)).

Do not call [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) to close this handle; the service will close the handle when the callback returns.

If the *Action* parameter is EvtSubscribeActionError, cast *Event* to a DWORD to access the Win32 error code.

## Return value

The service ignores the return code that you return.

## Remarks

This callback will block other events from being delivered to your callback, so keep your implementation as short as possible.

If the service encounters an error while setting up the subscription, your callback will not receive any notification that an error occurred.

If the *Flags* parameter of [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) includes EvtSubscribeStrict, your callback will receive notification when event records are missing. In this case, the value of *Event* will be ERROR_EVT_QUERY_RESULT_STALE.

To cancel the subscription, you must close the subscription handle that the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function returns.

#### Examples

For an example that implements **EVT_SUBSCRIBE_CALLBACK** callback function, see [Subscribing to Events](https://learn.microsoft.com/windows/desktop/WES/subscribing-to-events).

## See also

[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)