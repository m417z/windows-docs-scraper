# IXpsOMVisual::SetClipGeometryLookup

## Description

Sets the lookup key name of a shared clip geometry in a resource dictionary.

## Parameters

### `key` [in]

The lookup key name of the clip geometry in the dictionary. A **NULL** pointer clears the previously assigned key name.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

After you call **SetClipGeometryLookup**, the local clip geometry is released and [GetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylocal) returns a **NULL** pointer in the *clipGeometry* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *clipGeometry* by [GetClipGeometry](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometry) | Object that is returned in *clipGeometry* by [GetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylocal) | String that is returned in *key* by [GetClipGeometryLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-getclipgeometrylookup) |
| --- | --- | --- | --- |
| [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) | The local clip geometry that is set by [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal). | The local clip geometry that is set by [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal). | **NULL** pointer. |
| **SetClipGeometryLookup** (this method) | The shared clip geometry that gets retrieved, with a lookup key that matches the key that is set by **SetClipGeometryLookup**, from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetClipGeometryLookup**. |
| Neither **SetClipGeometryLookup** nor [SetClipGeometryLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomvisual-setclipgeometrylocal) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMVisual](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomvisual)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))