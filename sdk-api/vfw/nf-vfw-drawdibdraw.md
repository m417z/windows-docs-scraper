# DrawDibDraw function

## Description

The **DrawDibDraw** function draws a DIB to the screen.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `hdc`

Handle to the DC.

### `xDst`

The x-coordinate, in **MM_TEXT** client coordinates, of the upper left corner of the destination rectangle.

### `yDst`

The y-coordinate, in **MM_TEXT** client coordinates, of the upper left corner of the destination rectangle.

### `dxDst`

Width, in **MM_TEXT** client coordinates, of the destination rectangle. If *dxDst* is −1, the width of the bitmap is used.

### `dyDst`

Height, in **MM_TEXT** client coordinates, of the destination rectangle. If *dyDst* is −1, the height of the bitmap is used.

### `lpbi`

Pointer to the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure containing the image format. The color table for the DIB within **BITMAPINFOHEADER** follows the format and the **biHeight** member must be a positive value; **DrawDibDraw** will not draw inverted DIBs.

### `lpBits`

Pointer to the buffer that contains the bitmap bits.

### `xSrc`

The x-coordinate, in pixels, of the upper left corner of the source rectangle. The coordinates (0,0) represent the upper left corner of the bitmap.

### `ySrc`

The y-coordinate, in pixels, of the upper left corner of the source rectangle. The coordinates (0,0) represent the upper left corner of the bitmap.

### `dxSrc`

Width, in pixels, of the source rectangle.

### `dySrc`

Height, in pixels, of the source rectangle.

### `wFlags`

Applicable flags for drawing. The following values are defined.

| Value | Meaning |
| --- | --- |
| **DDF_BACKGROUNDPAL** | Realizes the palette used for drawing in the background, leaving the actual palette used for display unchanged. This value is valid only if **DDF_SAME_HDC** is not set. |
| **DDF_DONTDRAW** | Current image is decompressed but not drawn. This flag supersedes the **DDF_PREROLL** flag. |
| **DDF_FULLSCREEN** | Not supported. |
| **DDF_HALFTONE** | Always dithers the DIB to a standard palette regardless of the palette of the DIB. If your application uses the [DrawDibBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibbegin) function, set this value in **DrawDibBegin** rather than in **DrawDibDraw**. |
| **DDF_HURRYUP** | Data does not have to be drawn (that is, it can be dropped) and **DDF_UPDATE** will not be used to recall this information. DrawDib checks this value only if it is required to build the next frame; otherwise, the value is ignored.This value is usually used to synchronize video and audio. When synchronizing data, applications should send the image with this value in case the driver needs to buffer the frame to decompress subsequent frames. |
| **DDF_NOTKEYFRAME** | DIB data is not a key frame. |
| **DDF_SAME_HDC** | Use the current DC handle and the palette currently associated with the DC. |
| **DDF_SAME_DRAW** | Use the current drawing parameters for **DrawDibDraw**. Use this value only if *lpbi*, *dxDst*, *dyDst*, *dxSrc*, and *dySrc* have not changed since using **DrawDibDraw** or [DrawDibBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibbegin). **DrawDibDraw** typically checks the parameters, and if they have changed, **DrawDibBegin** prepares the DrawDib DC for drawing. This flag supersedes the **DDF_SAME_DIB** and **DDF_SAME_SIZE** flags. |
| **DDF_UPDATE** | Last buffered bitmap is to be redrawn. If drawing fails with this value, a buffered image is not available and a new image needs to be specified before the display can be updated. |

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

**DDF_DONTDRAW** causes **DrawDibDraw** to decompress but not display an image. A subsequent call to **DrawDibDraw** specifying **DDF_UPDATE** displays the image.

If the DrawDib DC does not have an off-screen buffer specified, specifying **DDF_DONTDRAW** causes the frame to be drawn to the screen immediately. Subsequent calls to **DrawDibDraw** specifying **DDF_UPDATE** fail.

Although they are set at different times, **DDF_UPDATE** and **DDF_DONTDRAW** can be used together to create composite images off-screen. When the off-screen image is complete, you can display the image by calling **DrawDibDraw**.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)