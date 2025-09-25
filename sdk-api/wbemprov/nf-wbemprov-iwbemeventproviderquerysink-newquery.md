# IWbemEventProviderQuerySink::NewQuery

## Description

Call the
**IWbemEventProviderQuerySink::NewQuery** method when a logical event consumer registers a relevant event query filter with Windows Management. The
**NewQuery** method determines how a provider responds to a new query registered by a client application. When WMI receives a new or modified event query from a consumer, WMI calls
**NewQuery** to echo the query to the event provider. The provider then generates the requested notification.

## Parameters

### `dwId` [in]

Windows Management-generated identifier for the query. The provider can track this so that during a later call to
[CancelQuery](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventproviderquerysink-cancelquery) so that the provider will know which query was canceled.

### `wszQueryLanguage` [in]

Language of the following query filter. For this version of WMI, it will always be "WQL".

### `wszQuery` [in]

Text of the event query filter, which was registered by a logical consumer. The event provider can examine the text of the query filter through the *wszQuery* parameter and the language of the query filter in the *wszQueryLanguage* parameter to discover which event notifications the consumer is requesting.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists return codes returned by
**NewQuery**. Additionally, a third-party event provider could return any valid WMI or COM return code which could be passed through
**NewQuery** as a return value.

## Remarks

If a consumer registers an event filter query with Windows Management and the query contains references to events provided by the current event provider, Windows Management can notify the event provider of the query.

If the provider implements the
[IWbemEventProviderQuerySink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventproviderquerysink) interface, Windows Management will provide a copy of the query text to the provider. The provider should parse the query, and determine if it can perform any internal optimization.

Windows Management does not expect a provider to alter its behavior in any way. Rather, this is an advisory call to assist the provider with internal optimization.

For example, if the provider is capable of providing many hundreds of events, but the required overhead for providing all of them is great, the provider can achieve substantial savings if it knows that most of these events are not required by the current set of event consumers. If the provider implements
[IWbemEventProviderQuerySink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventproviderquerysink), it will know about the current set of events requested by all consumers. It may be able to avoid setting up the mechanisms for delivering most of the event types that it supports until consumers actually begin requesting such events.

For each new consumer query filter, a separate call to this method with a unique dwId will be made. Be aware that Windows Management reserves the right to call
**NewQuery** more than one time for the same dwId value; for example, if there is a schema change elsewhere in the system. For this version of WMI, the query language is always "WQL".

The
**IWbemEventProviderQuerySink::NewQuery** method can be called before the
[IWbemEventProvider::ProvideEvents](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventprovider-provideevents) method.

## See also

[IWbemEventProviderQuerySink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventproviderquerysink)

[IWbemEventProviderQuerySink::CancelQuery](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventproviderquerysink-cancelquery)