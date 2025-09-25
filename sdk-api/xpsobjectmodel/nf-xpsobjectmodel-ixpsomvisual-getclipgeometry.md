# IXpsOMVisual::GetClipGeometry

## Description

Gets a pointer to the [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface that contains the resolved geometry of the visual's clipping region.

## Parameters

### `clipGeometry` [out, retval]

A pointer to the [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface that contains the resolved geometry of the visual's clipping region. If the clip geometry has not been set, a **NULL** pointer is returned.

The value that is returned in this parameter depends on which method has most recently been called to set the geometry.

| Most recent method called | Object that is returned in *clipGeometry* |
| --- | --- |
| [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) | The local clip geometry that is set by [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal). |
| [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) | The shared clip geometry that gets retrieved, with a lookup key that matches the key that is set by [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup), from the resource directory. |
| Neither [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) nor [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *clipGeometry* is **NULL**. |
| **XPS_E_LOOKUP_INVALID_TYPE** | The lookup key name set by [SetStrokeBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlookup) references an object that is not a brush. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the lookup value. |

## See also

[IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))