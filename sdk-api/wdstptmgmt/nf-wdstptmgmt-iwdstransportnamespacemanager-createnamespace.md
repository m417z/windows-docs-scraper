# IWdsTransportNamespaceManager::CreateNamespace

## Description

Creates an object of an [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface that can be registered on the current WDS transport server.

## Parameters

### `NamespaceType` [in]

The type of the new namespace object. This can be one of the namespace types listed by the [WDSTRANSPORT_NAMESPACE_TYPE](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_namespace_type) enumeration.

### `bszNamespaceName` [in]

The name of the new namespace object. If an application attempts to register this namespace with a WDS transport server, WDS confirms that the name is unique.

### `bszContentProvider` [in]

The name of the content provider to be associated with the new namespace object.

### `bszConfiguration` [in]

The configuration information used by the content provider. The format of this information is defined by the content provider. The value can be an empty string if no parameter is required.

### `ppWdsTransportNamespace` [out]

A pointer to the object of an [IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace) interface created by this method.

## Return value

Standard HRESULT error values are used: S_OK for success; others for failure.

## See also

[IWdsTransportNamespace](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespace)

[IWdsTransportNamespaceManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportnamespacemanager)

[WDSTRANSPORT_NAMESPACE_TYPE](https://learn.microsoft.com/windows/win32/api/wdstptmgmt/ne-wdstptmgmt-wdstransport_namespace_type)