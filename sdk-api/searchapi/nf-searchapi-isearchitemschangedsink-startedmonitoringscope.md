# ISearchItemsChangedSink::StartedMonitoringScope

## Description

Permits an index-managed notification source to add itself to a list of "monitored scopes".

## Parameters

### `pszURL` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string that is the start address for the scope of monitoring.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a notification agent comes online it calls [StartedMonitoringScope](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchpersistentitemschangedsink-startedmonitoringscope) which adds the scope to the list of sources. If the source is new (removed previously by [StoppedMonitoringScope](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchpersistentitemschangedsink-stoppedmonitoringscope), or never created in the first place) the indexer starts an incremental crawl of the corresponding document store. This is designed to pick up any changes in the store that occurred while the notification agent was offline.

## See also

**Conceptual**

[ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager)

[ISearchItemsChangedSink](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchitemschangedsink)

[ISearchScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchscoperule)

[Notifying the Index of Changes](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-notifyingofchanges)

**Reference**

[StoppedMonitoringScope](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchitemschangedsink-stoppedmonitoringscope)