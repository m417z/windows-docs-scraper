# IWdsTransportManager::GetWdsTransportServer

## Description

Creates an object of the [IWdsTransportServer](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportserver) interface that can be used to manage a WDS transport server. The method confirms that the system can reach a WDS transport server with the specified name.

## Parameters

### `bszServerName` [in]

The name of the WDS transport server to be represented by this object. This can be a NetBIOS name or a fully qualified DNS name. If the value is an empty string, the object represents the local computer.

### `ppWdsTransportServer` [out]

A pointer to the object of the [IWdsTransportServer](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportserver) interface.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportmanager)

[IWdsTransportServer](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportserver)