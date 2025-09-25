# IWbemEventSink::IsActive

## Description

The
**IWbemEventSink::IsActive** method is used by the provider to determine if there is interest in the events that the sink is filtering. In the case of a restricted sink, these events are defined by the queries passed to
[GetRestrictedSink](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemeventsink-getrestrictedsink). In the case where it is not a restricted sink, these events are defined by the queries in the event provider's registration. In the latter, the sink is always active.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.