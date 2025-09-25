# IXpsOMPath::SetFillBrushLookup

## Description

Sets the lookup key name of a shared brush in a resource dictionary, to be used as the fill brush.

## Parameters

### `lookup` [in]

The key name of the brush in a resource dictionary, to be used as the fill brush.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *lookup* references an object that is not a brush. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *lookup*. |

## Remarks

After you call **SetFillBrushLookup**, the local fill brush is released and [GetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getfillbrushlocal) returns a **NULL** pointer in the *brush* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *brush* by [GetFillBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getfillbrush) | Object that is returned in *brush* by [GetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getfillbrushlocal) | String that is returned in *lookup* by [GetFillBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getfillbrushlookup) |
| --- | --- | --- | --- |
| [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal) | The local brush that is set by [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal). | The local brush that is set by [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal). | **NULL** pointer. |
| **SetFillBrushLookup** (this method) | The shared brush retrieved, with a lookup key that matches the key that is set by **SetFillBrushLookup**, from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetFillBrushLookup**. |
| Neither [SetFillBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setfillbrushlocal) nor **SetFillBrushLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))