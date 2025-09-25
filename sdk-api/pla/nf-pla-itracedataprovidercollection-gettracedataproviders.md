# ITraceDataProviderCollection::GetTraceDataProviders

## Description

Populates the collection with registered trace providers.

## Parameters

### `server` [in]

The computer whose registered trace providers you want to enumerate. You can specify a computer name, a fully qualified domain name, or an IP address (IPv4 or IPv6 format). If **NULL**, PLA enumerates the providers on the local computer.

## Return value

Returns S_OK if successful.

## See also

[ITraceDataProviderCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovidercollection)

[ITraceDataProviderCollection::GetTraceDataProvidersByProcess](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovidercollection-gettracedataprovidersbyprocess)