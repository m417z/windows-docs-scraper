# ITraceDataProviderCollection::GetTraceDataProvidersByProcess

## Description

Populates the collection with the list of providers that have been registered by the specified process.

## Parameters

### `Server` [in]

The computer whose registered trace providers you want to enumerate. You can specify a computer name, a fully qualified domain name, or an IP address (IPv4 or IPv6 format). If **NULL**, PLA enumerates the providers on the local computer.

### `Pid` [in]

The process identifier of the process that registered the providers.

## Return value

Returns S_OK if successful.

## See also

[ITraceDataProviderCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovidercollection)

[ITraceDataProviderCollection::GetTraceDataProviders](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovidercollection-gettracedataproviders)