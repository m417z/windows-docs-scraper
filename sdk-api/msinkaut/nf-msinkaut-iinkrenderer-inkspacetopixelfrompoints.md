# IInkRenderer::InkSpaceToPixelFromPoints

## Description

Converts an array of points in ink space coordinates to an array of points in pixel space.

## Parameters

### `hDC` [in]

The handle of the device context on which to draw.

### `Points` [in, out]

The array of points in ink space coordinates to convert into pixel locations. This should be an array of 32-bit integer values, passed within a VARIANT.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

**InkSpaceToPixelFromPoints** applies the object transform, applies the view transform of the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object, and then converts from inkspace to pixel units (1 ink unit = .01mm).

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[InkSpaceToPixel Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixel)

[PixelToInkSpace Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspace)

[PixelToInkSpaceFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspacefrompoints)