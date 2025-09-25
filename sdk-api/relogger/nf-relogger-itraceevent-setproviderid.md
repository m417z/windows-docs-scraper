# ITraceEvent::SetProviderId

## Description

The **SetProviderId** method sets the GUID for the provider which traced an event.

## Parameters

### `ProviderId` [in]

Type: **LPCGUID**

Unique identifier of the provider.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)