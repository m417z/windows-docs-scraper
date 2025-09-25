# EvtQuery function

## Description

Runs a query to retrieve events from a channel or log file that match the specified query criteria.

## Parameters

### `Session` [in]

A remote session handle that the [EvtOpenSession](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopensession) function returns. Set to **NULL** to query for events on the local computer.

### `Path` [in]

The name of the channel or the full path to a log file that contains the events that you want to query. You can specify an .evt, .evtx, or.etl log file. The path is required if the *Query* parameter contains an XPath query; the path is ignored if the *Query* parameter contains a structured XML query and the query specifies the path.

### `Query` [in]

A query that specifies the types of events that you want to retrieve. You can specify an XPath 1.0 query or structured XML query. If your XPath contains more than 20 expressions, use a structured XML query. To receive all events, set this parameter to **NULL** or "*".

### `Flags` [in]

One or more flags that specify the order that you want to receive the events and whether you are querying against a channel or log file. For possible values, see the [EVT_QUERY_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_query_flags) enumeration.

## Return value

A handle to the query results if successful; otherwise, **NULL**. If the function returns **NULL**, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

 To get events from the query results, call the [EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext) function. To retrieve events beginning with a specific event in the results, call the [EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek) function.

 You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function with the query results handle when done.

You must only use the query handle that this function returns on the same thread that created the handle.

#### Examples

For an example that shows how to use this function, see [Querying for Events](https://learn.microsoft.com/windows/desktop/WES/querying-for-events).

## See also

[EvtNext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtnext)

[EvtSeek](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtseek)

[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)