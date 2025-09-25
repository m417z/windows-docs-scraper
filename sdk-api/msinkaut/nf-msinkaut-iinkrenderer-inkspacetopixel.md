# IInkRenderer::InkSpaceToPixel

## Description

Converts a location in ink space coordinates to a location in pixel space using a handle for the conversion.

## Parameters

### `hdcDisplay` [in]

The handle of the device context.

### `x` [in, out]

The X-coordinate of the point to convert into a pixel location.

### `y` [in, out]

The Y-coordinate of the point to convert into a pixel location.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_FAIL** | Coordinates overflowed during operation. |

## Remarks

[InkSpaceToPixelFromPoints](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixelfrompoints) applies the object transform, applies the view transform of the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object, and then converts from inkspace to pixel units (1 ink unit = .01mm).

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[InkSpaceToPixelFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixelfrompoints)

[PixelToInkSpace Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspace)

[PixelToInkSpaceFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspacefrompoints)