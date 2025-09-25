# IWSDiscoveryProviderNotify::SearchComplete

## Description

Called to indicate a user initiated search has successfully completed and no more matches for the search will be accepted.

## Parameters

### `pszTag` [in, optional]

Search tag passed to the [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) search method.

## Return value

The return value is not meaningful. An implementer should return S_OK.

## Remarks

If no responses are received for a given search, then [IWSDiscoveryProviderNotify::SearchFailed](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchfailed) will be called to indicate this.

The interval between initiating the search with [SearchByType](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbytype) or [SearchById](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbyid) and receiving a **SearchComplete** notification is a maximum of 10 seconds, based on MATCH_TIMEOUT from [WS-Discovery](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf) and amended by the [DPWS Appendix I](https://specs.xmlsoap.org/ws/2005/05/devprof/devicesprofile.pdf). The interval between initiating the search with [SearchByAddress](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbyaddress) and receiving a **SearchComplete** notification is a maximum of 150 seconds.

## See also

[IWSDiscoveryProviderNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovidernotify)