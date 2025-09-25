# DrawAnimatedRects function

## Description

Animates the caption of a window to indicate the opening of an icon or the minimizing or maximizing of a window.

## Parameters

### `hwnd` [in]

A handle to the window whose caption should be animated on the screen. The animation will be clipped to the parent of this window.

### `idAni` [in]

The type of animation. This must be IDANI_CAPTION. With the IDANI_CAPTION animation type, the window caption will animate from the position specified by lprcFrom to the position specified by lprcTo. The effect is similar to minimizing or maximizing a window.

### `lprcFrom`

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure specifying the location and size of the icon or minimized window. Coordinates are relative to the clipping window *hwnd*.

### `lprcTo`

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure specifying the location and size of the restored window. Coordinates are relative to the clipping window *hwnd*.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)