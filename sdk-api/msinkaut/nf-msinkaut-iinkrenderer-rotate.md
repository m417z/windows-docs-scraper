# IInkRenderer::Rotate

## Description

Applies a rotation to a [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)'s view transform.

## Parameters

### `Degrees` [in]

The degrees by which to rotate clockwise.

### `x` [in, optional]

Optional. The x-coordinate of the point in ink space coordinates around which to rotate. The default is zero.

### `y` [in, optional]

Optional. The y-coordinate of the point in ink space coordinates around which to rotate. The default is zero.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

If no point is specified, the rotation is centered around the origin.

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)