# IInkRenderer::GetObjectTransform

## Description

Gets the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object that represents the object transform that was used to render ink.

## Parameters

### `ObjectTransform` [in]

The [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object that represents the geometric transformation - rotation, scaling, shear, and reflection - values to use to transform the stroke coordinates within the ink space.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

Any translations applied to this transform should be in ink space units (1 unit = .01mm).

## See also

[GetViewTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getviewtransform)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[SetObjectTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-setobjecttransform)

[SetViewTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-setviewtransform)