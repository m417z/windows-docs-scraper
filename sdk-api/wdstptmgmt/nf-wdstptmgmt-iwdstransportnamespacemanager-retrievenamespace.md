# IWdsTransportNamespaceManager::RetrieveNamespace

## Description

Retrieves, by name, an object of an [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface. The name should be registered with the namespace on the WDS transport server.

## Parameters

### `bszNamespaceName` [in]

The name of the namespace for which an object is being returned. The namespace should be registered with the WDS transport server.

### `ppWdsTransportNamespace` [out]

A pointer to the object of an [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface that matches the specified name.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace)

[IWdsTransportNamespaceManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespacemanager)