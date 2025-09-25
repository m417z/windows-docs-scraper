# ISearchPersistentItemsChangedSink::StartedMonitoringScope

## Description

Called by a notifications provider to notify the indexer to monitor changes to items within a specified hierarchical scope.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string that is the start address for the scope to be monitored.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When notification loss occurs, a notification agent comes online and calls [StartedMonitoringScope](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchitemschangedsink-startedmonitoringscope), which permits an index-managed notification source to add itself to a list of "monitored scopes". The indexer starts an incremental crawl of the corresponding document store. The indexer crawls these scopes incrementally until the extreme conditions that caused the loss of notifications are no longer present. This method ensures that any changes in the store that occur during a period of notification loss are detected.

Under normal circumstances, the list of monitored scopes is not used. Notification loss is rare, and usually occurs only when disk space is extremely low.