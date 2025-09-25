# tagPRIORITIZE_FLAGS enumeration

## Description

Used by [PrioritizeMatchingURLs](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcatalogmanager2-prioritizematchingurls) to specify how to process items the indexer has previously failed to index.

## Constants

### `PRIORITIZE_FLAG_RETRYFAILEDITEMS:0x1`

Indicates that the indexer should reattempt to index items that it failed to index previously.

### `PRIORITIZE_FLAG_IGNOREFAILURECOUNT:0x2`

Indicates that the indexer should continue to reattempt indexing items regardless of the number of times the indexer has failed to index them previously.

## See also

**Conceptual**

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[PRIORITY_LEVEL](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-priority_level)

[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)

[ROWSETEVENT_TYPE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_type)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)