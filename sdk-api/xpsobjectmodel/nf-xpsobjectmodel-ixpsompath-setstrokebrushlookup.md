# IXpsOMPath::SetStrokeBrushLookup

## Description

Sets the lookup key name of a shared brush to be used as the stroke brush.The shared brush is stored in a resource dictionary.

## Parameters

### `lookup` [in]

The lookup key name of a shared brush to be used as the stroke brush for the path.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *lookup* references an object that is not a brush. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *lookup*. |

## Remarks

After you call **SetStrokeBrushLookup**, the local stroke brush is released and [GetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getstrokebrushlocal) returns a **NULL** pointer in the *brush* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *brush* by [GetStrokeBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getstrokebrush) | Object that is returned in *brush* by [GetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getstrokebrushlocal) | String that is returned in *lookup* by [GetStrokeBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-getstrokebrushlookup) |
| --- | --- | --- | --- |
| [SetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlocal) | The local brush that is set by [SetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlocal). | The local brush that is set by [SetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlocal). | **NULL** pointer. |
| **SetStrokeBrushLookup**(this method) | The shared brush retrieved, with a lookup key that matches the key that is set by **SetStrokeBrushLookup**, from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetStrokeBrushLookup**. |
| Neither [SetStrokeBrushLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlocal) nor **SetStrokeBrushLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMPath](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompath)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))