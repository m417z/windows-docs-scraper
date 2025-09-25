# IInkStrokes::Transform

## Description

Applies a linear transformation to an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object or an [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection, which can represent scaling, rotation, translation, and combinations of transformations.

## Parameters

### `Transform` [in]

The transform to use on the stroke or strokes. (This is an [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object, which correlates to the [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure). The transformation applies to both the points and pen width (if *ApplyOnPenWidth* is **VARIANT_TRUE**).

### `ApplyOnPenWidth` [in, optional]

Optional. **VARIANT_TRUE** to apply the transform to the width of the ink in the [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) of the strokes; otherwise, **VARIANT_FALSE**. The default is **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkStrokes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkstrokes)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))