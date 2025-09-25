# IInkRenderer::PixelToInkSpaceFromPoints

## Description

Converts an array of locations in pixel space coordinates to an array of locations in ink space coordinates.

## Parameters

### `hDC` [in]

The handle of the device context for the containing control or form.

### `Points` [in, out]

The Variant array of points, as alternating Long x and y values of the form x0, y0, x1, y1, x2, y2, and so on, to convert from a pixel location to ink space coordinates.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

`PixelToInkSpaceFromPoints` converts from pixel to ink space (1 ink unit = .01mm), applies the inverse of the view transform, and then applies the inverse of the object transform.

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[InkSpaceToPixel Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixel)

[InkSpaceToPixelFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixelfrompoints)

[PixelToInkSpace Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspace)