# EVT_SUBSCRIBE_FLAGS enumeration

## Description

Defines the possible values that specify when to start subscribing to events.

## Constants

### `EvtSubscribeToFutureEvents:1`

Subscribe to only future events that match the query criteria.

### `EvtSubscribeStartAtOldestRecord:2`

Subscribe to all existing and future events that match the query criteria.

### `EvtSubscribeStartAfterBookmark:3`

Subscribe to all existing and future events that match the query criteria that begin after the bookmarked event. If you include the EvtSubscribeStrict flag, the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) function fails if the bookmarked event does not exist. If you do not include the EvtSubscribeStrict flag and the bookmarked event does not exist, the subscription begins with the event that is after the event that is closest to the bookmarked event.

### `EvtSubscribeOriginMask:3`

A bitmask that you can use to determine which of the following flags is set:

* EvtSubscribeToFutureEvents
* EvtSubscribeStartAtOldestRecord
* EvtSubscribeStartAfterBookmark

### `EvtSubscribeTolerateQueryErrors:0x1000`

Complete the subscription even if the part of the query generates an error (is not well formed). The service validates the syntax of the XPath query to determine if it is well formed. If the validation fails, the service parses the XPath into individual expressions. It builds a new XPath beginning with the left most expression. The service validates the expression and if it is valid, the service adds the next expression to the XPath. The service repeats this process until it finds the expression that is failing. It then uses the valid expressions that it found beginning with the leftmost expression as the XPath query (which means that you may not get the events that you expected). If no part of the XPath is valid, the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) call fails.

### `EvtSubscribeStrict:0x10000`

Forces the [EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe) call to fail if you specify EvtSubscribeStartAfterBookmark and the bookmarked event is not found (the return value is ERROR_NOT_FOUND). Also, set this flag if you want to receive notification in your callback when event records are missing.

## Remarks

The EvtSubscribeToFutureEvents, EvtSubscribeStartAtOldestRecord, and EvtSubscribeStartAfterBookmark flags are mutually exclusive.

## See also

[EvtSubscribe](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtsubscribe)