# IWdsTransportNamespaceManager::RetrieveNamespaces

## Description

Returns a collection of objects of the [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface that represent namespaces on the server that match specified criteria.

## Parameters

### `bszContentProvider` [in]

The name of the content provider for which namespaces are to be returned. If an empty string is specified, the method returns the namespaces for all content providers.

### `bszNamespaceName` [in]

The name of the namespace for which instances are to be returned. If an empty string is specified, the method returns all namespaces for the selected content providers.

### `bIncludeTombstones` [in]

A value of true specifies that the method should include in the results any namespaces that have been deregistered while still having active sessions on the server. This enables an application to register another namespace with the name.

### `ppWdsTransportNamespaces` [out]

A pointer to the object of an [IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection) interface. This represents a collection of objects of an [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface that match the specified criteria.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection)

[IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace)

[IWdsTransportNamespaceManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespacemanager)