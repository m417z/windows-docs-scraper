# IWSDiscoveryProviderNotify::SearchFailed

## Description

Is called to indicate a user initiated search has failed.

## Parameters

### `hr` [in]

Cause of the search failure which initiated this callback. A value of **S_FALSE** indicates the search completed without issuing any Add callbacks.

### `pszTag` [in, optional]

Optional identifier tag for this search. May be **NULL**.

## Return value

The return value is not meaningful. An implementer should return **S_OK**.

## Remarks

[SearchComplete](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchcomplete) is called if any responses were successfully received.

**SearchFailed** is called if a user initiated query does not result in a response. In this case, the value of the *hr* parameter will be S_FALSE. **SearchFailed** can optionally be called if errors occur in the attempted transmission of the query, since query transmission is not necessarily synchronous. *pszTag* will match the user supplied tag from the query, and should be used to identify which query failed.

The interval between initiating the search with [SearchByType](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbytype) or [SearchById](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbyid) and receiving a **SearchFailed** notification is a maximum of 10 seconds, based on MATCH_TIMEOUT from [WS-Discovery](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf) and amended by the [DPWS Appendix I](https://specs.xmlsoap.org/ws/2005/05/devprof/devicesprofile.pdf). The interval between initiating the search with [SearchByAddress](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-searchbyaddress) and receipt of a **SearchFailed** notification is typically 21 seconds, but can be a maximum of 150 seconds.

**Note** Multiple simultaneous calls may be made to **SearchFailed** by the provider, so it is essential that shared data be synchronized in this callback.

## See also

[IWSDiscoveryProviderNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovidernotify)