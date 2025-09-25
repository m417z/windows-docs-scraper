# IInkRenderer::GetViewTransform

## Description

Gets the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object that represents the view transform that is used to render ink.

## Parameters

### `ViewTransform` [in]

 The matrix that represents the geometric transformation - rotation, scaling, shear, and reflection - values to use to transform the stroke coordinates within the ink space. The transformation applies to both the points and pen width. View transformation occurs after object transformation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

Any translations applied to this transform should be in ink space units (1 unit = .01mm).

Adjusting the view transform is analogous to adjusting the zoom factor on the ink rendering.

View transformation occurs after object transformation.

## See also

[GetObjectTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getobjecttransform)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[SetObjectTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-setobjecttransform)

[SetViewTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-setviewtransform)