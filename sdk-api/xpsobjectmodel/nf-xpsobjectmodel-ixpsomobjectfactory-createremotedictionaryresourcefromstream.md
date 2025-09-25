# IXpsOMObjectFactory::CreateRemoteDictionaryResourceFromStream

## Description

Loads the remote resource dictionary markup into an unrooted [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface.

## Parameters

### `dictionaryMarkupStream` [in]

The **IStream** interface that contains the remote resource dictionary markup.

### `dictionaryPartUri` [in]

The [IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi) interface that contains the part name to be assigned to this resource.

### `resources` [in]

The [IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources) interface for the part resources of the dictionary resource objects that have streams.

### `dictionaryResource` [out, retval]

A pointer to the new [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *dictionaryMarkupStream*, *dictionaryPartUri*, *resources*, or *dictionaryResource* is **NULL**. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *resources* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMObjectFactory](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomobjectfactory)

[IXpsOMPartResources](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompartresources)

[IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))