# IInkRenderer::ScaleTransform

## Description

Scales the [view transform](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getviewtransform) in the X and Y dimension.

## Parameters

### `HorizontalMultiplier` [in]

The factor to scale the X dimension in the view transform.

### `VerticalMultiplier` [in]

The factor to scale the Y dimension in the view transform.

### `ApplyOnPenWidth` [in, optional]

Optional. **VARIANT_TRUE** to apply the scale factors to the pen width; otherwise, **VARIANT_FALSE**. The default is **VARIANT_TRUE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)