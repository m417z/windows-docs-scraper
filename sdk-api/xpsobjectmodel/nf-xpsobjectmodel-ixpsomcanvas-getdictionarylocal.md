# IXpsOMCanvas::GetDictionaryLocal

## Description

Gets a pointer to the [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface of the local, unshared dictionary.

## Parameters

### `resourceDictionary` [out, retval]

The [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface pointer to the local, unshared dictionary, if one has been set. If a local dictionary has not been set or if a remote dictionary resource has been set, a **NULL** pointer is returned.

| Most recent method called | Object returned in *resourceDictionary* |
| --- | --- |
| [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionarylocal) | The local dictionary that is set by [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionarylocal). |
| [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionaryresource) | **NULL** pointer. |
| Neither [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionarylocal) nor [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomcanvas-setdictionaryresource) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *resourceDictionary* is **NULL**. |

## Remarks

When this method loads and parses the resource into the XPS OM, it might return an error that applies to another resource. This can occur because all of the relationships are parsed when the resource is loaded.

For more information about other return values that might be returned by this method, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

## See also

[IXpsOMCanvas](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomcanvas)

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))