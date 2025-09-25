# IInkRenderer::PixelToInkSpace

## Description

Converts a location in pixel space coordinates to be a location in ink space coordinates.

## Parameters

### `hDC` [in]

The handle of the device context for the containing control or form.

### `x` [in, out]

The x coordinate of the point to convert into an ink location.

### `y` [in, out]

The y coordinate of the point to convert into an ink location.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

**PixelToInkSpace** converts from pixel to ink space (1 HIMETRIC unit = .01mm), applies the inverse of the view transform, and then applies the object transform.

## See also

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[InkSpaceToPixel Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixel)

[InkSpaceToPixelFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-inkspacetopixelfrompoints)

[PixelToInkSpaceFromPoints Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-pixeltoinkspacefrompoints)