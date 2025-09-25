# _DXGKARG_SETPOINTERPOSITION structure

## Description

The DXGKARG_SETPOINTERPOSITION structure describes where and how to display the mouse pointer.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the mouse pointer is located on.

### `X` [in]

The column, in pixels, that the mouse pointer is located on from the top left.

### `Y` [in]

The row, in pixels, that the mouse pointer is located on from the top left.

### `Flags` [in]

A [DXGK_SETPOINTERPOSITIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setpointerpositionflags) structure that identifies, in bit-field flags, information about the mouse pointer.

## See also

[DXGK_SETPOINTERPOSITIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setpointerpositionflags)

[DxgkDdiSetPointerPosition](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointerposition)