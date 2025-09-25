# INK_HIGH_CONTRAST_ADJUSTMENT enum

## Description

Specifies how the [IInkD2DRenderer2](https://learn.microsoft.com/windows/win32/api/inkrenderer/nn-inkrenderer-iinkd2drenderer2) object draws ink (standard and modified) when system is in a contrast theme mode.

## Constants

### `USE_SYSTEM_COLORS_WHEN_NECESSARY`

For standard strokes, use selected color if contrast is sufficient against the background. Otherwise, use system color.

For highlighter strokes, use selected color if contrast is sufficient against the background. Otherwise, use system color.

### `USE_SYSTEM_COLORS`

For standard strokes, use system color.

For highlighter strokes, use system highlighter color.

### `USE_ORIGINAL_COLORS`

For standard strokes, use the selected color.

For highlighter strokes, use the selected color.

## Remarks

## See also

[Complex ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/ComplexInk)
[Simple ink sample](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/SimpleInk)
[Ink renderer interfaces](https://learn.microsoft.com/windows/win32/input_ink/ink-renderer-interfaces)
[Pen and stylus interactions](https://learn.microsoft.com/windows/uwp/input-and-devices/pen-and-stylus-interactions)