# IXpsOMPage::SetDictionaryResource

## Description

Sets the [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface pointer of the page's remote dictionary resource.

## Parameters

### `remoteDictionaryResource` [in]

The [IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource) interface pointer to be set for the page. A **NULL** value releases the previously assigned dictionary resource.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *remoteDictionaryResource* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

Setting this value will cause [GetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionarylocal) to return **NULL**.

| Most recent method called | Object that is returned in *resourceDictionary* by [GetDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionary) | Object that is returned in *resourceDictionary* by [GetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionarylocal) | Object that is returned in *remoteDictionaryResource* by [GetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionaryresource) |
| --- | --- | --- | --- |
| [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) | The local dictionary resource that is set by [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal). | The local dictionary resource that is set by [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal). | **NULL** pointer. |
| **SetDictionaryResource** (this method) | The shared dictionary in the dictionary resource that is set by **SetDictionaryResource**. | **NULL** pointer. | The remote dictionary resource that is set by **SetDictionaryResource**. |
| Neither [SetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionarylocal) nor **SetDictionaryResource** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[IXpsOMRemoteDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomremotedictionaryresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))