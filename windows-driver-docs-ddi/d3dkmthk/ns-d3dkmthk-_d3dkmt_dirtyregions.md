# _D3DKMT_DIRTYREGIONS structure

## Description

The D3DKMT_DIRTYREGIONS structure describes active rectangles (dirty regions) of a surface.

## Members

### `NumRects` [in]

The number of dirty regions in the array that the **Rects** member specifies.

### `Rects` [in]

An array of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures that specifies the dirty regions of a surface.

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)