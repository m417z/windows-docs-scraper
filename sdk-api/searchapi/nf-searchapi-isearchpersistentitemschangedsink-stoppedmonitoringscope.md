# ISearchPersistentItemsChangedSink::StoppedMonitoringScope

## Description

Called by a notifications provider to notify the indexer to stop monitoring changes to items within a specified hierarchical scope.

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string that is the address for the scope to stop monitoring.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the notifications provider responsible for monitoring changes in the document store goes offline, it calls **ISearchPersistentItemsChangedSink::StoppedMonitoringScope** to remove the scope from the list of notification sources.