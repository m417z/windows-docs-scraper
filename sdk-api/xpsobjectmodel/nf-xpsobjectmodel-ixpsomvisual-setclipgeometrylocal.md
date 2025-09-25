# IXpsOMVisual::SetClipGeometryLocal

## Description

Sets the local, unshared clipping region for the visual.

## Parameters

### `clipGeometry` [in]

A pointer to the [IXpsOMGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgeometry) interface to be set as the local, unshared clipping region for the visual. A **NULL** pointer releases the previously assigned geometry interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *clipGeometry* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

After you call **SetClipGeometryLocal**, the clip geometry lookup key is released and [GetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylookup) returns a **NULL** pointer in the *key* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *clipGeometry* by [GetClipGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometry) | Object that is returned in *clipGeometry* by [GetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylocal) | String that is returned in *key* by [GetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylookup) |
| --- | --- | --- | --- |
| **SetClipGeometryLocal** (this method) | The local clip geometry that is set by **SetClipGeometryLocal**. | The local clip geometry that is set by **SetClipGeometryLocal**. | **NULL** pointer. |
| [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) | The shared clip geometry that gets retrieved, with a lookup key that matches the key that is set by [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup), from the resource directory. | **NULL** pointer. | The lookup key that is set by [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup). |
| Neither [SetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylookup) nor **SetClipGeometryLocal** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))