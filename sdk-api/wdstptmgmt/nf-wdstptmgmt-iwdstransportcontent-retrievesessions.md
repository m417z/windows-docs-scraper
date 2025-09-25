# IWdsTransportContent::RetrieveSessions

## Description

Retrieves a collection of active transport sessions associated with this content.

## Parameters

### `ppWdsTransportSessions` [out]

A pointer to a collection of objects of the [IWdsTransportSession](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportsession) interface that represent active sessions under this content.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportContent](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcontent)