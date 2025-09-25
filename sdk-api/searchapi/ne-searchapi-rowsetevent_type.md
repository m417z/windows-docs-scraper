# ROWSETEVENT_TYPE enumeration

## Description

Describes the type of change to the rowset's data.

## Constants

### `ROWSETEVENT_TYPE_DATAEXPIRED:0`

Indicates that data backing the rowset has expired, and that a new rowset should be requested.

### `ROWSETEVENT_TYPE_FOREGROUNDLOST:1`

Indicates that an item that did have foreground priority in the prioritization stack has been demoted, because someone else prioritized themselves ahead of this query.

### `ROWSETEVENT_TYPE_SCOPESTATISTICS:2`

Indicates that the scope statistics are to be obtained.

## Remarks

This enumeration is used in the [IRowsetEvents::OnRowsetEvent](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-irowsetevents-onrowsetevent) method to describe the type of event that affects a rowset.

The **ROWSETEVENT_TYPE_SCOPESTATISTICS** event gives you the same information available from the [IRowsetPrioritization::GetScopeStatistics](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-irowsetprioritization-getscopestatistics) method call, but through a push mechanic, as follows:

* The event arises if the prioritization API has been used to request a non-default prioritization level, and a non-zero statistics event frequency.
* The event arises only when statistics actually change, and the interval specified in the [IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization) has elapsed (the interval does not guarantee the frequency of the event).
* This event is guaranteed to raise a "bounce zero" state (zero items remaining to be added, zero modifies remaining), provided that a non-zero event has been raised.
* The indexer may process items without sending this event, if the queue empties before the statistics event frequency.

Check out the [SearchEvents code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-searchevents).

## See also

**Conceptual**

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[Notifications Process (Windows Search)](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-support)

[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)

[PRIORITY_LEVEL](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-priority_level)

[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)