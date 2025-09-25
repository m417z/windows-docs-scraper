# IXpsOMTileBrush::SetTransformLookup

## Description

Sets the lookup key name of a shared matrix transform that will be used as the transform for this brush.The shared matrix transform that is referenced by the lookup key is stored in the resource dictionary.

## Parameters

### `key` [in]

A string variable that contains the lookup key name of a shared matrix transform in the resource dictionary. If a lookup key has already been set, a **NULL** pointer will clear it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_INVALID_RESOURCE_KEY** | According to the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification), the value of *lookup* is not a valid lookup key string. |
| **XPS_E_INVALID_LOOKUP_TYPE** | The lookup key name in *key* references an object that is not a geometry. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the value passed in *key*. |

## Remarks

The transform is applied before the brush image is rendered in the path, stroke, or glyph that is using the tile brush. The tile brush has only one transform, which can be local or remote.

After you call **SetTransformLookup**, the local transform is released and [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlocal) returns a **NULL** pointer in the *transform* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *transform* by [GetTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransform) | Object that is returned in *transform* by [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlocal) | String that is returned in *key* by [GetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlookup) |
| --- | --- | --- | --- |
| [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlocal) | The transform that is set by [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlocal). | The transform that is set by [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlocal). | **NULL** pointer. |
| **SetTransformLookup** (this method) | The transform which is retrieved—using a lookup key that matches the key that is set by **SetTransformLookup**— from the resource directory. | **NULL** pointer. | The lookup key that is set by **SetTransformLookup**. |
| Neither [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlocal) nor **SetTransformLookup** has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))