# IXpsOMGradientBrush::GetTransformLookup

## Description

Gets the name of the lookup key of the shared matrix transform interface that is to be used for the brush.

The key name identifies a shared resource in a resource dictionary.

## Parameters

### `key` [out, retval]

The name of the lookup key of the shared matrix transform interface that is to be used for the brush. If the lookup key name has not been set or if the local matrix transform has been set, a **NULL** pointer is returned.

The value that is returned in this parameter depends on which method has been most recently called to set the lookup key or the transform.

| Most recent method called | String that is returned in *key* |
| --- | --- |
| [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlocal) | **NULL** pointer. |
| [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) | The key that is set by [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup). |
| Neither [SetTransformLocal](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlocal) nor [SetTransformLookup](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomgradientbrush-settransformlookup) has been called yet. | **NULL** pointer. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *key* is **NULL**. |

## Remarks

This method does not return an [IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform) interface pointer; to retrieve this pointer from the dictionary, call [IXpsOMDictionary::GetByKey](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomdictionary-getbykey).

 The transform determines how the gradient is transformed. The visible part of the gradient that is ultimately rendered in the image is determined by the path, stroke, or glyph that is using the gradient brush.

This method allocates the memory used by the string that is returned in *key*. If *key* is not **NULL**, use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory.

## See also

[IXpsOMDictionary](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomdictionary)

[IXpsOMGradientBrush](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomgradientbrush)

[IXpsOMMatrixTransform](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsommatrixtransform)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))