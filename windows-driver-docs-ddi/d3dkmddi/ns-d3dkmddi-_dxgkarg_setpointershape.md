# _DXGKARG_SETPOINTERSHAPE structure

## Description

The DXGKARG_SETPOINTERSHAPE structure describes the appearance of the mouse pointer and the location that it should be displayed in.

## Members

### `Flags` [in]

A [DXGK_POINTERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pointerflags) structure that identifies, in bit-field flags, how to display the mouse pointer.

### `Width` [in]

The width of the mouse pointer, in pixels.

### `Height` [in]

The height of the mouse pointer, in scan lines.

### `Pitch` [in]

The width of the mouse pointer, in bytes.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the mouse pointer is located in.

### `pPixels` [in]

A pointer to the start of the following bitmap depending on the bit-field flag that is set in the **Flags** member:

|Bit-field flag|Bitmap|
|--- |--- |
|Monochrome|For monochrome mouse pointers:<br>A monochrome bitmap whose size is specified by Width and Height in a 1 bits per pixel (bpp) DIB format AND mask that is followed by another 1 bpp DIB format XOR mask of the same size.|
|Color|For color mouse pointers:<br>A color bitmap whose size is specified by Width and Height in a 32 bpp ARGB device independent bitmap (DIB) format.|
|MaskedColor|For masked color mouse pointers:<br>A 32-bpp ARGB format bitmap with the mask value in the alpha bits. The only allowed mask values are 0 and 0xFF. When the mask value is 0, the RGB value should replace the screen pixel. When the mask value is 0xFF, an XOR operation is performed on the RGB value and the screen pixel; the result should replace the screen pixel.|

### `XHot` [in]

The column, in pixels, that the mouse pointer is located on from the top left of the bitmap that **pPixels** points to.

### `YHot` [in]

The row, in pixels, that the mouse pointer is located on from the top left of the bitmap that **pPixels** points to.

## Remarks

The **XHot** and **YHot** members are used by display miniport drivers that are not associated with hardware, and these members can be ignored by drivers that control hardware.

## See also

[DXGK_POINTERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pointerflags)

[DxgkDdiSetPointerShape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setpointershape)