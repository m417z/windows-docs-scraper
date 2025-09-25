# EvtSubscribe function

## Description

Creates a subscription that will receive current and future events from a channel or log file that match the specified query criteria.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to subscribe to events on the local computer.

### `SignalEvent` [in]

The handle to an event object that the service will signal when new events are available that match your query criteria. This parameter must be **NULL** if the *Callback* parameter is not **NULL**.

### `ChannelPath` [in]

The name of the Admin or Operational channel that contains the events that you want to subscribe to (you cannot subscribe to Analytic or Debug channels). The path is required if the *Query* parameter contains an XPath query; the path is ignored if the *Query* parameter contains a structured XML query.

### `Query` [in]

A query that specifies the types of events that you want the subscription service to return. You can specify an XPath 1.0 query or structured XML query. If your XPath contains more than 20 expressions, use a structured XML query. To receive all events, set this parameter to **NULL** or "*".

### `Bookmark` [in]

A handle to a bookmark that identifies the starting point for the subscription. To get a bookmark handle, call the [EvtCreateBookmark](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreatebookmark) function. You must set this parameter if the *Flags* parameter contains the EvtSubscribeStartAfterBookmark flag; otherwise, **NULL**.

### `Context` [in]

A caller-defined context value that the subscription service will pass to the specified callback each time it delivers an event.

### `Callback` [in]

Pointer to your [EVT_SUBSCRIBE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winevt/nc-winevt-evt_subscribe_callback) callback function that will receive the subscription events. This parameter must be **NULL** if the *SignalEvent* parameter is not **NULL**.

### `Flags` [in]

One or more flags that specify when to start subscribing to events. For example, if you specify EvtSubscribeStartAtOldestRecord, the service will retrieve all current and future events that match your query criteria; however, if you specify EvtSubscribeToFutureEvents, the service returns only future events that match your query criteria. For possible values, see the [EVT_SUBSCRIBE_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_subscribe_flags) enumeration.

## Return value

A handle to the subscription if successful; otherwise, **NULL**. If the function returns **NULL**, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function with the subscription handle when done.

## Remarks

 To cancel the subscription, pass the returned subscription handle to the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function.

There are two subscription models: the poll model and the push model. In the push model, you implement a subscription callback and set the *Callback* parameter to your implementation. The service will call your callback for each event that matches your query criteria (or if an error occurs).

In the poll model, you create an event object that the service signals. When signaled, you call the [EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext) function using the subscription handle to enumerate the events. You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function on each event that you enumerate. You then reset the object and wait for the service to signal again. This process repeats until you cancel the subscription.

#### Examples

For an example that shows how to use this function, see [Subscribing to Events](https://learn.microsoft.com/windows/desktop/WES/subscribing-to-events).

## See also

[EVT_SUBSCRIBE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/winevt/nc-winevt-evt_subscribe_callback)

[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)