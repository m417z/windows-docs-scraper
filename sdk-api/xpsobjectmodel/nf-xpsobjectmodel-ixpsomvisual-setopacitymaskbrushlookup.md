# IXpsOMVisual::SetOpacityMaskBrushLookup

## Description

Sets the lookup key name of a shared opacity mask brush in a resource dictionary.

## Parameters

### `key` [in]

The lookup key name of the opacity mask brush in the dictionary. A **NULL** pointer clears the previously assigned key name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

After you call **SetOpacityMaskBrushLookup**, the local opacity mask brush is released and [GetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlocal) returns a **NULL** pointer in the *opacityMaskBrush* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *opacityMaskBrush* by [GetOpacityMaskBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrush) | Object that is returned in *opacityMaskBrush* by [GetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlocal) | String that is returned in *key* by [GetOpacityMaskBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getopacitymaskbrushlookup) |
| --- | --- | --- | --- |
| [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) | The local opacity mask brush that is set by [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal). | The local opacity mask brush that is set by [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal). | **NULL** pointer. |
| **SetOpacityMaskBrushLookup** (this method) | The shared opacity mask brush that gets retrieved—with a lookup key that matches the key that is set by **SetOpacityMaskBrushLookup**—from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetOpacityMaskBrushLookup**. |
| Neither [SetOpacityMaskBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setopacitymaskbrushlocal) nor **SetOpacityMaskBrushLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))