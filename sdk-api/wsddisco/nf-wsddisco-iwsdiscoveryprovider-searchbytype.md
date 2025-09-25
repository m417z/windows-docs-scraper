# IWSDiscoveryProvider::SearchByType

## Description

Initializes a search for [WS-Discovery](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf) hosts by device type.

## Parameters

### `pTypesList` [in, optional]

Pointer to a [WSD_NAME_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_name_list) structure that represents the list of discovery provider types to search for. May be **NULL**.

### `pScopesList` [in, optional]

Pointer to a [WSD_URI_LIST](https://learn.microsoft.com/windows/desktop/api/wsdtypes/ns-wsdtypes-wsd_uri_list) structure that represents the list of discovery provider scopes to search for. May be **NULL**.

### `pszMatchBy` [in, optional]

Matching rule used for scopes. May be **NULL**.

### `pszTag` [in, optional]

Optional identifier tag for this search. May be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The length in characters of *pszMatchBy* exceeds WSD_MAX_TEXT_LENGTH (8192) or the length in characters of *pszTag* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_ABORT** | A callback interface has not been attached. You must call [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) before calling this method. |
| **E_OUTOFMEMORY** | Not enough memory exists to perform the operation. |

## Remarks

**SearchByType** initiates a WS-Discovery [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) in an attempt to locate discovery hosts matching the provided criteria. This method allows matching by types, scopes, some combination of the two, or matching all discovery capable devices (when no scopes or types are provided).

*pszMatchBy* should be provided if and only if *pScopesList* is also provided. This call may result in one or more [Add](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-add) callbacks. If any **Add** callbacks are issued before the search completes, a [SearchComplete](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchcomplete) callback will be issued; otherwise, a [SearchFailed](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchfailed) callback will be issued.

*pszTag* is an optional user provided string which will be fed back in either callback, allowing the caller to associate the callback with the original query.

For information about troubleshooting applications calling this method, see [Troubleshooting WSDAPI Applications](https://learn.microsoft.com/windows/desktop/WsdApi/troubleshooting-wsdapi-applications).

## See also

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)