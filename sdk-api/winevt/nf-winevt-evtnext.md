# EvtNext function

## Description

Gets the next event from the query or subscription results.

## Parameters

### `ResultSet` [in]

The handle to a query or subscription result set that the [EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery) function or the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function returns.

### `EventsSize` [in]

The number of elements in the *EventArray* array. The function will try to retrieve this number of elements from the result set.

### `Events` [in]

A pointer to an array of handles that will be set to the handles to the events from the result set.

### `Timeout` [in]

The number of milliseconds that you are willing to wait for a result. Set to INFINITE to indicate no time-out value. If the time-out expires, the last error is set to ERROR_TIMEOUT.

### `Flags` [in]

Reserved. Must be zero.

### `Returned` [out]

The number of handles in the array that are set.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

Call this function in a loop until the function returns **FALSE** and the error code is ERROR_NO_MORE_ITEMS.

For each event that you retrieve, you can then call the [EvtCreateRenderContext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreaterendercontext) and [EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender) functions to render the event.

You must call [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) on each event handle that you receive.

#### Examples

For an example that shows how to use this function, see [Querying for Events](https://learn.microsoft.com/windows/desktop/WES/querying-for-events) and [Subscribing to Events](https://learn.microsoft.com/windows/desktop/WES/subscribing-to-events).

## See also

[EvtQuery](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtquery)

[EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek)

[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)