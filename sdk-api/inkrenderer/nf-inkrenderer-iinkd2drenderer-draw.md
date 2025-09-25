# IInkD2DRenderer::Draw

## Description

Renders the ink stroke to the designated Direct2D device context of the app.

## Parameters

### `pD2D1DeviceContext` [in]

Pointer to the designated Direct2D device context of the app.

### `pInkStrokeIterable` [in]

Pointer to the collection of ink strokes to render.

### `fHighContrast` [in]

True, if the high-contrast accessibility option, in Windows 10 and earlier, is currently selected (Settings -> Ease of Access -> High Contrast -> Use high contrast). Otherwise, false.

Listen for the [HighContrastChanged](https://learn.microsoft.com/uwp/api/windows.ui.viewmanagement.accessibilitysettings.highcontrastchanged) event to set this value appropriately.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)
[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)
[Ink renderer interfaces](https://learn.microsoft.com/windows/win32/input_ink/ink-renderer-interfaces)
[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)