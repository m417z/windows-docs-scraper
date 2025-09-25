# IWdsTransportSetupManager::DeregisterContentProvider

## Description

Enables an application run on a client computer to deregister a content provider. This makes the provider no longer available for use by the WDS transport server.

## Parameters

### `bszName` [in]

The name of the content provider to be deregistered.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportSetupManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportsetupmanager)