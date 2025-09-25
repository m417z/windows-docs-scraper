# _DXGKARG_PRESENT_DISPLAYONLY structure

## Description

Indicates how a kernel mode display-only driver (KMDOD) is to perform a present operation.

## Members

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology on which to restrict displaying.

### `pSource`

The virtual start address of the source image.

### `BytesPerPixel`

The number of bytes per pixel in the source image.

### `Pitch`

The pitch, in bytes, of each line in the source image—that is, the distance, in bytes, to the start of the next line.

### `Flags`

A [D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_d3dkmt_present_display_only_flags) structure that identifies how to display the source image in the present operation.

### `NumMoves`

The number of screen-to-screen moves that are pointed to by the **pMoves** member.

### `pMoves`

A pointer to a list of [D3DKMT_MOVE_RECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmt_move_rect) screen-to-screen moves.

### `NumDirtyRects`

The number of dirty rectangles that are pointed to by the **pDirtyRect** member.

### `pDirtyRect`

A pointer to a list of [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) dirty rectangles.

### `pfnPresentDisplayOnlyProgress`

Reserved for system use. The operating system sets this member to **NULL**.

## See also

[D3DKMT_MOVE_RECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmt_move_rect)

[D3DKMT_PRESENT_DISPLAY_ONLY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_d3dkmt_present_display_only_flags)

[DxgkCbPresentDisplayOnlyProgress](https://learn.microsoft.com/windows-hardware/drivers/display/dxgkcbpresentdisplayonlyprogress)

[DxgkDdiPresentDisplayOnly](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_presentdisplayonly)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)