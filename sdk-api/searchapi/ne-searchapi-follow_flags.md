# FOLLOW_FLAGS enumeration

## Description

Used to help define behavior when crawling or indexing. These flags are used by the [ISearchCrawlScopeManager::AddDefaultScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-adddefaultscoperule) and
[ISearchCrawlScopeManager::AddUserScopeRule](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-adduserscoperule) methods.

## Constants

### `FF_INDEXCOMPLEXURLS:0x1`

Specifies whether complex URLs (those containing a '?') should be indexed.

### `FF_SUPPRESSINDEXING:0x2`

Follow but do not index this URL.