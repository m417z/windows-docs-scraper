# IWbemEventProviderQuerySink::CancelQuery

## Description

Call the
**IWbemEventProviderQuerySink::CancelQuery** method whenever a logical event consumer cancels a relevant event query filter with Windows Management. The
**CancelQuery** method determines how an event provider responds to a relevant canceled event query filter. Whenever WMI retrieves a cancellation notice for an event query filter from a consumer, WMI calls
**CancelQuery** to echo the cancellation to the responsible event provider. The event provider can examine the identifier of the query to determine which query is being canceled. The provider then modifies which events are being sent out based on the cancellation.

## Parameters

### `dwId` [in]

Identifier of the query which was canceled. This identifier was originally delivered to the provider by the
[NewQuery](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventproviderquerysink-newquery) method of this interface.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

Whenever a consumer registers a new event query filter, Windows Management calls the
[IWbemEventProviderQuerySink::NewQuery](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventproviderquerysink-newquery) method with the query identifier. Later, when that query is unregistered, this method is called indicating which query is no longer outstanding.

Providers use this method to help optimize the generation of events internally.

## See also

[IWbemEventProviderQuerySink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemeventproviderquerysink)

[IWbemEventProviderQuerySink::NewQuery](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventproviderquerysink-newquery)