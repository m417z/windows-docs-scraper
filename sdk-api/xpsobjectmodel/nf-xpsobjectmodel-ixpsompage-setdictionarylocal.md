# IXpsOMPage::SetDictionaryLocal

## Description

Sets the [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface pointer of the page's local dictionary resource.

## Parameters

### `resourceDictionary` [in]

The [IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary) interface pointer to be set for the page. A **NULL** pointer releases any previously assigned local dictionary.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *resourceDictionary* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

After you call **SetDictionaryLocal**, the remote dictionary resource is released and [GetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionaryresource) returns a **NULL** pointer in the *remoteDictionaryResource* parameter. The table that follows explains the relationship between the local and remote values of this property.

| Most recent method called | Object that is returned in *resourceDictionary* by [GetDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionary) | Object that is returned in *resourceDictionary* by [GetDictionaryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionarylocal) | Object that is returned in *remoteDictionaryResource* by [GetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-getdictionaryresource) |
| --- | --- | --- | --- |
| **SetDictionaryLocal** (this method) | The local dictionary resource that is set by **SetDictionaryLocal**. | The local dictionary resource that is set by **SetDictionaryLocal**. | **NULL** pointer. |
| [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) | The shared dictionary in the dictionary resource that is set by [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource). | **NULL** pointer. | The remote dictionary resource that is set by [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource). |
| Neither **SetDictionaryLocal** nor [SetDictionaryResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompage-setdictionaryresource) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMPage](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompage)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))