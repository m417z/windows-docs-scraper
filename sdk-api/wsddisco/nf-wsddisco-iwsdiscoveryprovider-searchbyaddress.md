# IWSDiscoveryProvider::SearchByAddress

## Description

Initializes a search for [WS-Discovery](https://specs.xmlsoap.org/ws/2005/04/discovery/ws-discovery.pdf) hosts by device address.

## Parameters

### `pszAddress` [in]

The HTTP transport address of the device.

### `pszTag` [in, optional]

Optional identifier tag for this search. May be **NULL**.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *pszAddress* is **NULL**, the length in characters of *pszAddress* exceeds WSD_MAX_TEXT_LENGTH (8192), or the length in characters of *pszTag* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_ABORT** | A callback interface has not been attached. You must call [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) before calling this method. |
| **E_OUTOFMEMORY** | Not enough memory exists to perform the operation. |

## Remarks

**SearchByAddress** initiates a WS-Discovery [Probe](https://learn.microsoft.com/windows/desktop/WsdApi/probe-message) over HTTP in an attempt to identify a device at a known URL. The Probe is sent to the address specified by *pszAddress*. This call may result in one or more [Add](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-add) callbacks. If any **Add** callbacks are issued before the search completes, a [SearchComplete](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchcomplete) callback will be issued; otherwise, a [SearchFailed](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovidernotify-searchfailed) callback will be issued. The interval between initiating the search and receiving either of these notifications can be up to 30 seconds.

*pszTag* is an optional user provided string which will be fed back in either callback, allowing the caller to associate the callback with the original query.

For information about troubleshooting applications calling this method, see [Troubleshooting WSDAPI Applications](https://learn.microsoft.com/windows/desktop/WsdApi/troubleshooting-wsdapi-applications).

## See also

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)