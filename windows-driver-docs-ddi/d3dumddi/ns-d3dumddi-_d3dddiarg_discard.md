# _D3DDDIARG_DISCARD structure

## Description

Defines video display memory that can be discarded because the contents are no longer needed.

## Members

### `hResource`

A handle to the resource in which subresources are to be discarded.

### `FirstSubResource`

The index of the first subresource to be discarded.

### `NumSubResources`

The number of subresources to be discarded.

### `pRects`

An array of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structures for the rectangles in the resource view to discard. If **NULL**, the [Discard](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_discard) function discards the entire surface.

### `NumRects`

The number of rectangles in the array that the **pRects** member specifies.

## See also

[Discard](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_discard)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)