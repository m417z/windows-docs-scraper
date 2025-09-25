# IXpsOMGradientBrush::GetTransform

## Description

Gets a pointer to the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface that contains the resolved matrix transform for the brush.

## Parameters

### `transform` [out, retval]

A pointer to the [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface that contains the resolved matrix transform for the brush. If the transform has not been set, a **NULL** pointer is returned.

The value that is returned in this parameter depends on which method has been most recently called to set the transform.

| Most recent method called | Object that is returned in *transform* |
| --- | --- |
| [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlocal) | The local transform that is set by [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlocal). |
| [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) | The shared transform that is retrieved, with a lookup key that matches the key set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup), from the resource directory. |
| Neither [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlocal) nor [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *transform* is **NULL**. |
| **XPS_E_LOOKUP_INVALID_TYPE** | The lookup key name set by [SetStrokeBrushLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsompath-setstrokebrushlookup) references an object that is not a brush. |
| **XPS_E_LOOKUP_NOT_FOUND** | No object could be found with a key name that matched the lookup value.<br><br>No object could be found with a key name that matched the value passed in *lookup*. |

## Remarks

 The transform determines how the gradient is transformed. The visible part of the gradient that is ultimately rendered in the image is determined by the path, stroke, or glyph that is using the gradient brush.

## See also

[IXpsOMGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientbrush)

[IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))