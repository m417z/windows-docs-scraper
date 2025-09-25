# IWSDiscoveryProvider::GetXMLContext

## Description

Gets the XML context associated with this provider.

## Parameters

### `ppContext` [out]

Pointer to a pointer variable containing the XML context.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *ppContext* is **NULL**. |
| **E_ABORT** | The discovery provider has not been created. Call [WSDCreateDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-wsdcreatediscoveryprovider) to create a provider. |

## Remarks

Returns an optional context for the XML state of the transaction. If the service layer is used then this should be the context the XML namespaces and types were registered with.

**Note** [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) must be called before any other [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) method is used.

## See also

[IWSDXMLContext](https://learn.microsoft.com/windows/desktop/api/wsdxml/nn-wsdxml-iwsdxmlcontext)

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)