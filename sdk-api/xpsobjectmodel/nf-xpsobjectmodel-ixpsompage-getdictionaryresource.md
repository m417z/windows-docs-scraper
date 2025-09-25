# IXpsOMPage::GetDictionaryResource

## Description

Gets a pointer to the [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface of the shared dictionary resource that is used by this page.

## Parameters

### `remoteDictionaryResource` [out, retval]

A pointer to the [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface of the shared dictionary resource that is used by this page. If no **IXpsOMRemoteDictionaryResource** interface has been set or if a local dictionary has been set, a **NULL** pointer is returned.

| Most recent method called | Object that is returned in *remoteDictionaryResource* |
| --- | --- |
| [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) | **NULL** pointer. |
| [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) | The remote dictionary resource that is set by [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource). |
| Neither [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) nor [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *remoteDictionaryResource* is **NULL**. |

## Remarks

After loading and parsing the resource into the XPS OM, this method might return an error that applies to another resource. This occurs because all of the relationships are parsed when a resource is loaded.

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))