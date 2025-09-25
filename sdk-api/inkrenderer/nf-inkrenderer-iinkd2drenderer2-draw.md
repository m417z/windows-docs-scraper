## Description

Renders the ink stroke to the designated Direct2D device context of the app.

## Parameters

### `pD2D1DeviceContext` [in]

Pointer to the designated Direct2D device context of the app.

### `pInkStrokeIterable` [in]

Pointer to the collection of ink strokes to render.

### `highContrastAdjustment`

One of the values from the [INK_HIGH_CONTRAST_ADJUSTMENT enum](https://learn.microsoft.com/windows/win32/api/inkrenderer/ne-inkrenderer-ink_high_contrast_adjustment).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)
[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)
[Ink renderer interfaces](https://learn.microsoft.com/windows/win32/input_ink/ink-renderer-interfaces)
[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)