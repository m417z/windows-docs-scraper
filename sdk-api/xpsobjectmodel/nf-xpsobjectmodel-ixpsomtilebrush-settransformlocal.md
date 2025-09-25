# IXpsOMTileBrush::SetTransformLocal

## Description

Sets the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface pointer to a local, unshared matrix transform.

## Parameters

### `transform` [in]

A pointer to the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface to be set as the local, unshared matrix transform. If a local transform has been set, a **NULL** pointer will release it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *transform* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

The transform determines how the output area is transformed before the brush image is rendered in the path, stroke, or glyph that is using the tile brush.

After you call **SetTransformLocal**, the transform lookup key is released and [GetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlookup) returns a **NULL** pointer in the *key* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *transform* by [GetTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransform) | Object that is returned in *transform* by [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlocal) | String that is returned in *key* by [GetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-gettransformlookup) |
| --- | --- | --- | --- |
| **SetTransformLocal** (this method) | The transform that is set by **SetTransformLocal**. | The transform that is set by **SetTransformLocal**. | **NULL** pointer. |
| [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlookup) | The transform which is retrieved, using a lookup key that matches the key that is set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlookup), from the resource directory. | **NULL** pointer. | The lookup key that is set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlookup). |
| Neither **SetTransformLocal** nor [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomtilebrush-settransformlookup) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

## See also

[IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform)

[IXpsOMTileBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomtilebrush)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))