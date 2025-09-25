# IWdsTransportSession::RetrieveClients

## Description

Retrieves a collection of WDS clients joined to the transport session.

## Parameters

### `ppWdsTransportClients` [out]

A collection of objects of the [IWdsTransportClient](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportclient) interface joined to the transport session.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportClient](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportclient)

[IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection)

[IWdsTransportSession](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportsession)