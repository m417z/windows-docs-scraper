# CLUSION_REASON enumeration

## Description

These flags enumerate reasons why URLs are included or excluded from the current crawl scope. The
[ISearchCrawlScopeManager::IncludedInCrawlScopeEx](https://learn.microsoft.com/windows/desktop/api/searchapi/nf-searchapi-isearchcrawlscopemanager-includedincrawlscopeex) method returns a pointer to this enumeration to explain why a specified URL is either included or excluded from the current crawl scope.

## Constants

### `CLUSIONREASON_UNKNOWNSCOPE:0`

The URL has been excluded because its scope in unknown. There is no scope that would include or exclude this URL so it is excluded by default.

### `CLUSIONREASON_DEFAULT:1`

The URL has been included or excluded by a default rule. Default rules are set during setup or first run.

### `CLUSIONREASON_USER:2`

The URL has been included or excluded by a user rule. User rules are set either by the user through Control Panel or by a calling application through the [ISearchCrawlScopeManager](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-isearchcrawlscopemanager) interface.

### `CLUSIONREASON_GROUPPOLICY:3`

 Not Supported.