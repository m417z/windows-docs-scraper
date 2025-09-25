# IXpsOMGradientBrush::SetTransformLocal

## Description

Sets the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface pointer to a local, unshared matrix transform that is to be used for the brush.

## Parameters

### `transform` [in]

A pointer to the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface of the local, unshared matrix transform that is to be used for the brush. A **NULL** pointer releases any previously set interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **XPS_E_NO_CUSTOM_OBJECTS** | *transform* does not point to a recognized interface implementation. Custom implementation of XPS Document API interfaces is not supported. |

## Remarks

After you call **SetTransformLocal**, the transform lookup key is released and [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-gettransformlocal) returns a **NULL** pointer in the *transform* parameter. The table that follows explains the relationship between the local and lookup values of this property.

| Most recent method called | Object that is returned in *transform* by [GetTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-gettransform) | Object that is returned in *transform* by [GetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-gettransformlocal) | Object that is returned in *key* by [GetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-gettransformlookup) |
| --- | --- | --- | --- |
| **SetTransformLocal** (this method) | The local transform that is set by **SetTransformLocal**. | The local transform that is set by **SetTransformLocal**. | **NULL** pointer. |
| [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) | The shared transform retrieved, with a lookup key that matches the key that is set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup), from the resource directory. | **NULL** pointer. | The lookup key that is set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup). |
| Neither **SetTransformLocal** nor [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) has been called yet. | **NULL** pointer. | **NULL** pointer. | **NULL** pointer. |

 The transform passed in *transform* determines how the gradient is transformed. The visible part of the gradient that is ultimately rendered in the image is determined by the path, stroke, or glyph that is using the gradient brush.

## See also

[IXpsOMGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientbrush)

[IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))