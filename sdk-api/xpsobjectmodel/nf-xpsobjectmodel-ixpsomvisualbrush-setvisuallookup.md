# IXpsOMVisualBrush::SetVisualLookup

## Description

Sets the lookup key name of the shared visual, which is stored in a resource dictionary, to be used as the source for the brush.

## Parameters

### `lookup` [in]

The lookup key name of the shared visual to be used as the source for the brush. If a lookup key has already been set, a **NULL** pointer will clear it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

After you call **SetVisualLookup**, the local visual is released and [GetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallocal) returns a **NULL** pointer in the *visual* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *visual* by [GetVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisual) | Object that is returned in *visual* by [GetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallocal) | String that is returned in *lookup* by [GetVisualLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-getvisuallookup) |
| --- | --- | --- | --- |
| [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal) | The visual that is set by [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal). | The visual that is set by [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal). | **NULL** pointer. |
| **SetVisualLookup** (this method). | The visual that is retrieved, with a lookup key that matches the key set by **SetVisualLookup**, from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetVisualLookup**. |
| Neither [SetVisualLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisualbrush-setvisuallocal) nor **SetVisualLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisualBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisualbrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))