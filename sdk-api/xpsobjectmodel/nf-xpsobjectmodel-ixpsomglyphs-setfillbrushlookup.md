# IXpsOMGlyphs::SetFillBrushLookup

## Description

Sets the lookup key name of a shared fill brush.

## Parameters

### `key` [in]

A string variable that contains the key name of the fill brush that is stored in the resource dictionary and will be used as the shared fill brush. A **NULL** pointer clears any previously assigned key string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

After you call **SetFillBrushLookup**, the local fill brush is released and [GetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfillbrushlocal) returns a **NULL** pointer in the *fillBrush* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *fillBrush* by [GetFillBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfillbrush) | Object that is returned in *fillBrush* by [GetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfillbrushlocal) | String that is returned in *key* by [GetFillBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfillbrushlookup) |
| --- | --- | --- | --- |
| [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-setfillbrushlocal) | The local brush that is set by [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-setfillbrushlocal). | The local brush that is set by [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-setfillbrushlocal). | **NULL** pointer. |
| **SetFillBrushLookup** (this method) | The shared brush that gets retrieved, with a lookup key matching the key that is set by **SetFillBrushLookup**, from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetFillBrushLookup**. |
| Neither [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-setfillbrushlocal) nor **SetFillBrushLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))