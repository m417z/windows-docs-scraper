# IWbemEventSink::GetRestrictedSink

## Description

The
**IWbemEventSink::GetRestrictedSink** method retrieves a restricted event sink. A restricted event sink is one which filters a subset of the events defined in the event provider's registration.

## Parameters

### `lNumQueries` [in]

Number of queries in array.

### `awszQueries` [in]

Array of event queries.

### `pCallback` [in]

Pointer to callback for event provider.

### `ppSink` [out]

Pointer to created
[IWbemEventSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemeventsink) object.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.