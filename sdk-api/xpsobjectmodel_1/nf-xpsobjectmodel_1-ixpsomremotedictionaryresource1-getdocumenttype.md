# IXpsOMRemoteDictionaryResource1::GetDocumentType

## Description

Gets the [XPS_DOCUMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/ne-xpsobjectmodel_1-xps_document_type) of the resource.

## Parameters

### `documentType` [out, retval]

The [XPS_DOCUMENT_TYPE](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/ne-xpsobjectmodel_1-xps_document_type) document type of the resource.

Returns [XPS_DOCUMENT_TYPE_UNSPECIFIED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel_1/ne-xpsobjectmodel_1-xps_document_type) unless the [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface was created by loading a previously serialized remote dictionary.

## Return value

The method returns an **HRESULT**.

For information about XPS document API return values, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

## See also

[IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource)

[IXpsOMRemoteDictionaryResource1](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_1/nn-xpsobjectmodel_1-ixpsomremotedictionaryresource1)