# _D3DKMT_PRESENT_RGNS structure

## Description

Specifies dirty and move regions in a present operation.

## Members

### `DirtyRectCount`

The number of dirty rectangles.

### `pDirtyRects`

A pointer to an array of dirty rectangles ([RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)s).

### `MoveRectCount`

The number of move rectangles.

### `pMoveRects`

A pointer to an array of move rectangles ([RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)s).

## See also

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)