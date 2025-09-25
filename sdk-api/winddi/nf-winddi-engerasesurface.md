# EngEraseSurface function

## Description

The **EngEraseSurface** function calls GDI to erase the surface; a given rectangle on the surface will be filled with the given color.

## Parameters

### `pso`

Pointer to the surface to erase.

### `prcl`

Pointer to a [RECTL](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rectl) structure that defines which pixels to erase on the surface. This rectangle is exclusive of the bottom and right edges.

### `iColor` [in]

Specifies a color index. This is an index to the value that will be written into each pixel.

## Return value

The return value is **TRUE** if the function is successful. Otherwise, it is **FALSE**, and an error code is reported.