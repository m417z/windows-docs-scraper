# IRowsetPrioritization::GetScopeStatistics

## Description

Gets information describing the scope specified by this query.

## Parameters

### `indexedDocumentCount` [out]

Type: **DWORD***

The total number of documents currently indexed in the scope.

### `oustandingAddCount` [out]

Type: **DWORD***

The total number of documents yet to be indexed in the scope. These documents are not yet included in *indexedDocumentCount*.

### `oustandingModifyCount` [out]

Type: **DWORD***

The total number of documents indexed in the scope that need to be re-indexed. These documents are included in *indexedDocumentCount*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Returns S_OK if successful, **HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)** if there are no indexed documents in the scope, or an error value otherwise.

The **GetScopeStatistics** event can be used to get the number of indexed items in the scope, the number of outstanding docs to be added in the scope, and the number of docs that need to be re-indexed within this scope.

Check out the [SearchEvents code sample](https://learn.microsoft.com/windows/win32/search/-search-sample-searchevents).

## See also

**Conceptual**

[IRowsetEvents](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetevents)

[IRowsetPrioritization](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-irowsetprioritization)

[Indexing Prioritization and Rowset Events in Windows 7](https://learn.microsoft.com/windows/desktop/search/indexing-prioritization-and-rowset-events)

[PRIORITIZE_FLAGS](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-tagprioritize_flags)

[PRIORITY_LEVEL](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-priority_level)

[ROWSETEVENT_ITEMSTATE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_itemstate)

[ROWSETEVENT_TYPE](https://learn.microsoft.com/windows/win32/api/searchapi/ne-searchapi-rowsetevent_type)

**Reference**

[Rowset Properties](https://learn.microsoft.com/windows/desktop/search/-search-sql-rowset-properties)