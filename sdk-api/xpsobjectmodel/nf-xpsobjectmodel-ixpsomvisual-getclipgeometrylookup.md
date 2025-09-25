# IXpsOMVisual::GetClipGeometryLookup

## Description

Gets the lookup key for the [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface in a resource dictionary that contains the visual's clipping region.

## Parameters

### `key` [out, retval]

The lookup key for the [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface in a resource dictionary that contains the visual's clipping region. If a lookup key for the clip geometry has not been set, or if a local clip geometry has been set, a **NULL** pointer is returned.

| Most recent method called | Lookup key string that is returned in *key* |
| --- | --- |
| [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) | **NULL** pointer. |
| [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) | The lookup key that is set by [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup). |
| Neither [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) nor [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *key* is **NULL**. |

## Remarks

This method allocates the memory that is used by the string returned in *key*. If *key* is not **NULL**, use the SignatureDefinitions function to free the memory.

## See also

[IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry)

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))